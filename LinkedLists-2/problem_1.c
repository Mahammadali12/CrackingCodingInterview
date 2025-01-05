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
	add_to_end(2,head);
	add_to_end(3,head);
	add_to_end(4,head);
	add_to_end(7,head);
	add_to_end(3,head);
	add_to_end(1,head);
	add_to_end(400,head);
	add_to_end(3,head);
	add_to_end(6,head);
	add_to_end(7,head);
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
	
	// struct node* temp_1=head;
	// struct node* temp_2=head;
	// struct node* temp_3=head;
	
	// for (int i = 0; i < 9 ; i++)
	// {
	// 	temp_2=temp_2->next;
	// }

	// for (int i = 0; i < 13 ; i++)
	// {
	// 	temp_3=temp_3->next;
	// }
	
	struct node* temp=head;
	while (temp!=NULL)
	{
		printf("%i ",temp->value);
		temp = temp->next;
	}
	printf("\n");

	// removeNode(head,temp_1);
	// removeNode(head,temp_2);
	// removeNode(head,temp_3);
		printf("HIII");
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
		printf("HIII");
	
	while (temp != NULL)
	{
		nums[temp->value]++;
		temp=temp->next;
	}

	temp = head_node;
	struct node* remove;
	while (temp != NULL)
	{
		if(nums[temp->value]>0)
		{
			nums[temp->value]--;
			removeNode(head_node,temp);
		}
		temp=temp->next;
	}
}

void removeNode(struct node* head_node,struct node* remove)
{
	if (head == remove)
	{
		head = head->next;
		remove->next=NULL;
		free(remove);
		return;	
	}

	if(remove->next == NULL)
	{
		while (head_node->next != remove)
		{
			head_node = head_node->next;
			remove->next = NULL;
		}
		
		head_node->next=NULL;
		free(remove);
		return;
	}

	while (head_node != NULL)
	{
		if(head_node->next == remove)
		{
			head_node->next=remove->next;
			remove->next=NULL;
			free(remove);
			break;
		}
		head_node=head_node->next;
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
