#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const long long LLONG_MAX = numeric_limits<long long>::max();

vector<tuple<int, int, int>> bfgraph;
vector<long long> vertices;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    bfgraph.assign(M, tuple<int, int, int>());
    vertices.assign(N+1, LLONG_MAX);
    
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        bfgraph.at(i) = make_tuple(a, b, c);
    }
    
    vertices.at(1) = 0;
    
    for(int i=0; i<N-1; ++i){
        for(auto &t: bfgraph){
            int s, d, dist;
            tie(s, d, dist) = t;
            
            if(vertices.at(s) == LLONG_MAX)
                continue;
            
            if(vertices.at(d) > vertices.at(s) + dist)
            vertices.at(d) = vertices.at(s) + dist;
        }
    }
    
    bool isokay = true;
    
    for(auto &t: bfgraph){
        int s, d, dist;
        tie(s, d, dist) = t;
        
        if(vertices.at(s) == LLONG_MAX)
            continue;
        
        if(vertices.at(d) > vertices.at(s) + dist){
            isokay = false;
            break;
        }
    }
    
    if(!isokay)
        cout << -1 << "\n";
    else{
        for(int i=2; i<=N; ++i){
            long long &final = vertices.at(i);
            if(final == LLONG_MAX)
                cout << -1 << "\n";
            else
                cout << final << "\n";
        }
    }

    return 0;
}
