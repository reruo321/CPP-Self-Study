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
    
    vector<pair<int, long long>> goodnums(S.back()+1, 0);
    
    int end_idx = 0;
    
    while(end_idx < S.size()){
        int start_thres;
        int end_thres = S.at(end_idx);
        
        if(!end_idx){
            start_thres = 0;
        }
        else{
            start_thres = S.at(end_idx-1);
        }
        
        for(int i=start_thres+1; i<end_thres; ++i){
            goodnums.push_back(make_pair(i, static_cast<long long>((i-start_thres)*(end_thres-i))));
        }
        
    }
    
    return 0;
}
