#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
    
    if(S.size() > n){
        for(int i=0; i<n; ++i){
            cout << S.at(i) << " ";
        }
        cout << endl;
        return 0;
    }
    
    int sback = S.back();
    
    vector<pair<int, long long>> goodnums(sback+1);
    goodnums.at(0) = make_pair(0, numeric_limits<long long>::max());
    
    for(auto s: S){
        goodnums.at(s) = make_pair(s, 0);
    }
    
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
            goodnums.at(i) = make_pair(i, static_cast<long long>((i-start_thres)*(end_thres-i)));
        }
        
        ++end_idx;
    }
    
    sort(goodnums.begin(), goodnums.end(), [](const pair<int, long long> &a, const pair<int, long long> &b){
        if(a.second == b.second)
            return a < b;
        return a.second < b.second;
    });
    
    int count = 0;
    
    for(auto &p: goodnums){
        if(p.first){
            if(count < n){
                cout << p.first << " ";
                ++count;
            }
            else
                break;
        }
    }
    
    while(count < n){
        cout << ++sback << " ";
        ++count;
    }
    
    return 0;
}
