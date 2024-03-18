/* In Progress */
#include <iostream>

class TreeNode{

    TreeNode * left;
    TreeNode * right;
    int val;

public:
    // Note: nullptr is supported since C++11
    TreeNode(int v): val(v), front(nullptr), back(nullptr) {}
    
    void setLeft(TreeNode n){
        left = &n;
    }
    void setRight(TreeNode n){
        right = &n;
    }
    
    void getVal(){
        return val;
    }

};

class BST{
    
    TreeNode * root;

pulic:

    BST(): root(nullptr){}
    
    void insertNode(const int &n){
        TreeNode * t = root;
        
        while(1){
            if(t == nullptr){
                t = new TreeNode(n);
                std::cout << "Inserted " << n << "." << endl;
                return;
            }
            if(n < t.getVal()){
                t = t.left;
            }
            else if(n > t.getVal()){
                t = t.right;
            }
            else{
                return;
            }
        }
    }
    
    void removeNodeSubtree(TreeNode * node){
        
    }
    
    void removeNode(const int &n){
        
        TreeNode * t = root;
        
        while(1){
            
            if(t == nullptr){
                std::cout << "Could not find " << n << "." << endl;
                return;
            }
            else{
                if(n < t.getVal()){
                    t = t.left;
                }
                else if(n > t.getVal()){
                    t = t.right;
                }
                else{
                    // 1. No child
                    // remove the root (no children)
                    if(t.left == nullptr && t.right == nullptr)
                        delete t;
                    
                    // 2. One child
                    // bring the child to the root
                    
                    // 3. Two children
                    // find the minimum value RMIN in the right subtree, which is in the leftmost node in it
                    // change the root to RMIN
                    // process moving on RMIN's previous children
                    std::cout << "Removed " << n << "." << endl;
                    return;
                }
            }
            

        }
        
    }
    
};


int main()
{
    BST bst = new BST();

    return 0;
}
