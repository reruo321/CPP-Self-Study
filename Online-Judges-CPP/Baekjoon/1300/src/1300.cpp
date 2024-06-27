#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, k;
    cin >> N >> k;
    
    int start = 1;
    int end = k;
    int answer = k;
    
    while(start <= end){
        int mid = (start + end) / 2;
        int count = 0;
        
        for(int divisor = 1; divisor <= mid && divisor <= N; ++divisor){
            count += min((mid / divisor), N);
        }
        
        if(count < k)
            start = mid + 1;
        else{
            answer = mid;
            end = mid - 1;
        }
    }
    
    cout << answer << "\n";

    return 0;
}
