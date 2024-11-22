#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int source;
    int dest;
    int weight;
    
    Edge(int s, int d, int w): source(s), dest(d), weight(w){}
    bool operator<(const Edge &comp) const {
        return weight < comp.weight;
    }
};

vector<Edge> edges;
vector<int> root;
vector<int> ufrank;
vector<vector<bool>> isconnected;

int find(int v){
    if(v != root.at(v)){
        root.at(v) = find(root.at(v));
    }
    
    return root.at(v);
}

bool unionf(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a != b){
        
        if(ufrank.at(a) < ufrank.at(b)){
            root.at(a) = b;
        }
        else if(ufrank.at(a) > ufrank.at(b)){
            root.at(b) = a;
        }
        else{
            root.at(b) = a;
            ++ufrank.at(a);
        }
        return true;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    root.assign(N, 0);
    for(int i=0; i<N; ++i){
        root.at(i) = i;
    }
    
    ufrank.assign(N, 0);
    isconnected.assign(N, vector<bool>(N, false));
    
    int sum = 0;
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            char c;
            cin >> c;
            int len = 0;
            
            if(c >= 'a' && c <= 'z'){
                len = c - 'a' + 1;
            }
            else if(c >= 'A' && c <= 'Z'){
                len = c - 'A' + 27;
            }
            
            sum += len;
            
            if(i != j && len > 0){
                edges.push_back(Edge(i, j, len));
            }
        }
    }
    
    sort(edges.begin(), edges.end());
    int edge_group = N;
    
    for(auto &e: edges){
        if(unionf(e.source, e.dest)){
            sum -= e.weight;
            --edge_group;
        }
    }
    
    if(edge_group != 1){
        cout << -1 << "\n";
    }
    else{
        cout << sum << "\n";
    }

    return 0;
}
