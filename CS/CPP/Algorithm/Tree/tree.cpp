/* In Progress */
#include <iostream>

class TreeNode{

    TreeNode * front;
    TreeNode * back;
    int val;

public:
    // Note: nullptr is supported since C++11
    TreeNode(int v): val(v), front(nullptr), back(nullptr) {}
    
    void setFront(TreeNode n){
        front = &n;
    }
    void setBack(TreeNode n){
        back = &n;
    }
    
    void getVal(){
        return val;
    }

};

class BST{
    
    TreeNode * root;

pulic:

    BST(): root(nullptr){}
    
    void insert(const int &n){
        
        if(root == nullptr){
            root = new TreeNode(n);
            return;
        }
        
        if(root.val){
            
        }
        
    }
    
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
