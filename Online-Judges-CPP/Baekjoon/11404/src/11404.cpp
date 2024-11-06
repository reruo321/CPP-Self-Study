// Not finished

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<vector<int>> floyd;

const int INT_MAX = 100 * 100000 * 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    floyd.assign(n+1, vector<int>(n+1, INT_MAX));

    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        int &f = floyd.at(a).at(b);
        f = min(f, c);
    }
    
    for(int i=1; i<=n; ++i){
        floyd.at(i).at(i) = 0;
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            for(int k=1; k<=n; ++k){
                int &f = floyd.at(j).at(k);
                
                if(j == 2 && k == 1){
                    cout << "--- " << f << "\n";
                }
                
                if(f != INT_MAX){
                    f = min(f, floyd.at(j).at(i) + floyd.at(i).at(k));
                }
            }
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            int &f = floyd.at(i).at(j);
            if(f == INT_MAX){
                cout << 0 << " ";
            }
            else{
                cout << f << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
