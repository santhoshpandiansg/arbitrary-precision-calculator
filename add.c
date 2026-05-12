#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR) //This function adds two numbers represented by linked lists and stores the result in another linked list.
{
    node *temp1 = tail1;
    node *temp2 = tail2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int sum = carry;
        if(temp1 != NULL) //If temp1 is not NULL, add its data to the sum and move to the previous node.
        {
        sum = sum + temp1->data;
        temp1 = temp1->prev;
        }
        if(temp2 != NULL) //If temp2 is not NULL, add its data to the sum and move to the previous node.
        {
        sum = sum + temp2->data;
        temp2 = temp2->prev;
        }
        carry = sum / 10;
        insert_first(headR, tailR, sum % 10);
    }

    
}
