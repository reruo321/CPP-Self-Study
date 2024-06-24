#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<map<int, int>> vinput;
vector<bool> isvisited;
vector<long long> vdistance;

void BFS(int start){
    queue<int> que;
    que.push(start);
    
    fill(isvisited.begin(), isvisited.end(), false);
    fill(vdistance.begin(), vdistance.end(), 0);
    
    isvisited.at(start) = true;
    
    while(!que.empty()){
        int cver = que.front();
        int cdist = vdistance.at(cver);
        que.pop();
        for(auto &m: vinput.at(cver)){
            if(!isvisited.at(m.first)){
                isvisited.at(m.first) = true;
                que.push(m.first);
                vdistance.at(m.first) = cdist + m.second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V;
    cin >> V;
    
    vinput.assign(V+1, map<int, int>());
    
    for(int i=0; i<V; ++i){
        int v;
        int input1, input2;
        cin >> v;
        while(1){
            cin >> input1;
            if(input1 < 0)
                break;
            cin >> input2;
            
            vinput.at(v).insert(make_pair(input1, input2));
        }
    }

    isvisited.assign(V+1, false);
    vdistance.assign(V+1, 0);
    
    BFS(1);
    
    int sstart = distance(vdistance.begin(), max_element(vdistance.begin(), vdistance.end()));
    
    BFS(sstart);
    
    cout << *max_element(vdistance.begin(), vdistance.end()) << "\n";

    return 0;
}
