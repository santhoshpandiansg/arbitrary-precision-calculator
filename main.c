/*
Description: 
-> This is a APC project that implements a calculator using linked lists. 
-> The calculator can perform addition, subtraction, multiplication, and division on large numbers that cannot be handled by built-in data types. 
-> The numbers are represented as linked lists, where each node contains a single digit. 
-> The program takes command line arguments for the two numbers and the operator, performs the calculation, and prints the result.
Name of the project: APC - Arbitrary Precision Calculator
Author: Santhosh Pandian SG
Date: 5-4-2026

*/


#include "apc.h"

int main(int argc, char *argv[])
{
    print_banner();

    if(argc == 2 && strcmp(argv[1], "-help") == 0)
    {
        print_help();
        return SUCCESS;
    }

    if(cla_validation(argc, argv) == FAILURE)
    {
        return FAILURE;
    }

    node *head1 = NULL;
    node *tail1 = NULL;

    node *head2 = NULL;
    node *tail2 = NULL;

    node *headR = NULL;
    node *tailR = NULL;

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1, &tail1);
    remove_pre_zeros(&head2, &tail2);

    if(head1 == NULL)
        insert_last(&head1, &tail1, 0);

    if(head2 == NULL)
        insert_last(&head2, &tail2, 0);

    clock_t start = clock();

    switch(argv[2][0])
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            break;

        case '-':
        {
            int ret = compare_list(head1, head2);

            if(ret == OPERAND1)
            {
                subtraction(tail1, tail2,
                            &headR, &tailR);
            }
            else if(ret == OPERAND2)
            {
                subtraction(tail2, tail1,
                            &headR, &tailR);

                printf(CLR_RED "-");
            }
            else
            {
                insert_last(&headR, &tailR, 0);
            }

            break;
        }

        case 'x':
        case 'X':
            multiplication(tail1, tail2,
                           &headR, &tailR);
            break;

        case '/':
            division(head1, head2,
                     tail2,
                     &headR, &tailR);
            break;

        default:
            printf(CLR_RED "Invalid operator\n" CLR_RESET);
            return FAILURE;
    }

    clock_t end = clock();

    printf(CLR_GREEN "\nResult:\n" CLR_RESET);

    print_result(argv[1],
                 argv[2][0],
                 argv[3],
                 headR);

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf(CLR_CYAN "\nExecution Time: %.8f sec\n" CLR_RESET,
           time_taken);

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    printf(CLR_GREEN "\nMemory cleaned successfully\n" CLR_RESET);

    return SUCCESS;
}