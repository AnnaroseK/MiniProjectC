#include<stdio.h>
#include<string.h>
#include "calculator_header.h"

error check_input(exp *e1){
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
    return SUCCESS;
}

