    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #include<stdlib.h>
    #include "calculator_header.h"

    void mul_and_div(int length,long long int result);
    void sum_and_minus(int length,long long int result);
    void (*fptr1)(int,long long int)=&mul_and_div;
    void (*fptr2)(int,long long int)=&sum_and_minus;
    long long int result=0;
    int operator[20]={0},index_operator=0,index_operand=0,length;
    char operand[20];

    void shift(int length,int i){
        for(int rep=i+1;rep<length-1;rep++){
                operand[rep]=operand[rep+1];
            }
            for(int rep=i;rep<length-1;rep++){
                operator[rep]=operator[rep+1];
            }
            length--;
    }

    void mul_and_div(int length,long long int result){
        for(int i=0;i<length;i++){
            if(operator[i]=='/'){
                result=operand[i]/operand[i+1];
                operand[i]=result;
                shift(length,i);
            }
            else if(operator[i]=='*'){
                result=operand[i]*operand[i+1];
                operand[i]=result;
                shift(length,i);
            }
        }
    }

    void sum_and_minus(int length,long long int result){
        for(int i=0;i<length;i++){
            if(operator[i]=='+'){
                result=operand[i]+operand[i+1];
                operand[i]=result;
                shift(length,i);
            }
            else if(operator[i]=='-'){
                result=operand[i]-operand[i+1];
                operand[i]=result;
                shift(length,i);
            }
        }
    }

    void compute(expression *e,long long int result){
        int length=separate_operator_operand(e);
        if(SUCCESS==check_input(e)){
            (*fptr1)(length,result);
            (*fptr2)(length,result);
        }
    }

    int separate_operator_operand(expression *e){
        char temp[200];
        strcpy(temp,e->value);
        int len=strlen(temp);
        index_operator=0,index_operand=0;
        for(int i=0;i<len;i++){
            if(isdigit(temp[i])){
                char out[2]={temp[i],0};
                operand[index_operand]*=10+(int)atoi(out);
            }
            else{
                index_operand++;
                operator[index_operator]=temp[i];
                index_operator++;
            }
        }
        return index_operator;
    }

    error check_input(expression *e1){
        if(NULL==e1){
            return ERROR_NULL;
        }
        char temp[200];
        strcpy(temp,e1->value);
        int len=strlen(temp);
        if(len>30){
            return OUT_OF_SCOPE;
        }
        for(int i=0;i<len;i++){
            if((temp[i]>='a'&&temp[i]<='z')||(temp[i]>='A'&&temp[i]<='Z')){
                return INVALID_INPUT;
            }
            if(!(temp[i]=='+')||(temp[i]=='-')||(temp[i]=='*')||(temp[i]=='/')){
                return INVALID_INPUT;
            }
        }
        separate_operator_operand(e1);
        compute(e1,result);
        return SUCCESS;
    }
