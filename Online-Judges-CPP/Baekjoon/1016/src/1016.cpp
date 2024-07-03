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
    
    int sqrt_B = sqrt(B);
    vector<bool> vsquare(sqrt_B+1, true);
    vector<bool> vanswer(B-A+1, true);
    
    long long answer = vanswer.size();
    
    for(int i=2; i<=sqrt_B; ++i){
        if(!vsquare.at(i))
            continue;
        for(int j=2; j<=sqrt_B / i; ++j){
            vsquare.at(i * j) = false;
        }
    }
    
    for(int i=2; i<=sqrt_B; ++i){
        if(!vsquare.at(i))
            continue;
        
        long long i_power = pow(i, 2);
        long long j = A / i_power;
        if(A % i_power)
            ++j;
    
            while(static_cast<double>(A)/static_cast<double>(j) <= static_cast<double>(i_power) && static_cast<double>(B)/static_cast<double>(j) >= static_cast<double>(i_power)){
            long long idx = i_power * j;
            if(vanswer.at(idx-A)){
                vanswer.at(idx-A) = false;
                --answer;
            }
            ++j;
        }
    }
    
    cout << answer << "\n";

    return 0;
}
