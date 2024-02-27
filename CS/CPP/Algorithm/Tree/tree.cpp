/* In Progress */
#include <iostream>

class TreeNode{

    TreeNode * front;
    TreeNode * back;
    int val;
    
    TreeNode(int v): val(v), front(nullptr), back(nullptr) {}
    
    setFront(TreeNode n){
        front = &n;
    }
    setBack(TreeNode n){
        back = &n;
    }

};

class Tree{
    
    int traversal;
    
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
