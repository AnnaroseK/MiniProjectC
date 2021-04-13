#include<stdio.h>
#include<string.h>
#include "calculator_header.h"

long long int result=0;

void shift(int *operator,int *operand,int *length,int i){
    for(int rep=i+1;rep<length-1;rep++){
            operand[rep]=operand[rep+1];
        }
        for(int rep=i;rep<length-1;rep++){
            operator[rep]=operator[rep+1];
        }
        length--;
}

void mul_and_div(int *operator,int *operand,int length,int *result){
    for(int i=0;i<length;i++){
        if(operator[i]=='/'){
            result=operand[i]/operand[i+1];
            operand[i]=result;
            shift(operator,operand,&length,i);
        }
        else if(operator[i]=='*'){
            result=operand[i]*operand[i+1];
            operand[i]=result;
            shift(operator,operand,&length,i);
        }
    }
}

void sum_and_minus(int *operator,int *operand,int length,int *result){
    for(int i=0;i<length;i++){
        if(operator[i]=='+'){
            result=operand[i]+operand[i+1];
            operand[i]=result;
            shift(operator,operand,&length,i);
        }
        else if(operator[i]=='-'){
            result=operand[i]-operand[i+1];
            operand[i]=result;
            shift(operator,operand,&length,i);
        }
    }
}

long long int compute(exp *e,int *operator,int *operand,int *result){
    int length=separate_operator_operand(e);
    if(SUCCESS==check_input(e)){
        mult_and_div(operator,operand,length,&result);
        sum_and_minus(operator,operand,length,&result);
    }
    return result;
}