// Not Finished. Wrong solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> rsum;
vector<int> rcount;
vector<int> ctopo;
queue<int> que;

int f_source, f_dest;

void topoFunc(int start){
    que.push(start);
    
    while(!que.empty()){
        int v = que.front();
        que.pop();
        
        for(auto &np: graph.at(v)){
            int &next = np.first;
            int &dist = np.second;
            
            --ctopo.at(next);
            
            int distsum = rsum.at(v) + dist;
            if(rsum.at(next) < distsum){
                rsum.at(next) = distsum;
                rcount.at(next) = rcount.at(v) + 1;
                
                cout << "~~~ " << v << " " << next << " => " << rcount.at(next) << endl;
            }
            else if(rsum.at(next) == distsum){
                rcount.at(next) += (rcount.at(v) + 1);
                cout << "@@@ " << v << " " << next << " => " << rcount.at(next) << endl;
            }
            
            if(ctopo.at(next) == 0){
                que.push(next);
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
    
    graph.assign(n+1, vector<P>());
    rcount.assign(n+1, 0);
    rsum.assign(n+1, 0);
    ctopo.assign(n+1, 0);
    
    for(int i=0; i<m; ++i){
        int source, dest, d;
        cin >> source >> dest >> d;
        graph.at(source).push_back(make_pair(dest, d));
        ++ctopo.at(dest);
    }
    
    cin >> f_source >> f_dest;
    topoFunc(f_source);
    
    cout << rsum.at(f_dest) << "\n" << rcount.at(f_dest) << "\n";

    return 0;
}
