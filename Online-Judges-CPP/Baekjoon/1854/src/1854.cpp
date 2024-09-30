#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, long long> P;

vector<vector<P>> graph;
priority_queue<P, vector<P>, greater<P>> que;
vector<priority_queue<long long>> citydist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    graph.assign(n+1, vector<P>());
    citydist.assign(n+1, priority_queue<long long>());
    
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        
        graph.at(a).push_back(make_pair(b, c));
    }
    
    que.push(make_pair(0, 1));
    citydist.at(1).push(0);
    
    while(!que.empty()){
        P p = que.top();
        que.pop();
        
        long long &vtime = p.first;
        long long &v = p.second;
        
        for(auto &np: graph.at(v)){
            long long &next = np.first;
            long long &dist = np.second;
            bool issmall = true;
            
            long long total_time = vtime + dist;
            
            if(citydist.at(next).size() < k){
                citydist.at(next).push(total_time);
            }
            else{
                if(total_time < citydist.at(next).top()){
                    citydist.at(next).pop();
                    citydist.at(next).push(total_time);
                }
                else{
                    issmall = false;
                }
            }
            
            if(issmall){
                que.push(make_pair(total_time, next));
            }
        }
    }
    
    for(int i=1; i<=n; ++i){
        if(citydist.at(i).size() != k)
            cout << -1 << "\n";
        else
            cout << citydist.at(i).top() << "\n";
    }

    return 0;
}
