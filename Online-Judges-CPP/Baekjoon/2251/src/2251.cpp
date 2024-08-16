#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<vector<bool>>> graph;
queue<vector<int>> que;
vector<int> capa;

void pushNextStatus(const int &a, const int &b, const int &c){
    const vector<int> initstat = {a, b, c};
    
    for(int i=0; i<initstat.size(); ++i){
        if(initstat.at(i) == 0)
            continue;
        for(int j=0; j<initstat.size(); ++j){
            if(i == j)
                continue;
            
            int k = initstat.at(i);
            int m = initstat.at(j);
            vector<int> next = {a, b, c};
            
            if(m + k >= capa.at(j)){
                next.at(i) = m + k - capa.at(j);
                next.at(j) = capa.at(j);
            }
            else{
                next.at(i) = 0;
                next.at(j) = m + k;
            }
            
            que.push(next);
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    capa.assign(3, 0);
    for(int i=0; i<capa.size(); ++i){
        cin >> capa.at(i);
    }
    
    graph.assign(capa.at(0)+1, vector<vector<bool>>(capa.at(1)+1, vector<bool>(capa.at(2)+1, false)));
    
    que.push(vector<int>{0, 0, capa.at(2)});
    while(!que.empty()){
        vector<int> current = que.front();
        que.pop();
        
        int cura = current.at(0);
        int curb = current.at(1);
        int curc = current.at(2);
        
        if(!graph.at(cura).at(curb).at(curc)){
            graph.at(cura).at(curb).at(curc) = true;
            pushNextStatus(cura, curb, curc);
        }
        
    }
    
    set<int> answer;
    
    for(int i=0; i<=capa.at(1); ++i){
        for(int j=0; j<=capa.at(2); ++j){
            if(graph.at(0).at(i).at(j)){
                answer.insert(j);
            }
        }
    }
    
    for(auto &a: answer){
        cout << a << " ";
    }
    
    cout << "\n";

    return 0;
}
