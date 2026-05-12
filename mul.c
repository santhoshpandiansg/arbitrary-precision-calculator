#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR) //This function multiplies two numbers represented by linked lists and stores the result in another linked list.
{
    node *temp1=tail1,*temp2=tail2;
    node *headR2=NULL,*tailR2=NULL,*head_AR=NULL,*tail_AR=NULL;
    int carry=0,flag=0,zero_flag=0;
    while(temp2) //Outer loop to traverse the second linked list (temp2) and perform multiplication with each digit of the first linked list (temp1).
    {
        headR2=NULL;
        tailR2=NULL;
        for(int i=0;i<zero_flag;i++)
            insert_first(&headR2,&tailR2,0);
        carry=0;

        while(temp1) //Inner loop to traverse the first linked list (temp1) and perform multiplication with the current digit of the second linked list (temp2).
        {
            int res;
            res=temp1->data * temp2->data + carry;
            carry=res/10;
            if(!flag) 
                insert_first(headR,tailR,res%10);
            else
            {
                insert_first(&headR2,&tailR2,res%10);
            }
            temp1=temp1->prev;
            
        }

        if(carry) //If there is a carry left after the inner loop, insert it at the beginning of the result linked list.
        {
            if(!flag)
                insert_first(headR,tailR,carry);
            else
                insert_first(&headR2,&tailR2,carry);
        }
        if(flag)
        {
        head_AR=NULL;
        tail_AR=NULL;
        addition(*tailR,tailR2,&head_AR,&tail_AR);
        delete_list(headR,tailR);
        delete_list(&headR2,&tailR2);
        *headR=head_AR;
        *tailR=tail_AR;
        head_AR=NULL;
        tail_AR=NULL;
        }
        temp2=temp2->prev;
        zero_flag++;
        temp1=tail1;
        flag=1;
    }
}