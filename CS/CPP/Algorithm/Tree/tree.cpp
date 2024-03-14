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
                    // find the minimum value in the right subtree, which is in the leftmost node in it
                    
                    removeNodeSubtree(t);
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
