#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt = 0;
typedef struct node 
{
	char title[20];
	int year;
	struct node* next;
} BOOK;
BOOK* create_node(BOOK*);
BOOK* add_node(BOOK*);
BOOK* delete_head(BOOK*);
BOOK* shift_list(BOOK*);
BOOK* print_list(BOOK*);
BOOK* print_list_min(BOOK*);
BOOK* delete_list(BOOK*);

BOOK* create_node(BOOK* pointer) 
{
	char delimiter[] = ";";
	char ttl[20];
	char x;
	BOOK* temp = (BOOK*)malloc(sizeof(BOOK));
	printf("Enter the YEAR of new book\n");
	scanf_s("%d", &temp->year);
	printf("Enter the TITLE of new book(title;)\n");
	int a = 0;
	x = getchar();
	while (x != delimiter[0])
	{
		ttl[a] = x;
		a++;
		x = getchar();
	}
	ttl[a] = '\0';
	strcpy_s(temp->title, ttl);
	temp->next = temp;
	cnt++;
	return temp;
}
BOOK* add_node(BOOK* pointer) 
{
	char delimiter[] = ";";
	char x;
	char ttl[20];
	BOOK* save_head = pointer;
	BOOK* temp = (BOOK*)malloc(sizeof(BOOK));
	if (temp) 
	{
		printf("Enter the YEAR of the new book\n");
		scanf_s("%d", &temp->year);
		printf("Enter the TITLE of the new book(title;)\n");
		int a = 0;
		x = getchar();
		while (x != delimiter[0]) 
		{
			ttl[a] = x;
			a++;
			x = getchar();
		}
		ttl[a] = '\0';
		strcpy_s(temp->title, ttl);
		BOOK* p = pointer;
		for (int k = 1;k < cnt;k++) 
		{
			p = p->next;
		}
		BOOK* end = p;
		if ((temp->year) < (save_head->year))
		{
			temp->next = save_head;
			end->next = temp;
			cnt++;
			return temp;
		}
		else if (((temp->year) == (save_head->year)) && (strcmp(temp->title, save_head->title) == -1)) 
		{
			temp->next = save_head;
			end->next = temp;
			cnt++;
			return temp;
		}
		BOOK* remember = pointer;
		for (int i = 1;i <= cnt;i++) 
		{
			if ((temp->year) > (pointer->year)) 
			{
				remember = pointer;
				pointer = pointer->next;
			}
			else if ((temp->year) == (pointer->year)) 
			{
				int cmp = strcmp(temp->title, pointer->title);
				switch (cmp) 
{
				case 1:
				{
					BOOK* ptr = pointer->next->next;
					pointer->next = temp;
					temp->next = ptr;
					cnt++;
					return save_head;
					break;
				}
				case -1:
				{
					remember->next = temp;
					temp->next = pointer;
					cnt++;
					return save_head;
					break;
				}
				case 0: 
				{
					BOOK* ptr = pointer->next->next;
					pointer->next = temp;
					temp->next = ptr;
					cnt++;
					return save_head;
					break;
				}
				}
			}
			if ((temp->year) < (pointer->year)) 
			{
				break;
			}
		}
		cnt++;
		temp->next = pointer;
		remember->next = temp;
		return save_head;
	}
	else 
	{
		puts("ERROR");
		return save_head;
	}
}
BOOK* delete_head(BOOK* pointer) 
{
	BOOK* new_head = pointer->next;
	BOOK* p = pointer;
	for (int i = 1; i < cnt; i++)
	{
		p = p->next;
	}
	BOOK* end = p;
	end->next = new_head;
	free(pointer);
	cnt--;
	return new_head;
	
	printf("\n Your head of the list has been removed\n");
	
}
BOOK* shift_list(BOOK* pointer) 
{
	int k;
	printf("enter k\n");
	scanf_s("%d", &k);
	BOOK* p = pointer;
	for (int i = 1;i <= k;i++) 
	{
		p = p->next;
	}
	BOOK* new_head = p;
	return new_head;
	printf("\n Your list has been shifted by %d elements\n", k);
}
BOOK* print_list(BOOK* pointer) 
{
	if (cnt == 0) 
	{
		printf("The list is empty.\n");
	}
	else
	{
		printf("\n*----------------------------------------------------*\n");
		BOOK* p = pointer;
		for (int j = 1;j <= cnt;j++) 
		{
			for (int k = 0;k < strlen(p->title);k++) 
			{
				printf("%c", p->title[k]);
			}
			printf(", %d", p->year);
			p = p->next;
		}
		printf("\n\n*----------------------------------------------------*\n");
		printf("Your list has been printed\n");
	}
	return pointer;
}
BOOK* print_list_min(BOOK* pointer)
{
	if (cnt == 0) 
	{
		printf("The list is empty.\n");
	}
	else 
	{
		printf("\n*----------------------------------------------------*\n");
		BOOK* tmp;
		BOOK* p = pointer;
		int flag;
		BOOK* min = pointer;
		for (int i = 1;i <= cnt;i++) 
		{
			if ((pointer->year) < (min->year)) min = pointer;
			pointer = pointer->next;
		}
		BOOK* ptr = min;
		for (int j = 1;j <= cnt;j++) 
		{
			for (int k = 0;k < strlen(ptr->title);k++) 
			{
				printf("%c", ptr->title[k]);
			}
			printf(", %d", ptr->year);
			ptr = ptr->next;
		}
		printf("\n\n*----------------------------------------------------*\n");
		printf("Your list has been printed starting from the element with the earliest year of publishing:\n");
		
	}
	return pointer;
}
BOOK* delete_list(BOOK* pointer) 
{
	if (cnt == 0) return 0;
	else 
	{
		BOOK* p = pointer;
		BOOK* next;
		for (int i = 1;i <= cnt;i++) 
		{
			next = p->next;
			free(p);
			p = next;
		}
	}
	cnt = 0;
	return 0;
	printf("\nYour list has been deleted");
}
int main() 
{
	BOOK *head;
   head = NULL;
	int num;
	printf("1- to create the first element\n2- to add the element considering its year\n");
	printf("3- to delete the head of the list\n4- to shift list by k elements\n");
	printf("5- to print all list\n6- to print list from minimal element\n7- to delete all list\n0- to exit\n");
	while (1) 
	{
		printf("Enter the number of your command(1-7): \n");
		scanf_s("%d", &num);
	  switch (num) 
	  {
		  case 1: 
		 {
			head = create_node(head);
			break;
		 }
		  case 2: 
		 {
			head = add_node(head);
			break;
		 }
		  case 3: 
		 {
			head = delete_head(head);
			break;
		 }
		  case 4: 
		 {
			head = shift_list(head);
			break;
		 }
		  case 5: 
		 {
			print_list(head);
			break;
		 }
		 case 6: 
		 {
			print_list_min(head);
			break;
		 }
		 case 7:
		 {
			head = delete_list(head);
			break;
		 }
		 case 0: 
		 {
			exit(0);
			break;
		 }
		default: exit(0);
	  }
	}
	return 0;
}

