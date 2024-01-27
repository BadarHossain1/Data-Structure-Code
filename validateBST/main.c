#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;

};
struct node *binarytree(){
    struct node *newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Give the data for the node(-1 for stopping or for nothing)\n");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode ->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    printf("Enter data for left child of %d:\n", x);
    newnode->left = binarytree();
    printf("Enter data for right child of %d:\n", x);
    newnode->right = binarytree();
    return newnode;
}
void displayinorder(struct node*root){
    if(root == NULL){
        return;
    }

    displayinorder(root->left);
    printf("%d ",root->data);
    displayinorder(root->right);



}
bool isBST(struct node* root, struct node *min, struct node *max){
    if(root == NULL){
        return true;
    }
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data>= max->data){
        return false;
    }

    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid = isBST(root->right, root, max);
    return leftvalid && rightvalid;

}


int main() {
    int n;
    struct node *root;
    root = binarytree();
    displayinorder(root);
    if(isBST(root,0,0)){
        printf("The tree is a BST");
    }
    else{
        printf("The tree is not a bst");
    }
    return 0;
}



