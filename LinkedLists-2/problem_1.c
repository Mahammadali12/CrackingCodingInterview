#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node* next;
	int value;
};


void removeNode(struct node* head,struct node* remove);
void free_list(struct node* head);
void add_to_end(int v,struct node* head);
void removeDuplicate(struct node* head_node);

struct node* head;
int nums [1000];
int main(void)
{
	head = (struct node*) malloc(sizeof(struct node));
	head->value=310;
	add_to_end(1,head);
	add_to_end(7,head);
	add_to_end(310,head);
	add_to_end(400,head);
	add_to_end(7,head);
	add_to_end(2,head);
	add_to_end(3,head);
	add_to_end(400,head);
	add_to_end(7,head);
	add_to_end(4,head);
	add_to_end(7,head);
	add_to_end(3,head);
	add_to_end(7,head);
	add_to_end(400,head);
	add_to_end(3,head);
	add_to_end(3,head);
	add_to_end(1,head);
	add_to_end(7,head);
	add_to_end(400,head);
	add_to_end(3,head);
	add_to_end(400,head);
	add_to_end(3,head);
	add_to_end(7,head);
	add_to_end(6,head);
	add_to_end(3,head);
	add_to_end(1,head);

	for (int i = 0; i < 5; i++)
	{
		add_to_end(0,head);
	}
	for (int i = 0; i < 5; i++)
	{
		add_to_end(3,head);
	}
	for (int i = 0; i < 5; i++)
	{
		add_to_end(5,head);
	}
	
	
	struct node* temp=head;
	while (temp!=NULL)
	{
		printf("%i ",temp->value);
		temp = temp->next;
	}
	printf("\n");

	removeDuplicate(head);
	struct node* temp2=head;
	
	while (temp2!=NULL)
	{
		printf("%i ",temp2->value);
		temp2 = temp2->next;
	}
	printf("\n");
	free_list(head);
}

void removeDuplicate(struct node* head_node)
{
	struct node* temp=head_node;
	
	while (temp != NULL)
	{
		nums[temp->value]++;
		temp=temp->next;
	}

	temp = head_node;
	struct node* remove;
	while (temp != NULL)
	{
		if(nums[temp->value]>1)
		{
			nums[temp->value]--;
			remove = temp;
			temp = temp->next;
			removeNode(head_node,remove);
		}
		else
		temp=temp->next;
	}
}

void removeNode(struct node* head_node,struct node* remove)
{
	struct node* temp_head = head;
	if (head == remove)
	{
		head = head->next;
		remove->next=NULL;
		free(remove);
		return;	
	}

	if(remove->next == NULL)
	{
		while (temp_head->next != remove)
		{
			temp_head = temp_head->next;
		}
		
		temp_head->next=NULL;
		free(remove);
		return;
	}

	while (temp_head != NULL)
	{
		if(temp_head->next == remove)
		{
			temp_head->next=remove->next;
			remove->next=NULL;
			free(remove);
			break;
		}
		else
		temp_head=temp_head->next;
	}
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
