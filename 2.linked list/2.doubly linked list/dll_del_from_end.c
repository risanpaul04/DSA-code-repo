#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head, *temp, *newnode;

void dll_create(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->prev = NULL;
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        if(head!=NULL)
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        else{
            head = newnode;
            temp = newnode;
        }
    }
}

void display()
{
    temp = head;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            printf("[%d] <=> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("list empty !");
    }
}

//deletion using 1 pointer only

void del_from_end()
{
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// deletion using 2 pointers

// void del_from_end()
// {
//     struct node *ptr1, *ptr2;
//     ptr1 = head;
//     ptr2 = ptr1->next;
//     while(ptr2->next!=NULL)
//     {
//         ptr1 = ptr2;
//         ptr2 = ptr2->next;
//     }
//     ptr1->next = NULL;
//     free(ptr2);
// }

int main()
{
    int i, n;
    printf("No. of nodes to be created: ");
    scanf("%d", &n);
    dll_create(n);
    printf("\nThe given list:\n");
    display();
    del_from_end();
    printf("List after deleting the last node:\n");
    display();
    return 0;
}