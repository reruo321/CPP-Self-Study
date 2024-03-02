/* In Progress */
#include <iostream>

class TreeNode{

    TreeNode * front;
    TreeNode * back;
    int val;

    // Note: nullptr is supported since C++11
    TreeNode(int v): val(v), front(nullptr), back(nullptr) {}
    
    setFront(TreeNode n){
        front = &n;
    }
    setBack(TreeNode n){
        back = &n;
    }

};

class BST{
    
    TreeNode * root;

pulic:

    BST(): root(nullptr){}
    
    void insert(const int &n){
        if(root == nullptr){
            
        }
    }
    
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
