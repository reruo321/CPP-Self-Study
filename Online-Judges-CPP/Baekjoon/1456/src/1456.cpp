#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long A, B;
    cin >> A >> B;
    
    int sqrt_b = sqrt(B);
    
    vector<bool> vec(sqrt_b + 1, true);
    
    for(int i=2; i<vec.size(); ++i){
        if(vec.at(i)){
            for(int j=2; j<=(vec.size()-1) / i; ++j){
                vec.at(i * j) = false;
            }
        }
    }
    
    long long count = 0;
    
    for(int i=2; i<vec.size(); ++i){
        if(!vec.at(i))
            continue;
        double mult = 1;
        while(1){
            mult *= i;
            if(i > (double) B / mult)
                break;
            if((double) A / mult <= i){
                ++count;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
