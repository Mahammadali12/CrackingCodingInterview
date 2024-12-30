#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node* next;
	int value;
};

void free_list(struct node* head);
void add_to_end(int v,struct node* head);

int main(void)
{
	struct node* head = (struct node*) malloc(sizeof(struct node));
	add_to_end(00,head);
	add_to_end(01,head);
	add_to_end(02,head);
	add_to_end(03,head);
	add_to_end(04,head);
	free_list(head);
}


void free_list(struct node* head)
{
	if(head == NULL)
		return ;
	free_list(head->next);
	free(head);
}


void add_to_end(int v,struct node* head)
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = (struct node*) malloc(sizeof(struct node)); 
	temp=temp->next;
	temp->value=v;
}
