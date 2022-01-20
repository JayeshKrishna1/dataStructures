#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void create(struct node **head_ref){
    struct node *temp = *head_ref,*newnode; 
    int choice;
    while(choice){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    if(*head_ref == 0){
        *head_ref = temp = newnode;
    }
    else{
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    printf("enter a choice \n");
    scanf("%d",&choice);
    }
}
void Insertatend(struct node **head_ref){
    struct node *temp = *head_ref,*newnode; 
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void Insertatbegin(struct node **head_ref){
    struct node *temp = *head_ref,*newnode; 
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    if(*head_ref == 0){
        head = newnode;
    }
    else{
        newnode->next = *head_ref;
        temp->prev = newnode;
        *head_ref = newnode;
    }
}
void Insertatpos(struct node **head_ref){
    struct node *temp = *head_ref,*newnode,*prev;
    int pos,i=1; 
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    printf("enter a position\n");
    scanf("%d",&pos);
    while (i<pos)
    {
        temp = temp->next;
        i++;
    }
    prev = temp->prev;
    newnode->next = temp;
    newnode->prev = prev;
    temp->prev = newnode;
    prev->next = newnode;

}
void Insertafterpos(struct node **head_ref){
    struct node *temp = *head_ref,*newnode,*next;
    int pos,i=1; 
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->prev = newnode->next = 0;
    printf("enter a position\n");
    scanf("%d",&pos);
    while (i<pos)
    {
        temp = temp->next;
        i++;
    }
    next = temp->next;
    newnode->next = next;
    next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

} 
void Deleteatend(struct node **head_ref){
    struct node *temp=*head_ref;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp = temp->prev;
    temp->next = 0;
}
void Deleteatbegin(struct node **head_ref){
    struct node *temp = *head_ref;
    *head_ref = temp->next;
    temp = temp->next;
    temp->prev = 0;
}  
void Deleteatposition(struct node **head_ref){
     struct node *temp = *head_ref,*prev,*next;
     int pos,i=1;
     printf("enter a position\n");
     scanf("%d",&pos);
     while(i<pos){
         temp = temp->next;
         i++;
     }
     prev = temp->prev;
     next = temp->next;
     prev->next = next;
     next->prev = prev;
}
void Reverse(struct node **head_ref){
    struct node *current = *head_ref,
    *next = *head_ref,
    *prev = 0,*swap;
    while(next!=0){
        next = current->next;
        swap = current->prev;
        current->prev = current->next;
        current->next = swap;
        prev = current;
        current = next;

    }
    *head_ref = prev;
}
void print(struct node **head_ref){
    struct node *temp;
    temp = *head_ref;
    while(temp != 0){
        printf("%d \t",temp->data);
        temp = temp->next;        
    }
    printf("\n");
}
void main(){
    create(&head);
    print(&head); 
    Insertatend(&head);
    print(&head);
    Insertatbegin(&head);
    print(&head);
    Insertatpos(&head);
    print(&head);
    Insertafterpos(&head);
    print(&head);
    Deleteatend(&head);
    print(&head);
    Deleteatbegin(&head);
    print(&head);
    Deleteatposition(&head);
    print(&head);
    Reverse(&head);
    print(&head);
}

