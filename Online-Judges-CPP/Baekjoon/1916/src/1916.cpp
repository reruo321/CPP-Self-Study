#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> dijk;
vector<bool> isvisited;

auto comp = [](const P &a, const P &b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    graph.assign(N+1, vector<P>());

    for(int i=0; i<M; ++i){
        int s, d, c;
        cin >> s >> d >> c;
        
        graph.at(s).push_back(make_pair(d, c));
    }
    
    int A, B;
    cin >> A >> B;
    
    dijk.assign(N+1, numeric_limits<int>::max());
    dijk.at(A) = 0;
    
    priority_queue<P, vector<P>, decltype(comp)> que(comp);
    que.push(make_pair(A, dijk.at(A)));
    
    isvisited.assign(N+1, false);
    
    while(!que.empty()){
        int v = que.top().first;
        que.pop();
        
        if(isvisited.at(v))
            continue;
        
        isvisited.at(v) = true;
        
        for(auto &np: graph.at(v)){
            int &next = np.first;
            int &time = np.second;
            
            if(dijk.at(next) > dijk.at(v) + time){
                dijk.at(next) = dijk.at(v) + time;
                que.push(make_pair(next, dijk.at(next)));
            }
        }
    }
    
    cout << dijk.at(B) << "\n";

    return 0;
}
