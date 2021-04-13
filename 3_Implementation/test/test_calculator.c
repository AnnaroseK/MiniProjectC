#include<stdio.h>
#include<string.h>
#include "calculator_header.h"
#include "unity.h"

static expression *e;
long long int results=0;

void setUp(){}
void tearDown(){}

void testing(void){
    strcpy(e->value,NULL);
    TEST_ASSERT_EQUAL(ERROR_NULL,check_input(e));
    TEST_ASSERT_EQUAL(0,results);

    strcpy(e->value,"abc+d");
    TEST_ASSERT_EQUAL(INVALID_INPUT,check_input(e));
    TEST_ASSERT_EQUAL(0,results);

    strcpy(e->value,"12+4");
    TEST_ASSERT_EQUAL(SUCCESS,check_input(e));
    TEST_ASSERT_EQUAL(16,results);

    strcpy(e->value,"2+3*4");
    TEST_ASSERT_EQUAL(SUCCESS,check_input(e));
    TEST_ASSERT_EQUAL(14,results);

    strcpy(e->value,"300000+400000+500000/683*1102833+8900000+9000000");
    TEST_ASSERT_EQUAL(OUT_OF_SCOPE,check_input(e));
    TEST_ASSERT_EQUAL(0,results);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testing);
    return UNITY_END();
}
