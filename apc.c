#include "apc.h"

//validation of command line arguments
int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf(CLR_RED
               "Invalid number of arguments\n"
               CLR_RESET);

        printf("Use: ./apc -help\n");

        return FAILURE;
    }

    char *opr1 = argv[1];
    char *oper = argv[2];
    char *opr2 = argv[3];

    for(int i = 0; opr1[i] != '\0'; i++)
    {
        if(!isdigit(opr1[i]))
        {
            printf(CLR_RED
                   "Invalid operand 1\n"
                   CLR_RESET);

            return FAILURE;
        }
    }

    if(oper[0] != '+' &&
       oper[0] != '-' &&
       oper[0] != 'x' &&
       oper[0] != 'X' &&
       oper[0] != '/')
    {
        printf(CLR_RED
               "Invalid operator\n"
               CLR_RESET);

        return FAILURE;
    }

    for(int i = 0; opr2[i] != '\0'; i++)
    {
        if(!isdigit(opr2[i]))
        {
            printf(CLR_RED
                   "Invalid operand 2\n"
                   CLR_RESET);

            return FAILURE;
        }
    }

    return SUCCESS;
}

// Function to create a linked list from the operand string
void create_list(char *opr, node **head, node **tail)
{
    int len = strlen(opr);
    for(int i = 0; i < len; i++)
    {
    if(!isdigit(opr[i]))
        {
        printf("Invalid operand\n");
        exit(0);
        }
        insert_last(head, tail, opr[i] - '0');
    }
}

int insert_last(node **head, node **tail, int data) 
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
    printf("Memory allocation failed\n");
    return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
    *head = new;
        *tail = new;
    }
    else
    {
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    }
    return SUCCESS;
}

void print_list(node *head) //Function to print the linked list representation of the number.
{
    node *temp = head;
    while (temp != NULL && temp->data == 0 && temp->next != NULL)
    {
    temp = temp->next;
    }
    while(temp != NULL)
    {
    printf("%d", temp->data);
    temp = temp->next;
    }
    printf("\n");
}

int insert_first(node **head, node **tail, int data) //
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
    printf("Memory allocation failed\n");
    return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
    *head = new;
        *tail = new;
    }
    else
    {
    new->next = *head;
    (*head)->prev = new;
    *head = new;
    }
    return SUCCESS;
}

int list_len(node *head) //Function to calculate the length of the linked list.
{
    int count = 0;
    node *temp = head;
    while(temp != NULL)
    {
    count++;
    temp = temp->next;
    }
    return count;
}

int compare_list(node *head1, node *head2) //Function to compare two linked lists representing numbers and determine which one is greater, or if they are the same.
{

    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if(len1 > len2) //If the length of the first linked list is greater than the length of the second linked list, return OPERAND1 to indicate that the first number is greater.
    {
        return OPERAND1;
    }
    else if(len2 > len1)
    {
        return OPERAND2;
    }
    else
    {
    node *temp1 = head1;
    node *temp2 = head2;
        while(temp1 != NULL)
        {
        if(temp1->data > temp2->data)
        {
        return OPERAND1;
        }
        else if(temp2->data > temp1->data)
        {
        return OPERAND2;
        }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return SAME; 
    }

}
int delete_list(node **head, node **tail) //Function to delete the linked list and free the allocated memory.
{
    node *temp = *head;
    while(temp != NULL)
    {
    node *next = temp->next;
    free(temp);
    temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

void remove_pre_zeros(node **head, node **tail) //Function to remove leading zeros from the linked list representation of the number.
{
    node *temp = *head;
    while(temp != NULL && temp->data == 0)
    {
    *head = temp->next;
    if(*head != NULL)
        (*head)->prev = NULL;
    free(temp);
    temp = *head;
    }

    if (*head == NULL)
    {
    *tail = NULL;
    }
}
