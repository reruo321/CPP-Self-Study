#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> gleader;
stack<int> sta;

int findLeader(int n){
    int leader = gleader.at(n);
    
    if(n != leader){
        leader = findLeader(gleader.at(n));
    }
    sta.push(n);
    
    return leader;
}

void setLeader(int leader){
    while(!sta.empty()){
        int top = sta.top();
        sta.pop();
        gleader.at(top) = leader;
    }
}

void unionSet(int x, int y){
    stack<int>().swap(sta);
    
    int xleader = findLeader(x);
    int yleader = findLeader(y);

    int leader = min(xleader, yleader);
    setLeader(leader);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    gleader.assign(n+1, 0);
    
    for(int i=0; i<gleader.size(); ++i){
        gleader.at(i) = i;
    }
    
    for(int i=0; i<m; ++i){
        int k, a, b;
        cin >> k >> a >> b;
        
        if(k == 0){
            if(a == b)
                continue;
            unionSet(a, b);
        }
        else{
            if(a == b){
                cout << "YES\n";
            }
            else{
                setLeader(findLeader(a));
                setLeader(findLeader(b));
                if(gleader.at(a) == gleader.at(b))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }

    return 0;
}
