// Not finished, wrong solution

#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const long long LLONG_MAX = numeric_limits<long long>::max();

vector<tuple<int, int, int>> edges;
vector<long long> vertices;
vector<int> credits;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, start, dest, M;
    cin >> N >> start >> dest >> M;
    
    edges.assign(M, tuple<int, int, int>());
    
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.at(i) = {a, b, c};
    }
    
    vertices.assign(N, LLONG_MAX);
    credits.assign(N, 0);
    
    for(int i=0; i<N; ++i){
        cin >> credits.at(i);
    }
    
    if(N == 1){
        if(M > 0){
            for(auto &t: edges){
                int &cost = get<2>(t);
                if(cost < credits.at(0)){
                    cout << "Gee\n";
                    return 0;
                }
            }
        }
        cout << credits.at(0) << "\n";
        return 0;
    }
    
    vertices.at(start) = credits.at(start);
    
    for(int i=0; i<N-1; ++i){
        for(auto &t: edges){
            int s, d, cost;
            tie(s, d, cost) = t;
            
            if(vertices.at(s) != LLONG_MAX){
                long long compdist = vertices.at(s) - cost + credits.at(d);
                if(vertices.at(d) == LLONG_MAX || vertices.at(d) < compdist){
                    vertices.at(d) = compdist;
                }
            }
        }
    }
    
    long long first_dest = vertices.at(dest);
    
    if(first_dest == LLONG_MAX){
        cout << "gg\n";
        return 0;
    }

    for(int i=0; i<N-1; ++i){
        for(auto &t: edges){
            int s, d, cost;
            tie(s, d, cost) = t;
            
            if(vertices.at(s) != LLONG_MAX){
                long long compdist = vertices.at(s) - cost + credits.at(d);
                if(vertices.at(d) < compdist){
                    vertices.at(d) = compdist;
                }
            }
        }
    }
    
    if(first_dest >= vertices.at(dest)){
        cout << first_dest << "\n";
    }
    else{
        cout << "Gee\n";
    }

    return 0;
}
