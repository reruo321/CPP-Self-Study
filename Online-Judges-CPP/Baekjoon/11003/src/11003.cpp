#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, L;
    cin >> N >> L;
    int input;
    
    deque<pair<int, int>> deq;
    
    for(int i=0; i<N; ++i){
        cin >> input;
        
        if(deq.empty()){
            deq.push_back(make_pair(i, input));
        }
        else{
            while(!deq.empty() && i - deq.front().first >= L){
                deq.pop_front();
            }
            while(!deq.empty() && deq.back().second >= input){
                deq.pop_back();
            }
            deq.push_back(make_pair(i, input));
        }
        cout << deq.front().second << " ";
    }

    return 0;
}
