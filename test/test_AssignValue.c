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

void test_equalValueFind_given_sammung_and_sammung_equal_123_expect_equal_123(void){

                  char * sammung123 = "sammung =123";
                  char * result = equalValueFind("sammung",sammung123);
                  TEST_ASSERT_EQUAL_PTR (sammung123+ 7,result);
                  TEST_ASSERT_EQUAL_STRING(" =123",result);

}
void test_equalValueFind_given_huawei_and_sony_equal_7789_expect_nothing_change(void){

                  char * sony7789 = "sony =7789";
                  char * result = equalValueFind("huawei",sony7789);
                  TEST_ASSERT_EQUAL_PTR (sony7789+ 0,result);
                  TEST_ASSERT_EQUAL_STRING(sony7789,result);

}

void test_equalValueFind_given_Sony_XperiaX1_and_iphone_equal_4499_expect_space_equal_3099(void){

                  char * phonePrice = "iphoneXS = 4999 ,SonyXperiaX1 = 3099";
                  char * result = equalValueFind("SonyXperiaX1",phonePrice);
                  TEST_ASSERT_EQUAL_PTR (phonePrice+ 29,result);
                  TEST_ASSERT_EQUAL_STRING(" = 3099",result);

}

void test_equalValueFind_given_ali_equal_44_abu_equal_5_seng_equal_8_expect_space_equal_8(void){

                  char * seng = "ali = 44 ,abu = 5 ,seng =8";
                  char * result = equalValueFind("seng",seng);
                  TEST_ASSERT_EQUAL_PTR (seng+ 23,result);
                  TEST_ASSERT_EQUAL_STRING(" =8",result);

}


void test_assignValue_given_pineapple_equals_789123_expect_value_is_assigned(void){
  int pineappleVar = -789123;
  NameValueMap map []= {
    {"pineapple", &pineappleVar},
    {NULL , NULL},
  };

   assignValue(map , " pineapple = 789123 ");
   TEST_ASSERT_EQUAL(789123,pineappleVar);
}

void test_assignValue_given_peach_equals_234_but_wanted_watermelon_expect_no_value_is_assigned(void){
  int watermelonVar = -987654;
  NameValueMap map [] = {
    {"watermelon", &watermelonVar},
    {NULL , NULL},
  };

   assignValue(map , " peach = 234 ");
   TEST_ASSERT_EQUAL(-987654,watermelonVar);
}

void test_assignValue_given_lee_equals_13579_expect_13579_is_assigned(void){
  int leeVar = 88;
  NameValueMap map [] = {
    {"lee", &leeVar},
    {NULL , NULL},
  };

   assignValue(map , " lee =13579 ");
   TEST_ASSERT_EQUAL(13579,leeVar);
}

void test_assignValue_given_apple_equals_123_expect_value_is_assigned(void){
  int appleVar = 0;
  NameValueMap map [] = {
    {"apple", &appleVar},
    {NULL , NULL},
  };

   assignValue(map , " orange = 0 ,apple = 123 ");
   TEST_ASSERT_EQUAL(123,appleVar);
}

void test_assignValue_given_mango_equals_789_expect_value_is_assigned(void){
  int mangoVar = 77;
  NameValueMap map [] = {
    {"mango", &mangoVar},
    {NULL , NULL},
  };

   assignValue(map , " mangosteen = 77, mango = 789 ");
   TEST_ASSERT_EQUAL(789,mangoVar);
}

void test_assignValue_given_apple_equals_123_durian_equal_789_expect_value_is_assigned(void){
  int rambutanVar = 0;
  int durianVar = 0;
  int orangeVar = 0;
  NameValueMap map [] = {
  {"rambutan", &rambutanVar},
  {"durian", &durianVar},
  {"orange",&orangeVar},
    {NULL , NULL},
};

   assignValue(map , " orange = 700 ,rambutan = 123 ,durian = 789");
   TEST_ASSERT_EQUAL(123,rambutanVar);
   TEST_ASSERT_EQUAL(789,durianVar);

}
