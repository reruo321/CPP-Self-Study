#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Goodnum{
    int no;
    long long weight;
    
    Goodnum(int n, long long w): no(n), weight(w) {}
    bool operator<(const Goodnum &op) const {
        if(weight != op.weight)
            return weight < op.weight;
        return no < op.no;
    }
};

int main()
{
    int L, n;
    cin >> L;
    
    vector<int> S(L, 0);
    
    for(int i=0; i<S.size(); ++i){
        cin >> S.at(i);
    }
    
    cin >> n;
    
    sort(S.begin(), S.end());
    
    priority_queue<Goodnum> que;
    
    int send_idx = 0;
    int send_last = S.back();
    
    for(auto &s: S){
        que.push(Goodnum(s, 0));
    }
    
    while(send_idx < S.size()){
        
        int sstart_num;
        int send_num;
        
        if(send_idx){
            sstart_num = S.at(send_idx - 1);
        }
        else{
            sstart_num = 0;
        }
        send_num = S.at(send_idx);
        
        for(int i=1; sstart_num + i <= send_num - i; ++i){
            if(send_num - sstart_num == 2){
                que.push(Goodnum(send_num - 1, 0));
                break;
            }
            
            long long mult = static_cast<long long>(i) * (send_num - sstart_num - i);
            Goodnum gn(sstart_num + i, mult);
            if(que.size() < n){
                que.push(gn);
                if(sstart_num + i != send_num - i)
                    que.push(Goodnum(send_num - i, mult));
            }
            else{
                if(gn < que.top()){
                    que.push(gn);
                    if(sstart_num + i != send_num - i)
                        que.push(Goodnum(send_num - i, mult));
                }
                else{
                    break;
                }
                while(que.size() > n){
                    que.pop();
                }
            }
        }
        
        ++send_idx;
    }
    
    while(que.size() < n){
        que.push(Goodnum(++send_last, numeric_limits<long long>::max()));
    }
    while(que.size() > n){
        que.pop();
    }
    
    vector<int> resultvec(que.size(), 0);
    for(int i=0; i<n; ++i){
        resultvec.at(n-1-i) = que.top().no;
        que.pop();
    }
    
    for(auto &v: resultvec){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
