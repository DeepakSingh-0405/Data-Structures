#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* root = NULL;
node* newNode(int data){
    node* newNode = new node();
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data){
    if(root == NULL){
        root = newNode(data);
        return root;
    }
    if(data <= root->data) root->left = insert(root->left,data);
    else root->right = insert(root->right,data);
    return root;
}

node* search(node* root, int data){
    if(root == NULL){
        cout<<"Element not found"<<endl;
        return root;
    }if(root->data == data){
        cout<<"Element found"<<endl;
        return root;
    }else if(data<root->data) return search(root->left,data);
    else return search(root->right,data);
}


//go as left as possible to find the minimum value in the BST
node* findmin(node* root){
    if(root == NULL) return NULL;
    else if(root->left != NULL) return findmin(root->left);
    return root;
}   
//go as right as possible to find the maximum value in the BST
node* findmax(node* root){
    if(root == NULL) return NULL;
    else if(root->right != NULL) return findmax(root->right);
    return root;
}                

node* deleteNode(node* root, int data){
    if(root == NULL){
        cout<<"Element not found"<<endl;
        return root;
    }
    else if(data < root->data) root->left = deleteNode(root->left,data);
    else if(data > root->data) root->right = deleteNode(root->right,data);
    else{
        //data found
        //case1 - no child
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //case2 - one child
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //case 3 - two children
        else{
            node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
            return root;
        }
    }
}

//traversals
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,60);
    root = insert(root,80);

    cout<<"In-order traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Pre-order traversal: ";
    preorder(root); 
    cout<<endl;
    cout<<"Post-order traversal: ";
    postorder(root);
    cout<<endl;

    search(root,40);
    search(root,90);

    root = deleteNode(root,20);
    cout<<"In-order traversal after deleting 20: ";
    inorder(root);
    cout<<endl;

    root = deleteNode(root,30);
    cout<<"In-order traversal after deleting 30: ";
    inorder(root);
    cout<<endl;

    root = deleteNode(root,50);
    cout<<"In-order traversal after deleting 50: ";
    inorder(root);
    cout<<endl;

    return 0;
}
