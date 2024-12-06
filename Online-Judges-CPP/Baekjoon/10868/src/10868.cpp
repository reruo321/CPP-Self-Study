#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> segtree;

const int INT_MAX = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int k = 0;
    while((1 << k) < N){
        ++k;
    }
    const int halftree = (1 << k);
    segtree.assign(halftree << 1, INT_MAX);
    
    for(int i=0; i<N; ++i){
        cin >> segtree.at(halftree + i);
    }
    
    for(int i=halftree+N-1; i>1; --i){
        segtree.at(i/2) = min(segtree.at(i/2), segtree.at(i));
    }
    
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        
        int b_idx = halftree + b - 1;
        int a_idx = halftree + a - 1;
        int minimum = segtree.at(b_idx);
        
        while(a_idx <= b_idx){
            if(a_idx % 2 == 1){
                minimum = min(minimum, segtree.at(a_idx));
                ++a_idx;
            }
            if(b_idx % 2 == 0){
                minimum = min(minimum, segtree.at(b_idx));
                --b_idx;
            }
            a_idx /= 2;
            b_idx /= 2;
        }
        
        cout << minimum << "\n";
    }
    
    return 0;
}
