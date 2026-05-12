#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Subtract from least significant digit to most significant digit.
    node *temp1 = tail1;
    node *temp2 = tail2;
    int borrow = 0;
    int digit1, digit2;

    while (temp1 != NULL || temp2 != NULL) //Loop until both linked lists are fully traversed.
    {

        if(temp1 != NULL) //If temp1 is not NULL, set digit1 to its data; otherwise, set digit1 to 0.
        digit1 = temp1->data;

        else
        digit1 = 0;

        if(temp2 != NULL)
        digit2 = temp2->data;
        else
        digit2 = 0;

        digit1 -= borrow;

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int res = digit1 - digit2;
        insert_first(headR, tailR, res);

        if (temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }

}
