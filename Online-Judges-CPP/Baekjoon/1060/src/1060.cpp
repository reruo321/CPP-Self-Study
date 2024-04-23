#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct Goodnum{
    int no;
    long long weight;
    
    Goodnum(int n, long long w): no(n), weight(w){}
    bool operator<(const Goodnum &another) const {
        if(weight != another.weight){
            return weight > another.weight;
        }
        return no > another.no;
    }
};


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
    
    priority_queue<Goodnum> pque;
    for(auto &s: S){
        pque.push(Goodnum(s, 0));
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
        
        long long peak = 0;
        
        for(int i=start_thres+1; i<end_thres; ++i){
            long long multi = (i-start_thres)*(end_thres-i);
            if(multi > peak){
                peak = multi;
                if(pque.size() < n || (pque.size() >= n && pque.top().weight >= multi)){
                    pque.push(Goodnum(i, multi));
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        
        while(pque.size() > n){
            pque.pop();
        }
        
        ++end_idx;
    }
    
    while(pque.size() < n){
        pque.push(Goodnum(++sback, numeric_limits<long long>::max()));
    }
    
    while(pque.size() > n){
        pque.pop();
    }
    
    while(!pque.empty()){
        cout << pque.top().no << " ";
        pque.pop();
    }
    
    return 0;
}
