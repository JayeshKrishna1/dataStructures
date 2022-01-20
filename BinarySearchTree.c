#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *create(int data){
    struct node *newnode;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = 0;
    return newnode;
}
struct node *insert(struct node *root,int data){
    if(root == 0){
        root =  create(data);
    }
    else{
        if(data < root->data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
    }
    return root;
}
void preorder(struct node *root_ref){
    if(root_ref == 0){
        return;
    }
    else{
        printf("%d ",root_ref->data);
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
        printf("%d ",root_ref->data);
    }
}
struct node* min(struct node *root){
    if(root == 0){
        return root;
    }
    struct node* current = root;
    while(current->left != 0){
        current = current->left;
    }
    return current;
}
struct node* delete(struct node*root,int data){
    if (root == 0)
    {
        return root;
    }
    else if(data < root->data){
        root->left = delete(root->left,data);
    }
    else if(data > root->data){
        root->right = delete(root->right,data);
    }
    else{
        if(root->left == 0 && root->right == 0){
            free(root);
            root = 0;
            
        }
        else if(root->left == 0){
            struct node *temp = root->right;
            root->data = temp->data;
            free(temp);
            
        }
        else if(root->right == 0){
            struct node *temp = root->left;
            root->data = temp->data;
            free(temp);
               
        }
        else{
            struct node *temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
            
        }
    }
    return root;
}
struct node* max(struct node *root){
    if(root == 0){
        return root;
    }
    struct node* current = root;
    while(current->right != 0){
        current = current->right;
    }
    return current;
}
void main(){
    struct node *root;
    root = insert(root,15);
    root = insert(root,12);
    root = insert(root,25);
    root = insert(root,30);
    root = insert(root,22);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = delete(root,15);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}