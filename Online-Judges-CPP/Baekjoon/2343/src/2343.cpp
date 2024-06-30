#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> vinput(N, 10000);
    
    int max_lecture = 1;
    int sum = 0;

    for(int i=0; i<N; ++i){
        cin >> vinput.at(i);
        max_lecture = max(max_lecture, vinput.at(i));
        sum += vinput.at(i);
    }

    int answer = sum;
    int start = max_lecture;
    int end = sum;
    
    while(start <= end){
        int capacity = (start + end) / 2;
        int count = 0;
        int blueray_inside = 0;
        
        for(int i=0; i<vinput.size(); ++i){
            int lec = vinput.at(i);
            if(blueray_inside + lec < capacity){
                blueray_inside += lec;
            }
            else if(blueray_inside + lec == capacity){
                ++count;
                blueray_inside = 0;
            }
            else{
                ++count;
                blueray_inside = lec;
            }
        }
        
        if(blueray_inside)
            ++count;
        
        if(count <= M){
            answer = min(answer, capacity);
            end = capacity - 1;
        }
        else{
            start = capacity + 1;
        }
    }
    cout << answer << "\n";

    return 0;
}
