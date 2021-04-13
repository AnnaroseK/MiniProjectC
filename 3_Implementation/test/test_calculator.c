#include "calculator_header.h"
#include "unity.h"

static exp *e;
static exp *result={"0"};

void setup(){}
void teardown(){}

void input(void){
    strcpy(e->value,"abc+d");
    TEST_ASSERT_EQUAL(INVALID_INPUT,check_input(&e));
    strcpy(result->value,"0");
}