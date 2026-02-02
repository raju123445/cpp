#include<iostream>
using namespace std;

enum color {RED, BLACK};

struct RBNode{
    int data;
    color color;
    RBNode *left, *right, *parent;

    RBNode(int val){
        data = val;
        color = RED;
        left = right = parent = nullptr;
    }
};

class RBTree{
    private:
        RBNode* root;
        RBNode* NIL;
        void leftRotate(RBNode* x){
            RBNode* y = x->right;
            x->right = y->left;

            if(y->left != NIL)          // imp
                y->left->parent = x;

            y->parent = x->parent;

            if(x->parent == NIL)
                root = y;
            else if(x->parent->left == x)
                x->parent->left = y;
            else
                x->parent->right = y;

            x->parent = y;
            y->left = x;
        }

        void rightRotate(RBNode* x){
            RBNode* y = x->left;
            x->left = y->right;

            if(y->right != NIL)
                y->right->parent = x;

            y->parent = x->parent;

            if(x->parent == NIL)
                root = y;

            else if(x->parent->left == x)
                x->parent->left = y;  //x->left->parent = y;

            else
                x->parent->right = y;

            x->parent = y;
            y->right = x;
        }

        void insertFixUp(RBNode* z){
            while(z->parent->color == RED){
                if(z->parent == z->parent->parent->left){
                    RBNode* y = z->parent->parent->right;
                    if(y->color == RED){
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent; //imp
                    }
                    else{
                        if(z == z->parent->right){
                            z = z->parent; //imp
                            leftRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rightRotate(z->parent->parent);
                    }
                }
                else{
                    RBNode* y = z->parent->parent->left; //imp
                    if(y->color == RED){
                        z->parent->color = BLACK;
                        y->color = RED;
                        z->parent->parent->color = BLACK;
                        z = z->parent->parent;
                    }
                    else{
                        if(z == z->parent->left){
                            z = z->parent; //imp
                            rightRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->color = BLACK;
        }

    public:

        RBTree(){
            NIL = new RBNode(0);
            NIL->color = BLACK;
            NIL->left = NIL->right = NIL->parent = nullptr;
            root = NIL;
        }
        RBNode* RBInsertion(int val){
            RBNode* z = new RBNode(val);
            z->color = RED;
            z->left = z->right = z->parent = NIL;

            RBNode* x = root;
            RBNode* y = NIL;

            while (x != NIL){
                y = x;

                if(val < x->data)
                    x = x->left;
                else
                    x = x->right;
            }
            z->parent = y;
            if(y == NIL)   //imp error
                root = z;
            else if(z->data < y->data)
                y->left = z;
            else
                y->right = z;

            insertFixUp(z);

            return root;
        }

        void inorder(RBNode* root){
            if(root == NIL)//imp
                return;

            inorder(root->left);
            cout<<root->data<<"("<<(root->color==BLACK ? "B" : "R")<<") ";
            inorder(root->right);
        }

        void print(){
            inorder(root);
            cout<<endl;
        }
};

int main(){
    int values[] = {20,3,48,2,9,34,57};
    RBTree rbt;

    for(int val : values){
        rbt.RBInsertion(val);
    }

    rbt.print();
    
    return 0;
}