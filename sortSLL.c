#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addNode(struct node **head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortLinkedList(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    struct node *head = NULL;

    addNode(&head, 30);
    addNode(&head, 10);
    addNode(&head, 40);
    addNode(&head, 20);

    printf("Original Linked List:\n");
    display(head);

    sortLinkedList(head);

    printf("Sorted Linked List:\n");
    display(head);

    return 0;
}
