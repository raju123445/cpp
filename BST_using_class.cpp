#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
    };

class BST{
    public:
    Node* insertBST(Node* root, int val){
        if (root == NULL)
            return new Node(val);

        if(val < root->data)
            root->left = insertBST(root->left, val);

        else
            root->right = insertBST(root->right, val);

        return root;
    }

    void preorder(Node* root){
        if (root == NULL) return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if (root == NULL) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(Node* root){
        if (root == NULL) return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};

int main(){
    BST bst;
    Node* root = NULL;

    int keys[] = {20,3,48,2,9,34,57};
    for (int key: keys){
        root = bst.insertBST(root, key);
    }

    cout<<"Preorder : ";
    bst.preorder(root);
    cout<<endl;

    cout<<"Inorder : ";
    bst.inorder(root);
    cout<<endl;

    cout<<"Postorder : ";
    bst.postorder(root);
    cout<<endl;

    return 0;
}

