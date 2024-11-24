#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int sour;
    int dest;
    int weight;
    
    Edge(int s, int d, int w): sour(s), dest(d), weight(w){}
    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};

vector<Edge> spanning;
vector<int> ufroot;
vector<int> ufrank;

int find(int v){
    
    if(ufroot.at(v) != v){
        ufroot.at(v) = find(ufroot.at(v));
    }
    
    return ufroot.at(v);
}

bool unionf(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a != b){
        
        if(ufrank.at(a) < ufrank.at(b))
            ufroot.at(a) = b;
        else if(ufrank.at(a) > ufrank.at(b))
            ufroot.at(b) = a;
        else{
            ufroot.at(b) = a;
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
    
    int V, E;
    cin >> V >> E;
    
    spanning.assign(E, Edge(0, 0, 0));
    ufroot.assign(V+1, 0);
    ufrank.assign(V+1, 0);
    
    for(int i=1; i<=V; ++i){
        ufroot.at(i) = i;
    }
    
    for(int i=0; i<E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        spanning.at(i) = Edge(a, b, c);
    }

    sort(spanning.begin(), spanning.end());
    
    int sum = 0;
    
    for(auto &e: spanning){
        if(unionf(e.sour, e.dest)){
            sum += e.weight;
        }
    }

    cout << sum << "\n";

    return 0;
}
