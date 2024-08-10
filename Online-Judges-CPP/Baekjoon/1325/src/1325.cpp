#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> vinput;
vector<int> vnum;

void BFS(const int &i, const int &N, vector<bool> &isvisited){
    queue<int> que;
    que.push(i);
    isvisited.at(i) = true;
    
    while(!que.empty()){
        int front = que.front();
        que.pop();

        for(auto &next: vinput.at(front)){
            if(!isvisited.at(next)){
                ++vnum.at(i);
                isvisited.at(next) = true;
                que.push(next);
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vinput.assign(N+1, vector<int>());
    vnum.assign(N+1, 0);
    vnum.at(0) = -1;

    for(int i=0; i<M; ++i){
        int dest, source;
        cin >> dest >> source;
        vinput.at(source).push_back(dest);
    }
    
    vector<bool> isvisited(N+1, false);
    
    for(int i=1; i<=N; ++i){
        fill(isvisited.begin(), isvisited.end(), false);
        BFS(i, N, isvisited);
    }
    
    int maximum = *max_element(vnum.begin(), vnum.end());
    
    for(int i=1; i<=N; ++i){
        if(maximum == vnum.at(i))
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}
