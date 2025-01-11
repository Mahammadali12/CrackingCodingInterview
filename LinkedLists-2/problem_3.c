#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct node* head;
void deleteMidNode(struct node* mid);

int main (void)
{
    head = (struct node*) malloc(sizeof(struct node));

    for (int i = 1; i < 10; i++)
    {
        add_to_end(i,head);
    }

    printList(head);
    struct node * temp=head;
    for (int i = 0; i < 5; i++)
    {
        temp=temp->next;
    }
    

    deleteMidNode(temp);

    printList(head);

    free_list(head);
}

void deleteMidNode(struct node* mid)
{
    struct node* mid_next = mid->next;

    mid->next =  mid_next->next;
    mid->value = mid_next->value;
}