#include "unity.h"
#include "AssignValue.h"
#include "StringLib.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_isEqualSign_given_apple_equals_1234_expect_1(void){

    int result = isEqualSign("apple = 1234");
    TEST_ASSERT_EQUAL (1,result); //apple word is not in the string

  }

void test_isEqualSign_given_andy_equals_3214_commar_abu_equal_1255_expect_1(void){

      int result = isEqualSign("andy = 3214 , abu = 1255");
      TEST_ASSERT_EQUAL (1,result); //apple word is not in the string

    }

void test_isEqualSign_given_sam_commar_john_equal_7749_expect_1(void){

          int result = isEqualSign("sam, john = 7749");
          TEST_ASSERT_EQUAL (1,result); //apple word is not in the string

    }
void test_isEqualSign_given_sammy_expect_0(void){

                  int result = isEqualSign("sammy");
                  TEST_ASSERT_EQUAL (0,result); //apple word is not in the string

  }

void test_isEqualSign_given_sammeng_commar_johnny_expect_0(void){

            int result = isEqualSign("sammeng, johnny");
            TEST_ASSERT_EQUAL (0,result); //apple word is not in the string

      }



void test_assignValue_given_pineapple_equals_789123_expect_value_is_assigned(void){
  int pineappleVar = -789123;
  NameValueMap map []= {
  {"pineapple", &pineappleVar},
    {NULL , NULL},
};

   assignValue(map , " pineapple=789123");
   TEST_ASSERT_EQUAL(789123,pineappleVar);
}

void test_assignValue_given_peach_equals_234_but_wanted_watermelon_expect_no_value_is_assigned(void){
  int watermelonVar = -987654;
  NameValueMap map [] = {
  {"watermelon", &watermelonVar},
    {NULL , NULL},
};

   assignValue(map , " peach=234");
   TEST_ASSERT_EQUAL(-987654,watermelonVar);
}

void test_assignValue_given_apple_equals_123_expect_value_is_assigned(void){
  int appleVar = 0;
  NameValueMap map [] = {
  {"apple", &appleVar},
    {NULL , NULL},
};

   assignValue(map , " orange = 0 ,apple = 123");
   TEST_ASSERT_EQUAL(123,appleVar);
}

void test_assignValue_given_apple_equals_123_durian_equal_789_expect_value_is_assigned(void){
  int appleVar = 0;
  int durianVar = 0;
  int orangeVar = 0;
  NameValueMap map [] = {
  {"apple", &appleVar},
  {"durian", &durianVar},
  {"orange",&orangeVar},
    {NULL , NULL},
};

   assignValue(map , " orange = 0 ,apple = 123 ,durian = 789");
   TEST_ASSERT_EQUAL(123,appleVar);
   TEST_ASSERT_EQUAL(789,durianVar);

}
