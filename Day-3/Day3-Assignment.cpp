#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void insertion_begin();
void insertion_end();
void deletion_begin();
void deletion_end();
void display();

int main()
{
	int choice;
	char c;
	do
	{
		cout << "\t\t\t******************************\n";
		cout << "\n\t\t\t\t------Menu-----\n";
		cout << "\n\t\t\t******************************\n";
		cout << "\n\t1.Insertion at beginning";
		cout << "\n\t2.Insertion at ending";
		cout << "\n\t3.Deletion at beginning";
		cout << "\n\t4.Deletion at ending";
		cout << "\n\t5.Display";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		insertion_begin();
		break;
		case 2:
		insertion_end();
		break;
		case 3:
		deletion_begin();
		break;
		case 4:
		deletion_end();
		break;
		case 5:
		display();
		break;
		case 6:
		default:
			cout << "\nEnter a valid choice!";
		}
		cout << "\nDo you want to continue?(Y/N): ";
		cin >> c;
	} while (c == 'Y' || c == 'y');
	return 0;
}

void insertion_begin()
{
	int item;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	cout << "\nEnter an element:";
	cin >> item;
	ptr->data = item;
	if (head==NULL)
	{
		head=ptr;
		head->next = NULL;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

void insertion_end()
{
	int item;
	struct node *ptr,*temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	cout << "\nEnter an element:";
	cin >> item;
	ptr->data = item;
	temp=head;
	if (head == NULL)
	{
        head=ptr;
		head->next = NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
	}
}

void deletion_begin()
{
	struct node *ptr;
	if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		free(ptr);
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
	}
}

void deletion_end()
{
	struct node *ptr,*ptr1;
	if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		free(ptr);
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
	}
}

void display()
{
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        cout << "\nNothing to print";  
    }     
    else  
    {  
        cout << "\nThe values in list are: \n";   
        while(ptr!=NULL)  
        {  
            cout << ptr->data <<"\n";   
            ptr=ptr->next;  
        }  
    }              
}
