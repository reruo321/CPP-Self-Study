// Not Finished. Wrong solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> v_forward;
vector<vector<P>> v_reverse;

vector<int> f_topo;
vector<int> r_topo;
vector<bool> r_isvisited;

queue<int> que;

int rcount = 0;

void f_topoFunc(int start){
    que.push(start);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        for(auto &np: v_forward.at(v)){
            int &next = np.first;
            int &dist = np.second;
            
            --f_topo.at(next);
            r_topo.at(next) = max(r_topo.at(next), r_topo.at(v) + dist);
            
            if(f_topo.at(next) == 0){
                que.push(next);
            }
        }
    }
}

void r_topoFunc(int dest){
    int &final = r_topo.at(dest);
    que.push(dest);
    
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        for(auto &pp: v_reverse.at(v)){
            int &prev = pp.first;
            int &dist = pp.second;
            
            if(r_isvisited.at(prev))
                continue;
            
            r_isvisited.at(prev) = true;
            if(r_topo.at(v) == r_topo.at(prev) + dist){
                ++rcount;
                que.push(prev);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    v_forward.assign(n+1, vector<P>());
    v_reverse.assign(n+1, vector<P>());
    
    f_topo.assign(n+1, 0);
    r_topo.assign(n+1, 0);
    r_isvisited.assign(n+1, false);
    r_isvisited.at(0) = true;
    
    for(int i=0; i<m; ++i){
        int s, d, t;
        cin >> s >> d >> t;
        
        v_forward.at(s).push_back(make_pair(d, t));
        v_reverse.at(d).push_back(make_pair(s, t));
        
        ++f_topo.at(d);
        ++r_topo.at(s);
    }
    
    int c_source, c_dest;
    cin >> c_source >> c_dest;
    
    f_topoFunc(c_source);
    r_topoFunc(c_dest);
    
    cout << r_topo.at(c_dest) << "\n" << rcount << "\n";

    return 0;
}
