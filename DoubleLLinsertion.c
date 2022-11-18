#include <stdio.h>
#include<stdlib.h>
//structure for the node and its size.
struct node {
    int data ;
    struct node* next ;
    struct node* prev ;
};
//insertion at beginning...
void insertHead(struct node** head , int data){
    struct node * newNode ; 
    newNode =(struct node *)malloc(sizeof(struct node));
    newNode ->data = data ;
    newNode->prev = NULL;
    //here is now second node
    newNode ->next = (*head);
    (*head) = newNode;
}
//insertion at tail ...
void insertTail(struct node ** head , int data){
    struct node * newNode ;
    newNode = (struct node*)malloc (sizeof(struct node));
    newNode ->data = data ;
    newNode->next = NULL;
    struct node * temp =(*head);
    //going to last node
    while (temp->next !=NULL)
    {
        temp = temp ->next;
    }
    //linking new node with prev last node
    newNode->prev = temp ;
    temp ->next = newNode ;
}

//display at forward direction
void display(struct node *head){
    struct node *temp = head;
    //traversing to last from first
    while (temp != NULL)
    {
        printf("%d->", temp ->data);
        temp = temp ->next ;
    }
    printf("NULL");
}
//reverse the node and print it backward
void printBack(struct node * head){
    struct node * temp = head ;
    //while loop for going to last node
    while(temp ->next  !=NULL){
        temp = temp ->next ;
    }

    //traversing back to first node while printing
    while(temp  != NULL){
        printf("%d ->" , temp ->data );
        temp = temp ->prev ;
    }
    printf("NULL");
}
//driver main
int main(){
    // creating an empty node
    struct node *head  =NULL;
    //calling function
    insertHead(&head , 10);
    insertTail(&head , 20);
    insertTail(&head , 30);
    insertTail(&head , 40);
    insertTail(&head , 50);
    // display(head);
    printBack(head);
    return 0;
}