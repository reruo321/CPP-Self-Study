#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L, n;
    cin >> L;
    
    vector<int> S(L, 0);
    for(int i=0; i<S.size(); ++i)
        cin >> S.at(i);
    
    cin >> n;
    
    sort(S.begin(), S.end());
    
    if(S.size() <= n){
        for(int i=0; i<n; ++i){
            cout << S.at(i) << " ";
        }
        cout << endl;
        return 0;
    }
    
    int end_idx = 0;
    
    while(end_idx <= S.size()-1){
        int start_num;
        int end_num = S.at(end_idx);
        
        if(!end_idx){
            start_num = 0;
        }
        else{
            start_num = S.at(end_idx-1);
        }
        
        
    }
    
    

    return 0;
}
