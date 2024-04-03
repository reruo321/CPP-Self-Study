#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> original2d(N+1, vector<int>(N+1, 0));
    vector<vector<int>> prefixsum2d(N+1, vector<int>(N+1, 0));
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin >> original2d.at(i).at(j);
            prefixsum2d.at(i).at(j) = prefixsum2d.at(i-1).at(j) + prefixsum2d.at(i).at(j-1) - prefixsum2d.at(i-1).at(j-1) + original2d.at(i).at(j);
        }
    }
    
    for(int i=0; i<M; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << prefixsum2d.at(x2).at(y2) - prefixsum2d.at(x2).at(y1-1) - prefixsum2d.at(x1-1).at(y2) + prefixsum2d.at(x1-1).at(y1-1) << '\n';
    }
    
    return 0;
}
