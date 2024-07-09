#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> T;

long long GCD(long long p, long long q){
    if(!q)
        return p;
    else
        return GCD(q, p%q);
}

void DFS(int node, vector<vector<T>> &vinfo, vector<long long> &vval, vector<bool> &visvisited){
    
    visvisited.at(node) = true;
    
    for(auto &t: vinfo.at(node)){
        int next = get<0>(t);
        if(!visvisited.at(next)){
            vval.at(next) = vval.at(node) * get<2>(t) / get<1>(t);
            DFS(next, vinfo, vval, visvisited);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<vector<T>> vinfo(N, vector<T>());
    vector<long long> vval(N, 0);
    vector<bool> visvisited(N, false);
    
    long long lcm = 1;
    
    for(int i=0; i<N-1; ++i){
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        
        vinfo.at(a).push_back(make_tuple(b, p, q));
        vinfo.at(b).push_back(make_tuple(a, q, p));
        
        lcm *= (p * q / GCD(p, q));
    }
    
    vval.at(0) = lcm;
    DFS(0, vinfo, vval, visvisited);
    
    long long ggcd = vval.at(0);
    for(int i=1; i<N; ++i){
        ggcd = GCD(ggcd, vval.at(i));
    }
    
    for(auto v: vval){
        cout << v/ggcd << " ";
    }

    return 0;
}
