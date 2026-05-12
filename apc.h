#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SUCCESS     1
#define FAILURE     0

#define SAME        0
#define OPERAND1    1
#define OPERAND2    2

// ANSI Colors
#define CLR_RESET   "\033[0m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_CYAN    "\033[36m"
#define CLR_BOLD    "\033[1m"

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

} node;

// Arithmetic Operations
void addition(node *tail1, node *tail2,
              node **headR, node **tailR);

void subtraction(node *tail1, node *tail2,
                 node **headR, node **tailR);

void multiplication(node *tail1, node *tail2,
                    node **headR, node **tailR);

void division(node *head1, node *head2,
              node *tail2,
              node **headR, node **tailR);

// Validation
int cla_validation(int argc, char *argv[]);

// List Operations
void create_list(char *opr,
                 node **head,
                 node **tail);

int insert_first(node **head,
                 node **tail,
                 int data);

int insert_last(node **head,
                node **tail,
                int data);

int delete_list(node **head,
                node **tail);

void print_list(node *head);

// Utility
int compare_list(node *head1,
                 node *head2);

int list_len(node *head);

void remove_pre_zeros(node **head,
                      node **tail);

void print_banner(void);

void print_help(void);

void print_result(char *opr1,
                  char operator,
                  char *opr2,
                  node *result);

#endif