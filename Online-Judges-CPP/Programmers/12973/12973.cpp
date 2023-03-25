#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    if(s.size()&1)
        return 0;
 
    stack<char> sstack;
    
    for(auto &c: s){
        if(sstack.empty())
            sstack.push(c);
        else{
            if(sstack.top()==c){
                sstack.pop();
            }
            else{
                sstack.push(c);
            }
        }
    }
    if(sstack.empty())
        return 1;

    return 0;
}
