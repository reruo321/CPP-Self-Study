#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int left, int mid, int right){
    int nl = mid - left + 1;
    int nr = right - mid;
    
    vector<int> lvec(nl), rvec(nr);
    
    for(int i=0; i<nl; ++i){
        lvec.at(i) = vec.at(left + i);
    }
    for(int i=0; i<nr; ++i){
        rvec.at(i) = vec.at(mid + 1 +i);
    }
    
    int i=0, j=0, k=left;
    
    while(i<nl && j<nr){
        if(lvec.at(i) <= rvec.at(j)){
            vec.at(k) = lvec.at(i);
            ++i;
        }
        else{
            vec.at(k) = rvec.at(j);
            ++j;
        }
        ++k;
    }
    
    while(i<nl){
        vec.at(k) = lvec.at(i);
        ++i;
        ++k;
    }
    
    while(j<nr){
        vec.at(k) = rvec.at(j);
        ++j;
        ++k;
    }
}

void mergesort(vector<int> &vec, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        
        mergesort(vec, left, mid);
        mergesort(vec, mid+1, right);
        
        merge(vec, left, mid, right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    
    for(int i=0; i<N; ++i)
        cin >> vec.at(i);
        
    mergesort(vec, 0, vec.size()-1);
    
    for(auto &v: vec){
        cout << v << "\n";
    }

    return 0;
}
