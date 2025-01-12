#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct node* head;

void reverseList(struct node* head);


int main (void)
{
    head = (struct node*) malloc(sizeof(struct node));

    for (int i = 1; i < 3; i++)
    {
        add_to_end(i,head);
    }

    printList(head);

    reverseList(head);

    printList(head);

    free_list(head);   
}


void reverseList(struct node* Head)
{
    struct node* temp_3 = Head->next->next;
    struct node* temp_2 = Head->next;
    struct node* temp_1 = Head;

    temp_1->next = NULL;
    while (temp_3->next != NULL)
    {
        temp_2->next = temp_1;
        temp_3->next = temp_2;
        temp_1 = temp_2;
        temp_2 = temp_3;
        temp_3 = temp_3->next;
        
    }
    temp_3->next = temp_2;
    temp_2->next = temp_1;
    head = temp_3;
    
}