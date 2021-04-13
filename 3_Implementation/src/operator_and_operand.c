#include<stdio.h>
#include<string.h>
#include "calculator_header.h"

int separate_operator_operand(expression *e){
    char temp[200];
    strcpy(temp,e->value);
    int len=strlen(temp);
    index_operator=0,index_operand=0;
    for(int i=0;i<len;i++){
        if(isdigit(temp[i])){
            operand[index_operand]*=10+atoi(temp[i]);
        }
        else{
            index_operand++;
            operator[index_operator]=temp[i];
            index_operator++;
        }
    }
    return index_operator;
}
