#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *fhead, *shead;
void addNode(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    newnode->next = NULL;
    // printf("Enter the data : ");
    scanf("%d", &newnode->data);
    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void merge(struct node **first, struct node *second)
{
    if (*first == NULL)
    {
        *first = second;
        return;
    }
    struct node *temp;
    temp = *first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = second;
}
int main()
{
    printf("\nEnter elements for first list\t:\t");
    addNode(&fhead);
    addNode(&fhead);

    printf("\nEnter elements for swcond list\t:\t");
    addNode(&shead);
    addNode(&shead);

    printf("\nFirst list\t:\t");
    display(fhead);

    printf("\nSecond list\t:\t");
    display(shead);

    merge(&fhead, shead);

    printf("\nMerged list\t:\t");
    display(fhead);
    return 0;
}