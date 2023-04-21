#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = INT_MAX;
    long long q1 = 0;
    long long q2 = 0;
    long long q1sum;
    long long mean;
    queue<int> que1;
    queue<int> que2;
    int count = 0;
    
    for(auto &q: queue1){
        q1 += q;
        que1.push(q);
        }
    que1.push(INT_MAX);
    for(auto &q: queue2){
        q2 += q;
        que2.push(q);
        }
    if((q1+q2)&1)
        return -1;
    mean = (q1+q2) >> 1;
    
    q1sum = q1;
    
    while(que2.front()!=INT_MAX){
        if(que1.front()==INT_MAX){
            que2.push(INT_MAX);
            que1.pop();
        }
        if(q1sum == mean)
            return count;
        else if(q1sum < mean){
            if(que2.front()==INT_MAX)
                return -1;
            q1sum += que2.front();
            que1.push(que2.front());
            que2.pop();
        }
        else{
            q1sum -= que1.front();
            que2.push(que1.front());
            que1.pop();
        }
        ++count;
    }
    
    if(answer == INT_MAX)
        return -1;
    return count;
}
