#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floyd;
vector<int> bacon;

const int INT_MAX = 100 * 5000 * 10;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    floyd.assign(N+1, vector<int>(N+1, INT_MAX));
    bacon.assign(N+1, 0);
    
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        floyd.at(a).at(b) = 1;
        floyd.at(b).at(a) = 1;
    }
    
    for(int i=1; i<=N; ++i)
        floyd.at(i).at(i) = 0;
        
    for(int k=1; k<=N; ++k){
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                int &f = floyd.at(i).at(j);
                int m1 = floyd.at(i).at(k);
                int m2 = floyd.at(k).at(j);
                
                if(m1 != INT_MAX && m2 != INT_MAX){
                    f = min(f, m1 + m2);
                }
            }
        }
    }

    int answer = 1;
    int bacon_min = INT_MAX;
    
    for(int i=1; i<=N; ++i){
        for(auto &c: floyd.at(i)){
            if(c != INT_MAX){
                bacon.at(i) += c;
            }
        }
        if(bacon_min > bacon.at(i)){
            answer = i;
            bacon_min = bacon.at(i);
        }
    }

    cout << answer << "\n";
    
    return 0;
}
