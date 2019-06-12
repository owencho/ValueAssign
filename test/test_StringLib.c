#include "unity.h"
#include "StringLib.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_stringCompare_given_ali_and_ali_expect_a_0(void)
{
   int result = stringCompare("ali" , "ali");
   TEST_ASSERT_EQUAL (0,result);             //0 means equal
}

void test_stringCompare_given_bottas_and_bati_expect_a_1(void)
{
   int result = stringCompare("bottas" , "bati");
   TEST_ASSERT_EQUAL (1,result);           //1 means lexicographically larger
}
void test_stringCompare_given_same_and_sami_expect_a_minus_1(void)
{
   int result = stringCompare("same" , "sami");
   TEST_ASSERT_EQUAL (-1,result);           //-1 means lexicographically smaller
}

void test_stringCompare_given_babu_and_baBu_expect_a_1(void)
{
   int result = stringCompare("babu" , "baBu");
   TEST_ASSERT_EQUAL (1,result);           //b is lexicographically larger than B
}

void test_stringCompare_given_Aquaman_and_aquaman_expect_a_negative_1(void)
{
   int result = stringCompare("Aquaman" , "aquaman");
   TEST_ASSERT_EQUAL (-1,result);           //A is lexicographically smaller than a
}
void test_stringCompare_given_NULL_and_mayday_expect_a_negative_1(void)
{
   int result =  stringCompare(NULL , "mayday");
   TEST_ASSERT_EQUAL (-1,result);           //NULL is lexicographically smaller
}

void test_stringCompare_given_NULL_and_NULL_expect_a_0(void)
{
   int result = stringCompare(NULL , NULL);
   TEST_ASSERT_EQUAL (0,result);           //NULL is lexicographically same
}

void test_stringCompare_given_Jumbo_and_NULL_expect_a_1(void)
{
   int result =  stringCompare("Jumbo",NULL);
   TEST_ASSERT_EQUAL (1,result);           //mayday is lexicographically larger
}

void test_stringCompare_given_yell_SPACE_and_yell_expect_a_1(void)
{
   int result =  stringCompare("yell " , "yell");
   TEST_ASSERT_EQUAL (1,result);
}

void test_stringCompare_given_moon_and_moon_SPACE_expect_a_negative_1(void)
{
   int result =  stringCompare("moon" , "moon ");
   TEST_ASSERT_EQUAL (-1,result);
}