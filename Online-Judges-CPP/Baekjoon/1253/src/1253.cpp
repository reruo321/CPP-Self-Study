#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int answer = 0;
    
    cin >> N;
    vector<int> vinput(N, 0);
    
    for(int i=0; i<N; ++i){
        cin >> vinput.at(i);
    }
    
    sort(vinput.begin(), vinput.end());
    
    for(int i=0; i<vinput.size(); ++i){
        int p = 0;
        int q = vinput.size()-1;
        
        while(p < q){
            if(i == p){
                ++p;
                continue;
            }
            else if(i == q){
                --q;
                continue;
            }
            
            int sum = vinput.at(p) + vinput.at(q);
            
            if(sum < vinput.at(i))
                ++p;
            else if(sum > vinput.at(i))
                --q;
            else{
                ++answer;
                break;
            }
        }
    }
    
    cout << answer << endl;

    return 0;
}
