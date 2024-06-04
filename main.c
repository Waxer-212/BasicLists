#include <stdio.h>
#include <stdlib.h>

typedef int data;

struct node{
    data val;
    struct node* next;
    struct node* prev;};

typedef struct node Node;

void addAtBeginning(Node** head, data val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void addAtPos(Node** head, int pos, data val)
{
    Node* headcopy = *head;
    int p = 0;

    while(headcopy!=NULL && p+1 != pos )
    {
        headcopy = headcopy->next;
        p++;
    }

    if(p == 0 || *head == NULL)
        addAtBeginning(&*head, val);
    else
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(p+1 == pos && headcopy->next != NULL)
        {
                newNode->next = headcopy->next;
                (headcopy->next)->prev = newNode;
                headcopy->next = newNode;
                newNode->prev = headcopy;
        }
        else if(p+1 == pos && headcopy->next == NULL)
        {
            newNode->next = headcopy->next;
            headcopy->next = newNode;
            newNode->prev = headcopy;
        }
    }
}

void deleteElem(Node** head, data val)
{
    Node* headcopy = *head;

    while(headcopy != NULL && headcopy->val != val)
        headcopy = headcopy->next;

    if(headcopy->val == val)
    {
        (headcopy->next)->prev = headcopy->prev;
        (headcopy->prev)->next = headcopy ->next;
        free(headcopy);
    }
}

void printList(Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head= head->next;
    }
}

int main()
{
    Node* head = NULL;

    addAtBeginning(&head,7);
    addAtBeginning(&head,6);
    addAtBeginning(&head,1);
    addAtBeginning(&head,2);
    addAtBeginning(&head,3);

    addAtPos(&head,2, 9);
    addAtPos(&head,1, 23);
    addAtPos(&head,2, 11);
    addAtPos(&head,0, 78);

    printList(head);
    printf("\n");
    deleteElem(&head, 11);
    printList(head);

    return 0;
}

