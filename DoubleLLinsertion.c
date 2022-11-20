#include <stdio.h>
#include <stdlib.h>
// structure for the node and its size.
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// insertion at beginning...
void insertHead(struct node **head, int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    // here is now second node
    newNode->next = (*head);
    (*head) = newNode;
}
// insertion in between...
void insertBetween(struct node **head, int data, int index)
{
    struct node *newNode, *temp = (*head);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next->prev = newNode;
}
// insertion at tail ...
void insertTail(struct node **head, int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node *temp = (*head);
    // going to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // linking new node with prev last node
    newNode->prev = temp;
    temp->next = newNode;
}
// deletion of nodes
void delete (struct node **head, int index)
{
    struct node *temp = (*head);
    int i = 0;
    while (i != index)
    {
        temp = temp->next;
        i++;
    }
    temp ->prev ->next = temp ->next ;
    temp ->next->prev = temp ->prev;
}

// display at forward direction
void display(struct node *head)
{
    struct node *temp = head;
    // traversing to last from first
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
// reverse the node and print it backward
void printBack(struct node *head)
{
    struct node *temp = head;
    // while loop for going to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // traversing back to first node while printing
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
}
// driver main
int main()
{
    // creating an empty node
    struct node *head = NULL;
    // calling function
    insertHead(&head, 10);
    insertTail(&head, 20);
    insertTail(&head, 40);
    insertTail(&head, 50);
    insertTail(&head, 60);
    insertBetween(&head, 30, 2);
    //before deletion
    display(head);
    //deleting a node (40)
    delete(&head , 3);
    display(head);
    // printBack(head);
    return 0;
}
