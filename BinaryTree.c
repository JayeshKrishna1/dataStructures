#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* create(){
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data (-1 for leaf)\n");
    scanf("%d",&data);
    if(data == -1){
        return 0;
    }
    else{
        newnode->data = data;
        printf("left child of %d\n",data);
        newnode->left = create();
        printf("right child of %d\n",data);
        newnode->right = create();
        return newnode;
    }
} 
void preorder(struct node *root_ref){
    if(root_ref == 0){
        return;
    }
    else{
        printf("%d",root_ref->data);
        preorder(root_ref->left);
        preorder(root_ref->right);
    }
}
void inorder(struct node *root_ref){
    if(root_ref == 0){
        return;
    }
    else{
        inorder(root_ref->left);
        printf("%d ",root_ref->data);
        inorder(root_ref->right);
    }
}
void postorder(struct node *root_ref){
    if(root_ref == 0){
        return;
    }
    else{
        postorder(root_ref->left);
        postorder(root_ref->right);
        printf("%d",root_ref->data);
    }
}
void main(){
    struct node *root;
    root = create();
    // preorder ===> root left right
    // inorder ====> left root right
    // postorder ==> left right root
    printf("preoder traversal is \n");
    preorder(root);
    printf("\n inorder traversal is \n");
    inorder(root);
    printf("\n postoder traversal is \n");
    postorder(root);
}