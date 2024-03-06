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
                    // find the minimum value in right subtree
                    
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
    std::cout<<"Hello World";

    return 0;
}
