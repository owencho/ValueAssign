#include "unity.h"
#include "Exception.h"
#include "Error.h"
#include "CException.h"

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

    Try{
    v = isPositiveValueLessThan10(-2245);
    TEST_FAIL_MESSAGE("Expect ERR_VALUE_IS_NON_POSITIVE to be thrown , but none received.");
    }Catch(ex){
     TEST_ASSERT_EQUAL_MESSAGE(ERR_VALUE_IS_NON_POSITIVE,ex,"Wrong Exception error code");
    }
}
