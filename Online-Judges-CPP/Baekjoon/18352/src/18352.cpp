#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<set<int>> road;
    vector<bool> isvisited;
    
    road.assign(N+1, set<int>());
    
    for(int i=0; i<M ;++i){
        int source, dest;
        cin >> source >> dest;
        road.at(source).insert(dest);
    }
    
    isvisited.assign(N+1, false);
    isvisited.at(0) = true;
    
    queue<pair<int, int>> que;
    que.push(make_pair(X, 0));
    vector<int> answer;
    
    while(!que.empty()){
        int v = que.front().first;
        int dist = que.front().second;
        que.pop();
        
        if(!isvisited.at(v)){
            isvisited.at(v) = true;
            if(dist >= K){
                if(dist == K)
                    answer.push_back(v);
                continue;
            }
            else{
                for(auto &next: road.at(v)){
                    if(!isvisited.at(next)){
                        que.push(make_pair(next, dist + 1));
                    }
                }
            }
        }
    }
    
    if(answer.empty())
        cout << -1 << endl;
    else{
        sort(answer.begin(), answer.end());
        for(auto &a: answer){
            cout << a << endl;
        }
    }
    
    return 0;
}
