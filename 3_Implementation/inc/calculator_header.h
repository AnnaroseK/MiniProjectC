#ifndef __CALCULATOR_HEADER_H__
#define __CALCULATOR_HEADER_H__

typedef enum error_t{
    SUCCESS=1,
    ERROR_NULL=0,
    INVALID_INPUT=-1,
    ERROR_DIV_ZERO=-2,
    OUT_OF_SCOPE=-3
}error;

typedef struct expression{
    char value[200];
}exp;

int operator[20]={0},index_operator=0,index_operand=0;
char operand[20];

error check_input(exp *e);
int separate_operator_operand(exp *e);
long long int compute(exp *e,int *operator,int *operand);

#endif