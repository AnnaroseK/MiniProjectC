/**
 * @file calculator_header.h
 * @author Annarose K
 * @brief To perfrom calculation
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __CALCULATOR_HEADER_H__
#define __CALCULATOR_HEADER_H__

/**
 * @brief Error enum values
 * 
 */

typedef enum error_t{
    SUCCESS=1,
    ERROR_NULL=0,
    INVALID_INPUT=-1,
    ERROR_DIV_ZERO=-2,
    OUT_OF_SCOPE=-3
}error;

/**
 * @brief the input expression
 * 
 */

typedef struct expression{
    char value[200];
}expression;

int operator[20]={0},index_operator=0,index_operand=0;
char operand[20];

/**
 * @brief To check if input is valid or not
 * 
 * @param e expression entered by user
 * @return error SUCCESS if right input else display respective errors
 */

error check_input(expression *e);

/**
 * @brief To separate operators and operands from the expression
 * 
 * @param e expression entered by user
 * @return int number of operands present
 */
int separate_operator_operand(expression *e);

/**
 * @brief To compute the expression
 * 
 * @param e expression entered by user
 * @param result the rult of the expression 
 */
void compute(expression *e,long long int *result);

/**
 * @brief To perform addition and subtraction
 * 
 * @param length the number of operands
 * @param result result of operation
 */
void sum_and_minus(int length,long long int *result);

/**
 * @brief To perform multiplication and division
 * 
 * @param length the number of operands
 * @param result result of operation
 */
void mul_and_div(int length,long long int *result);
#endif
