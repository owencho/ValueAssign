#include "unity.h"
#include "Exception.h"
#include "Error.h"
#include "CException.h"
#include <stdio.h>
#include <stdarg.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_isPositiveValueLessThan10_given_3_expect_1(void)
{
    int v =isPositiveValueLessThan10(3);
    TEST_ASSERT_EQUAL(1,v);
}

void test_isPositiveValueLessThan10_given_245_expect_0(void)
{
    int v =isPositiveValueLessThan10(2345);
    TEST_ASSERT_EQUAL(0,v);
}



void test_isPositiveValueLessThan10_given_minus2245_expect_exception_to_be_thrown(void)
{
    CEXCEPTION_T ex;
    int v ;
    throwException(77,"message the value is %d , %d , %s \n and ayy hello");
    Try{
      v = isPositiveValueLessThan10(-987);
      TEST_FAIL_MESSAGE("Expect ERR_VALUE_IS_NON_POSITIVE to be thrown , but none received.");  //this error is important
    }Catch(ex){
      dumpException(ex);
      TEST_ASSERT_EQUAL_MESSAGE(ERR_VALUE_IS_NON_POSITIVE,ex,"Wrong Exception error code"); // need to check if ex equal to ERR_VALUE_IS_NON_POSITIVE if not then output wrong exception error code
      freeException(ex);
    }
}

void test_A(){
  printf("result from A() = %d\n",A(10));
  printf("result from A() = %d\n",A(-10));
  printf("result from A() = %d\n",A(20000));
}
