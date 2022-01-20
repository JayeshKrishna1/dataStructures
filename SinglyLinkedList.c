#include<stdio.h>
#include<stdlib.h>
struct  node
    {
        int data;
        struct  node *next;
        
    };
void Insertatbegin(struct node **head_ref){
    struct node*newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&data);
    newnode->data = data;
    newnode->next = *head_ref;
    *head_ref = newnode;
}
void Insertatend(struct node **head_ref){
    struct node*newnode,*temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&data);
    newnode->data = data;
    newnode->next = 0;
    temp = *head_ref;
    while(temp->next !=0){
        temp = temp->next;
    }
    temp->next = newnode;
    temp = newnode;
}
void Insertatposition(struct node **head_ref){
    struct node*newnode,*temp;
    int data,pos,i=1;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&data);
    newnode->data = data;
    printf("enter a position \n");
    scanf("%d",&pos);
    temp = *head_ref;
    while(i<pos){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void print(struct node **head_ref){
    struct node *temp = *head_ref;
    int count = 0;
    printf("the linked list data are :\n");
    while(temp !=0){
        printf("%d \t",temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
    printf("the number of node in linked list is %d \n",count);
}
void Deleteatend(struct node **head_ref){
    struct node *temp = *head_ref,*prev = *head_ref;
    while(temp->next !=0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == *head_ref){
        *head_ref = 0;
    }
    else{
    prev->next = 0;
    free(temp);
    }
} 
void Deleteatbegin(struct node **head_ref){
    struct node *temp = *head_ref;
    if(*head_ref == 0){
        printf("the linked list is empty");
    }
    else{
        *head_ref = temp->next;
        free(temp);
    }
}   
void Deleteatposition(struct node **head_ref){
    struct node *temp = *head_ref,*prev = *head_ref;
    int pos,i=1;
    printf("enter a position\n");
    scanf("%d",&pos);
    while(i<pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}
void Reverse(struct node **head_ref){
    struct node *current = *head_ref,
    *prev = 0,
    *next = *head_ref;
    while(next != 0){
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void Search(struct node **head_ref){
    struct node *temp = *head_ref;
    int num,flag = 0;
    printf("enter the number to be searched \n");
    scanf("%d",&num);
    while(temp!=0){
        if(num == temp->data){
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 0){
        printf("the number is not present\n");
    }
    else{
        printf("the number is present\n");
    }
}
void sort(struct node **head_ref){
    struct node *temp = *head_ref,
    *next = temp->next;
    int count = 0,swap;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    for(int i =1;i<count;i++){
        int flag = 0;
        temp = *head_ref;
        next = temp->next;
        for(int j = 1;j<=count-i;j++){
            if(temp->data > next->data){
                swap = temp->data;
                temp->data = next->data;
                next->data = swap;
                flag = 1;
            }
            temp = next;
            next = next->next;
        }
        
        if(flag == 0){
            printf("the list is sorted");
            break;
        }
    }
}
void main(){
    
    struct node *head,*newnode,*temp;
    head = 0;
    int choice;
    while (choice)
    {
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head == 0){
    head = temp = newnode;
    }
    else{
        temp->next =newnode;
        temp = newnode;
    }
    printf("enter the choice \n");
    scanf("%d",&choice);
    }
     print(&head);
    printf("INSERTION AT END \n");
    Insertatend(&head);
    print(&head);
    printf("INSERTION AT BEGIN \n"); 
    Insertatbegin(&head);
    print(&head);
    printf("INSERTION AT A PARTICULAR POSITION \n");
    Insertatposition(&head);
    print(&head);
    printf("DELETION AT END \n");
    Deleteatend(&head);
    print(&head);
    printf("DELETION AT BEGIN \n");
    Deleteatbegin(&head);
    print(&head);
    printf("DELETION AT A PARTICULAR POSITION \n");
    Deleteatposition(&head);
    print(&head);
    printf("REVERSED LIST IS \n");
    Reverse(&head);
    print(&head);
    printf("SEARCHING\n");
    Search(&head);
    printf("SORTING\n");
    sort(&head);
    print(&head);
}