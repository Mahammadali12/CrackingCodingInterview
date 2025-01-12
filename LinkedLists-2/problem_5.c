#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct node* head_1;
struct node* head_2;

void reverseList(struct node* head);


int main (void)
{
    head_1 = (struct node*) malloc(sizeof(struct node));
    head_1->value = 1;
    
    for (int i = 2; i < 4; i++)
    {
        add_to_end(i,head_1);
    }
    // printList(head_1);


    head_2 = (struct node*) malloc(sizeof(struct node));
    head_2->value = 3;

    for (int i = 5; i < 7; i++)
    {
        add_to_end(i,head_2);
    }


    int number_1;
    int buf=1;
    struct node* temp_1 = head_1;
    while (temp_1 != NULL)
    {
        number_1 = number_1 + temp_1->value*buf;
        buf *=10;
        temp_1 = temp_1->next;
    }


    int number_2;
    buf=1;
    struct node* temp = head_2;
    while (temp != NULL)
    {
        number_2 = number_2 + temp->value*buf;
        buf *=10;
        temp = temp->next;
    }


    printf("%i\n",number_1);
    printf("%i\n",number_2);
    
    printf("%i + %i\n",number_1,number_2);
    
    printList(head_1);
    printList(head_2);

    free_list(head_1);   
    free_list(head_2);   
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
    // head = temp_3;
    
}