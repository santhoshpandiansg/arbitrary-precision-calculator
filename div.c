#include "apc.h"

void division(node *head_L1, node *head_op2,node *tail_op2, node **headR, node **tailR) //This function performs division of two numbers represented by linked lists and stores the quotient in another linked list. It also handles division by zero and prints the remainder if there is any.
{
    node *head_op1=NULL,*tail_op1=NULL,*L1_temp=head_L1,*head_SR=NULL,*tail_SR=NULL;
    int sub_count=0;
    if (head_op2 == NULL || (head_op2->data == 0 && head_op2->next == NULL)) //If the second number is zero, print an error message and return.
    {
        printf("ERROR: Division by zero\n");
        return;
    }
    if(compare_list(head_L1,head_op2)==OPERAND2) //If the first number is less than the second number, the quotient is zero and the remainder is the first number. Insert a node with data 0 in the result linked list and return.
        {
            insert_first(headR,tailR,0);
            return;
        }
    insert_last(&head_op1,&tail_op1,L1_temp->data);
        L1_temp=L1_temp->next;

    while(head_op1) //Loop until the first operand becomes zero, which means the division is complete.
    {
    while(compare_list(head_op1,head_op2)==OPERAND2) //While the first number is less than the second number, keep adding digits from the first number to the first operand until it becomes greater than or equal to the second number.
    {
        if(L1_temp==NULL)
            break;
        insert_last(&head_op1,&tail_op1,L1_temp->data);
        L1_temp=L1_temp->next;

    }
    sub_count=0;
    while(compare_list(head_op1,head_op2)==OPERAND1 || compare_list(head_op1,head_op2)==SAME ) //While the first number is greater than or equal to the second number, perform subtraction and increment the quotient count until the first number becomes less than the second number.
    {
        subtraction(tail_op1,tail_op2,&head_SR,&tail_SR);
        sub_count++;
        delete_list(&head_op1,&tail_op1);
        head_op1=head_SR;
        tail_op1=tail_SR;
        head_SR= NULL;
        tail_SR=NULL;
        remove_pre_zeros(&head_op1, &tail_op1);
    }
    insert_last(headR,tailR,sub_count);
    if(L1_temp==NULL)
        break;
    }

    printf(CLR_YELLOW "Remainder = " CLR_RESET);
    if(head_op1)
    {
    print_list(head_op1);
    }
    else    printf("0\n");


    
}
