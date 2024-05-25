#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int start, int end){
    int pivot = vec.at(end);
    int pidx = start;
    
    for(int i=start; i<end; ++i){
        if(vec.at(i) <= pivot){
            swap(vec.at(i), vec.at(pidx));
            ++pidx;
        }
    }
    swap(vec.at(pidx), vec.at(end));
    return pidx;
}

void quicksort(vector<int> &vec, int start, int end){
    if(start < end){
        int pidx = partition(vec, start, end);
        quicksort(vec, start, pidx - 1);
        quicksort(vec, pidx + 1, end);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    
    for(int i=0; i<N; ++i)
        cin >> vec.at(i);
    
    quicksort(vec, 0, vec.size()-1);
    for(auto &v: vec)
        cout << v << " ";

    return 0;
}
