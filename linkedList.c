#include<stdio.h>
#include<stdlib.h>

void insert_item_after_element(int);
void search_element_in_list(int);
void delete_element(int);
void insert_item_before_element(int);
void insert_node_at_last(int);
void print_list(void);

struct list{
int data;
struct list *next;
};

struct list *head;
int main()
{
	int choice, data;
	head = (struct list *)malloc(sizeof(struct list));
	head->next = NULL;
	
	while(1)
	{
		printf("\n Please enter your choice \n");
		puts(" 1: Insert at last of list \n");
		puts(" 2: Search item in the list \n");
		puts(" 3: Print element in the list \n");
		puts(" 4: Insert item after element\n");
		puts(" 5: Insert item before element\n");
		puts(" 6: Delete element from the list\n");
		puts(" -1: Enter -1 to exit\n");
		scanf("%d",&choice);

		if( choice == -1 ) 
			break;
		switch(choice)
		{
			case 1:
				puts("Enter the element \n");
				scanf("%d",&data);
				insert_node_at_last(data);
				break;

			case 2:
				puts("Enter the element to search in the list\n");
				scanf("%d",&data);
				search_element_in_list(data);
				break;

			case 3:
				print_list();
				break;
			case 4:
				puts("Enter item after which to add another item\n");
				scanf("%d",&data);
				insert_item_after_element(data);
				break;

			case 5:
				puts("Enter the item before which to add another item\n");
				scanf("%d", &data);
				insert_item_before_element(data);
				break;
			case 6:
				puts("Enter the element to delete from the list\n");
				scanf("%d", &data);
				delete_element(data);
				break;
		}
	}

	return 0;
}

void insert_node_at_last(int data)
{
	struct list *node;
	node = head;
	while(node->next != NULL)
		node = node->next; 
	node->next = (struct list *)malloc(sizeof(struct list));
	node = node->next;
	node->data = data;
	node->next = NULL;
}

void insert_item_after_element(int data)
{
	int flag = 0;
	struct list *node, *tmp;
	node = head;
	node = node->next;
	while(node != NULL)
	{
		if( node->data == data )
		{
			flag = 1;
			tmp = node->next;	
			node->next = (struct list *)malloc(sizeof(struct list));
			printf("Enter the data to be added to list after %d\n", data);
			scanf("%d", &data);
			node = node->next;
			node->data = data;
			node->next = tmp;
		}
		node = node->next;
	}
	if( flag == 0 )
		printf("Element %d is not present in the list\n", data);
}

void insert_item_before_element(int data)
{
	int flag = 0;
	struct list *prev, *node, *next;
	node = head;	
	prev = node;
	node = node->next;

	while( node != NULL )
	{
		if( node->data == data )
		{
			flag = 1;
			next = node;
			prev->next = (struct list *)malloc(sizeof(struct list));
			printf("Enter the data to be inserted before %d\n", data);
			scanf("%d", &data);
			node = prev->next;
			node->data = data;
			node->next = next; 
		}	
		prev = node;
		node = node->next;	
	}
	if( flag == 0 )
		printf("Input element %d is not present in the list\n", data);
}

void delete_element(int data)
{
	int found = 0;
	struct list * node, *prev, *next;
	node = head;
	prev = node;
	node = node->next;

	while( node != NULL )
	{
		if( node->data == data )
		{
			next = node->next;	
			prev->next = next;
			free(node);
		}
		prev = node;
		node = node->next;
	}
	if( found == 0 )
		puts("Given element is not present in the list\n");
}

void search_element_in_list(int item)
{
	int found = 0;
	struct list *node;
	node = head;
	while(node != NULL)
	{
		if( node->data = item )
		{
			printf("Item is present in the list \n");
			return;
		}
		node = node->next;
	}
	if( found == 0 )
		printf("%d is not present in the list\n", item);
}

void print_list(void)
{
	int i = 0;
	struct list *node;

	node = head;
	node = node->next;
	if( node == NULL)
		printf(" List is empty, nothing to print \n");

	while(node != NULL)
	{
		printf(" Element at %d = %d \n", i++, node->data);
		node = node->next;
	}
}
