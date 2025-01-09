#include <stdio.h>
#include <malloc.h>
#include "list.h"

int main()
{
    struct node* head = (struct node*) malloc(sizeof(struct node));

    for (int i = 0; i < 10; i++)
    {
        add_to_end(i,head);
    }

    int k=3;
    int j=0;
    struct node* temp = head;
    int length = listLength(head);
    while ((temp != NULL) && j!=(length-k) )
    {
        // printf("ASDAS");
        temp=temp->next;
        j++;
    }

    printf("%i\n",temp->value);
    free_list(head);
}
