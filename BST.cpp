#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }

    return root;

}

Node* preorder(Node* root){
    if (root == NULL) return 0;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* inorder(Node* root){
    if (root == NULL) return 0;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* postorder(Node* root){
    if (root == NULL) return 0;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = new Node(7);

    int keys[] = {20,3,48,2,9,34,57};
    for (int key: keys){
        insertBST(root, key);
    }

    cout<<"Preoreder : ";
    preorder(root);
    cout<<endl;
    cout<<"Inoreder : ";
    inorder(root);
    cout<<endl;
    cout<<"Postoreder : ";
    postorder(root);
    cout<<endl;

    return 0;
}