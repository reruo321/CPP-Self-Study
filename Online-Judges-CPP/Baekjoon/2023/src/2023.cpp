#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

static vector<set<int>> prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    prime.assign(N, set<int>());

    prime.at(0).insert(2);
    prime.at(0).insert(3);
    prime.at(0).insert(5);
    prime.at(0).insert(7);
    
    for(int i=1; i<N; ++i){
        for(auto &p: prime.at(i-1)){
            for(int j=1; j<10; j+=2){
                int num = stoi(to_string(p)+to_string(j));
                bool isprime = true;
                for(int d=3; d<=sqrt(num); ++d){
                    if(!(num % d)){
                        isprime = false;
                        break;
                    }
                }
                if(isprime)
                    prime.at(i).insert(num);
            }
        }
    }
    
    for(auto &p: prime.at(N-1)){
        cout << p << "\n";
    }

    return 0;
}
