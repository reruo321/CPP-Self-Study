#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    long long answer = n;
    
    for(int i=2; i<=sqrt(n); ++i){
        if(!(n % i)){
            answer -= (answer / i);
        }
        while(!(n % i)){
            n /= i;
        }
    }
    
    if(n > 1){
        answer -= (answer / n);
    }
    
    cout << answer << "\n";

    return 0;
}
