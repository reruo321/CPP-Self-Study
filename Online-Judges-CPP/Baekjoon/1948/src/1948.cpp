// Not Finished

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> rsum;
vector<int> rcount;
vector<int> ctopo;

int f_source, f_dest;

void topoFunc(int v){
    if(ctopo.at(v) == 0){
        --ctopo.at(v);
        for(auto &np: graph.at(v)){
            int &next = np.first;
            int &dist = np.second;
            
            --ctopo.at(next);
            
            cout << "? => " << v << " " << next << endl;
            
            int distsum = rsum.at(v) + dist;
            if(rsum.at(next) < distsum){
                rsum.at(next) = distsum;
                rcount.at(next) = rcount.at(v) + 1;
            }
            else if(rsum.at(next) == distsum){
                rcount.at(next) += (rcount.at(v) + 1);
            }
            
            topoFunc(next);
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
