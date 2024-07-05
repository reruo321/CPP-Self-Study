#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;
    
    long long bg = a >= b ? a : b;
    long long sm = a >= b ? b : a;
    
    long long r;
    
    while(1){
        r = bg % sm;
        if(!r)
            break;
        bg = sm;
        sm = r;
    }
    
    cout << string(sm, '1') << "\n";

    return 0;
}
