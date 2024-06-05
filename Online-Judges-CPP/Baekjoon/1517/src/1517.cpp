#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &vec, int start, int mid, int end){
    long long count = 0;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    vector<int> v1(n1);
    vector<int> v2(n2);
    
    for(int i=0; i<n1; ++i)
        v1.at(i) = vec.at(start+i);
    for(int i=0; i<n2; ++i)
        v2.at(i) = vec.at(mid+1+i);
        
    int i=0, j=0, k=start;
        
    while(i<n1 && j<n2){
        if(v1.at(i) <= v2.at(j)){
            vec.at(k) = v1.at(i);
            ++i;
        }
        else{
            count += (mid+1+j-k);
            vec.at(k) = v2.at(j);
            ++j;
        }
        ++k;
    }
    
    while(i<n1){
        vec.at(k) = v1.at(i);
        ++i;
        ++k;
    }
    
    while(j<n2){
        vec.at(k) = v2.at(j);
        ++j;
        ++k;
    }
    
    return count;
}

long long mergesort(vector<int> &vec, int start, int end){
    long long count = 0;
    if(start < end){
        int mid = start + (end - start)/2;
        
        count += mergesort(vec, start, mid);
        count += mergesort(vec, mid+1, end);
        
        count += merge(vec, start, mid, end);
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> vec(N);
    
    for(int i=0; i<N; ++i)
        cin >> vec.at(i);

    cout << mergesort(vec, 0, vec.size()-1) << endl;

    return 0;
}
