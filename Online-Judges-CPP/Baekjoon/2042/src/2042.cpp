#include <iostream>
#include <vector>

using namespace std;

vector<long long> segtree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    int plevel = 0;
    
    while((1 << plevel) < N){
        ++plevel;
    }
    
    segtree.assign(1 << (plevel + 1), 0);
    const int halftree = segtree.size()/2;
    
    for(int i=0; i<N; ++i){
        cin >> segtree.at(halftree + i);
    }
    
    for(int i=segtree.size()-1; i>1; --i){
        segtree.at(i / 2) += segtree.at(i);
    }
    
    for(int i=0; i<M+K; ++i){
        int x, y;
        long long z;
        cin >> x >> y >> z;
        
        if(x == 1){
            int changed_idx = halftree + y - 1;
            long long diff = z - segtree.at(changed_idx);
            segtree.at(changed_idx) = z;

            while(changed_idx > 1){
                segtree.at(changed_idx / 2) += diff;
                changed_idx /= 2;
            }
        }
        else{
            long long segsum = 0;
            int start_idx = halftree + y - 1;
            int end_idx = halftree + z - 1;
            
            while(start_idx <= end_idx){
                if(start_idx % 2 == 1){
                    segsum += segtree.at(start_idx);
                }
                if(end_idx % 2 == 0){
                    segsum += segtree.at(end_idx);
                }
                
                start_idx = (start_idx + 1) / 2;
                end_idx = (end_idx - 1) / 2;
            }
            cout << segsum << "\n";
        }
    }

    return 0;
}
