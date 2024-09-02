#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> v_forward;
vector<vector<P>> v_reverse;

vector<int> v_ftopo;

vector<bool> v_risvisited;
vector<int> v_csum;

int rcount = 0;

void topoForward(int start){
    queue<int> que;
    que.push(start);
    
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        if(v_ftopo.at(v) == 0){
            --v_ftopo.at(v);
            for(auto &np: v_forward.at(v)){
                int &next = np.first;
                int &dist = np.second;
                
                --v_ftopo.at(next);
                v_csum.at(next) = max(v_csum.at(next), v_csum.at(v) + dist);
                
                if(v_ftopo.at(next) == 0)
                    que.push(next);
            }
        }
    }
}

void topoReverse(int end){
    queue<int> que;
    que.push(end);
    
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        if(!v_risvisited.at(v)){
            v_risvisited.at(v) = true;
            for(auto &pp: v_reverse.at(v)){
                int &prev = pp.first;
                int &dist = pp.second;
                
                if(v_csum.at(v) == v_csum.at(prev) + dist){
                    ++rcount;
                    que.push(prev);
                }
            }
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    v_forward.assign(n+1, vector<P>());
    v_reverse.assign(n+1, vector<P>());
    
    v_ftopo.assign(n+1, 0);
    
    v_risvisited.assign(n+1, false);
    v_csum.assign(n+1, 0);
    
    for(int i=0; i<m; ++i){
        int s, d, t;
        cin >> s >> d >> t;
        
        v_forward.at(s).push_back(make_pair(d, t));
        v_reverse.at(d).push_back(make_pair(s, t));
        
        ++v_ftopo.at(d);
    }
    
    int i_source, i_dest;
    cin >> i_source >> i_dest;
    
    topoForward(i_source);
    topoReverse(i_dest);
    
    cout << v_csum.at(i_dest) << "\n" << rcount << "\n";
    
    return 0;
}
