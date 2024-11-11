#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> floyd;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    floyd.assign(N, vector<bool>(N, false));
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int input;
            cin >> input;
            
            if(input)
                floyd.at(i).at(j) = true;
        }
    }
        
    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(floyd.at(i).at(k) && floyd.at(k).at(j)){
                    floyd.at(i).at(j) = true;
                }
            }
        }
    }
    
    for(auto &row: floyd){
        for(auto b: row){
            if(b){
                cout << "1 ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
