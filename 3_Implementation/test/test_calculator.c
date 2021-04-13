#include "calculator_header.h"
#include "unity.h"

static expression *e;
long long int result=0;

void setup(){}
void teardown(){}

void testing(void){
    strcpy(e->value,NULL);
    TEST_ASSERT_EQUAL(ERROR_NULL,check_input(&e));
    TEST_ASSERT_EQUAL(0,result);

    strcpy(e->value,"abc+d");
    TEST_ASSERT_EQUAL(INVALID_INPUT,check_input(&e));
    TEST_ASSERT_EQUAL(0,result);

    strcpy(e->value,"12+4");
    TEST_ASSERT_EQUAL(SUCCESS,check_input(&e));
    TEST_ASSERT_EQUAL(16,result);

    strcpy(e->value,"2+3*4");
    TEST_ASSERT_EQUAL(SUCCESS,check_input(&e));
    TEST_ASSERT_EQUAL(14,result);

    strcpy(e->value,"300000+400000+500000/683*1102833+8900000+9000000");
    TEST_ASSERT_EQUAL(OUT_OF_SCOPE,check_input(&e));
    TEST_ASSERT_EQUAL(0,result);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testing);
    return UNITY_END();
}
