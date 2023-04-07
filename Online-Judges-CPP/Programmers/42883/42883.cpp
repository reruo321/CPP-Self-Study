#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer;
    stack<char> sta;
    int a = k;
    int i = 0;
    
    for(; i<number.size(); ++i){
        char &num = number.at(i);
        while(!sta.empty() && sta.top() < num && a){
            sta.pop();
            --a;
        }
        if(!a)
            break;
        sta.push(num);
    }
    while(a){
        sta.pop();
        --a;
    }
    while(!sta.empty()){
        answer = sta.top() + answer;
        sta.pop();
    }
    if(i<number.size())
        answer += number.substr(i, string::npos);
    
    return answer;
}
