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

int main(void)
{
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head->value=31;
	add_to_end(0,head);
	add_to_end(1,head);
	add_to_end(2,head);
	add_to_end(3,head);
	add_to_end(4,head);
	add_to_end(7,head);
	add_to_end(3,head);
	add_to_end(1,head);
	add_to_end(400000,head);
	add_to_end(3,head);
	add_to_end(6,head);
	add_to_end(7,head);
	add_to_end(1,head);
	struct node* temp_2=head;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	temp_2=temp_2->next;
	// printf("%i\n",temp_2->value);
	struct node* temp=head;
	struct node* temp2=head;
	while (temp!=NULL)
	{
		printf("%i ",temp->value);
		temp= temp->next;
	}
	printf("\n");

	removeNode(head,temp_2);
	while (temp2!=NULL)
	{
		printf("%i  ",temp2->value);
		temp2= temp2->next;
	}
	printf("\n");
	free_list(head);
}

void removeDuplicate(struct node* head)
{
	int nums [100000];
	struct node* temp=head;
	
	while (temp != NULL)
	{
		nums[temp->value]++;
		temp=temp->next;
	}

	struct node* temp_2 = head;

	while (temp_2 != NULL)
	{
		if(nums[temp_2->next->value]!=1)
		{
			temp_2->next=temp_2->next->next;
			temp_2->next->next=NULL;
		}
	}
	

}


void removeNode(struct node* head,struct node* remove)
{
	struct node* temp = head;
	if (temp = remove)
	{
		remove->next=NULL;
		// free(remove);
	}

	while (temp != NULL)
	{
		if(temp->next = remove)
		{
			temp->next=remove->next;
			remove->next=NULL;
			// free(remove);
			break;
		}

		if(remove->next=NULL)
		{
			temp->next=NULL;
			// free(remove);
			break;
		}
		temp=temp->next;
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
