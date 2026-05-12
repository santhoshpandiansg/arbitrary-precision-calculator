#include "apc.h"

void print_banner(void)
{
    printf(CLR_CYAN CLR_BOLD);

    printf("====================================================\n");
    printf("        ARBITRARY PRECISION CALCULATOR\n");
    printf("====================================================\n");

    printf(CLR_RESET);
}

void print_help(void)
{
    printf(CLR_YELLOW);

    printf("\nUsage:\n");
    printf("./apc <operand1> <operator> <operand2>\n");

    printf("\nSupported Operators:\n");

    printf("+  Addition\n");
    printf("-  Subtraction\n");
    printf("x  Multiplication\n");
    printf("/  Division\n");

    printf("\nExamples:\n");

    printf("./apc 999999999999999 + 1\n");
    printf("./apc 123456789 x 987654321\n");
    printf("./apc 100000000000 / 25\n");

    printf("\nFeatures:\n");

    printf("- Arbitrary Precision Arithmetic\n");
    printf("- Doubly Linked List Representation\n");
    printf("- Large Integer Computation\n");
    printf("- Dynamic Memory Management\n");
    printf("- Timing Benchmark\n");

    printf(CLR_RESET);
}

void print_result(char *opr1,
                  char operator,
                  char *opr2,
                  node *result)
{
    printf(CLR_BLUE);

    printf("%s %c %s = ",
           opr1,
           operator,
           opr2);

    printf(CLR_RESET);

    print_list(result);
}