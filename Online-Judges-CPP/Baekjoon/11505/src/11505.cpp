#include <iostream>
#include <vector>

using namespace std;

const int REMAIN = 1000000007;
vector<int> segtree;

int getRemain(int x, int y){
    return (static_cast<long long>(x) * static_cast<long long>(y)) % REMAIN;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    int k = 0;
    while((1 << k) < N){
        ++k;
    }
    
    const int halftree = (1 << k);
    segtree.assign(halftree << 1, 1);
    
    for(int i=0; i<N; ++i){
        cin >> segtree.at(halftree + i);
    }
    
    for(int i=halftree - 1; i>=1; --i){
        segtree.at(i) = getRemain(segtree.at(i * 2), segtree.at((i * 2) + 1));
    }
    
    for(int i=0; i<M+K; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1){
            segtree.at(halftree + b - 1) = c;
            for(int i=(halftree + b - 1)/2; i>=1; i/=2){
                segtree.at(i) = getRemain(segtree.at(i * 2), segtree.at((i * 2) + 1));
                
            }
        }
        else{
            int start_idx = halftree + b - 1;
            int end_idx = halftree + c - 1;
            
            int multi = 1;
            while(start_idx <= end_idx){
                if(start_idx % 2 == 1){
                    multi = getRemain(multi, segtree.at(start_idx));
                    ++start_idx;
                }
                if(end_idx % 2 == 0){
                    multi = getRemain(multi, segtree.at(end_idx));
                    --end_idx;
                }
                start_idx /= 2;
                end_idx /= 2;
            }
            cout << multi << "\n";
        }
    }
    
    return 0;
}
