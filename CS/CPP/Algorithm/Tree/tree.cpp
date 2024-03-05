/* In Progress */
#include <iostream>

class TreeNode{

    TreeNode * left;
    TreeNode * right;
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
        TreeNode * t = root;
        
        while(1){
            if(t == nullptr){
                t = new TreeNode(n);
                return;
            }
            if(n < root.getVal()){
                t = root.left;
            }
            else if(n > root.getVal()){
                t = root.right;
            }
        }
    }
    
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
