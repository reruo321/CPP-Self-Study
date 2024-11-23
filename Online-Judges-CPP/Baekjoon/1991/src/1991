#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> btree;

void preorder(char c){
    if(c != '.'){
        auto &next = btree.at(c - 'A');
        
        cout << c;
        preorder(next.at(0));
        preorder(next.at(1));
    }
}

void inorder(char c){
    if(c != '.'){
        auto &next = btree.at(c - 'A');
        
        inorder(next.at(0));
        cout << c;
        inorder(next.at(1));
    }
}

void postorder(char c){
    if(c != '.'){
        auto &next = btree.at(c - 'A');
        
        postorder(next.at(0));
        postorder(next.at(1));
        cout << c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    btree.assign(N, vector<char>(2, '.'));
    
    for(int i=0; i<N; ++i){
        char a, b, c;
        cin >> a >> b >> c;
        
        if(b != '.')
            btree.at(a - 'A').at(0) = b;
        if(c != '.')
            btree.at(a - 'A').at(1) = c;
    }
    
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
    
    return 0;
}
