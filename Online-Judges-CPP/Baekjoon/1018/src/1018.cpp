#include <iostream>
#include <vector>
#include <string>
#include <limits>

#define CHESS_SIDE 8

using namespace std;

int main()
{
    const int chess_cells = CHESS_SIDE * CHESS_SIDE;
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> vec(N, vector<bool>(M, false));
    
    for(int i=0; i<N; ++i){
        string input;
        cin >> input;
        
        for(int k=0; k<M; ++k){
            if(((i % 2) && !(k % 2)) || (!(i % 2) && (k % 2))){
                vec.at(i).at(k) = (input.at(k) == 'W');
            }
            else{
                vec.at(i).at(k) = (input.at(k) == 'B');                
            }
        }
    }
    
    int min_cell = numeric_limits<int>::max();
    
    for(int i=0; i <= N-CHESS_SIDE; ++i){
        int count;
        for(int k=0; k <= M-CHESS_SIDE; ++k){
            count = 0;
            
            for(int a=0; a < CHESS_SIDE; ++a){
                for(int b=0; b < CHESS_SIDE; ++b){
                    if(vec.at(i+a).at(k+b)){
                        ++count;
                    }
                }
            }
            min_cell = std::min(count, min_cell);
            min_cell = std::min(chess_cells-count, min_cell);
        }
    }
    cout << min_cell << endl;

    return 0;
}
