#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> adj;
static vector<bool> isvisited;

void DFS(int n){
    isvisited.at(n) = true;
    for(auto &a: adj.at(n)){
        if(!isvisited.at(a)){
            DFS(a);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    adj.assign(N+1, vector<int>());
    
    for(int i=0; i<M; ++i){
        int input1, input2;
        cin >> input1 >> input2;
        
        adj.at(input1).push_back(input2);
        adj.at(input2).push_back(input1);
    }
    
    isvisited.assign(N+1, false);
    int answer = 0;
    
    for(int i=1; i<isvisited.size(); ++i){
        if(!isvisited.at(i)){
            ++answer;
            DFS(i);
        }
    }
    
    cout << answer << endl;

    return 0;
}
