#include "unity.h"
#include "StringLib.h"
#include "Exception.h"
#include "Error.h"
#include "CException.h"

//Test for isWordInString
void test_isWordInString_given_pine_and_pine_expect_a_1(void)
{
  int result = isWordInString("pine" , "pine");
  TEST_ASSERT_EQUAL (1,result); //pine word is in the string

}

void test_isWordInString_given_apple_and_apiplnle_expect_a_0(void)
{
  int result = isWordInString("apple" , "apiplnle");
  TEST_ASSERT_EQUAL (0,result); //apple word is not in the string

}

void test_isWordInString_given_mamamia_and_mamalaide_expect_a_0(void)
{
  int result = isWordInString("mamamia" , "mamalaide");
  TEST_ASSERT_EQUAL (0,result); //mamamia word is not in the string

}

void test_isWordInString_given_rot_and_rotiboy_expect_a_0(void)
{
  int result = isWordInString("rot" , "rotiboy");
  TEST_ASSERT_EQUAL (0,result); //rot word is not in the string

}

void test_isWordInString_given_apple_and_Apple_expect_a_1(void)
{
  int result = isWordInString("apple" , "Apple");
  TEST_ASSERT_EQUAL (1,result); //Apple word is in the string

}

void test_isWordInString_given_pineapple_and_apple_expect_a_0(void)
{
  int result = isWordInString("pineapple" , "apple");
  TEST_ASSERT_EQUAL (0,result); //pineapple word is not in the string

}

void test_isWordInString_given_pine_the_apple_and_apple_expect_a_0(void)
{
  int result = isWordInString("pine the apple" , "apple");
  TEST_ASSERT_EQUAL (0,result); //pine the apple word is not in the string

}

void test_isWordInString_given_Mac_Burger_and_Mac_Burger_Delicious_expect_a_1(void)
{
  int result = isWordInString("Mac Burger" , "Mac Burger Delicious");
  TEST_ASSERT_EQUAL (1,result); //Mac Burger word is in the string

}

void test_isWordInString_given_hello_space_space_and_hello_space_world_expect_a_0(void)
{
  int result = isWordInString("hello  " , "hello world");
  TEST_ASSERT_EQUAL (0,result); //pine the apple word is not in the string

}

void test_isWordInString_given_tart_and_tart_the_tard_expect_a_1(void)
{
  int result = isWordInString("tart" , "tart the tard");
  TEST_ASSERT_EQUAL (1,result); //tart word is in the string

}


//Test StringCompare
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
//Test SkipWhiteSpace
void test_skipWhiteSpaces_given_Mumbo_jumbo_expect_to_skip_leading_spaces(void)
{
   char * mumboJumbo = "    Mumbo jumbo";
   char * firstNonWhiteSpace =  skipWhiteSpaces("    Mumbo jumbo");
   TEST_ASSERT_EQUAL_PTR (mumboJumbo + 4,firstNonWhiteSpace);
   TEST_ASSERT_EQUAL_STRING("Mumbo jumbo",firstNonWhiteSpace);
}

void test_skipWhiteSpaces_given_no_space_huckberry_expect_nothing_done(void)
{
   char * huckberry = "huckberry";
   char * noSkip=  skipWhiteSpaces("huckberry");
   TEST_ASSERT_EQUAL_PTR (huckberry+ 0,noSkip);
   TEST_ASSERT_EQUAL_STRING(huckberry,noSkip);
}
void test_skipWhiteSpaces_given_tarzan_symbol_jungle_expect_to_skip_tarzan_with_symbol(void)
{
   char * tarzanJungle = "tarzan!@#$% jungle";
   char * jungle=  skipWhiteSpaces(tarzanJungle);
   TEST_ASSERT_EQUAL_PTR (tarzanJungle+ 12,jungle);
   TEST_ASSERT_EQUAL_STRING("jungle",jungle);
}

void test_skipNonWhiteSpaces_given_space_sultana_expect_nothing(void)
{
   char * sultana = " sultana";
   char * noSkip=  skipNonWhiteSpaces(sultana);
   TEST_ASSERT_EQUAL_PTR (sultana + 0,noSkip);
   TEST_ASSERT_EQUAL_STRING(sultana,noSkip);
}

void test_skipNonWhiteSpaces_given_lewis_space_hamiltion_expect_hamilton(void)
{
   char * lewisName = "lewis hamilton";
   char * skip=  skipNonWhiteSpaces(lewisName);
   TEST_ASSERT_EQUAL_PTR (lewisName + 5,skip);
   TEST_ASSERT_EQUAL_STRING(" hamilton",skip);
}

void test_skipIfAlphaNumberics_given_rambo123456_expect_to_skip_rambo123456(void)
{
   char * rambowithSymbols = "rambo123456()&*()  ";
   char * symbols=  skipIfAlphaNumberics(rambowithSymbols);
   TEST_ASSERT_EQUAL_PTR (rambowithSymbols + 11,symbols);
   TEST_ASSERT_EQUAL_STRING("()&*()  ",symbols);
}

void test_skipIfAlphaNumberics_given_space_then_kree_expect_nothing_done(void)
{
   char * spaceKree = "\t \nkree";
   char * noSkip=  skipIfAlphaNumberics(spaceKree);
   TEST_ASSERT_EQUAL_PTR (spaceKree + 0,noSkip);
   TEST_ASSERT_EQUAL_STRING(spaceKree,noSkip);
}
void test_skipIfNotAlphaNumberics_given_symbol_and_ironman1234_expect_to_skip_rambo123456(void)
{
   char * symbolsWithIronMan1234 = "()&*()ironman1234";
   char * symbols=  skipIfNotAlphaNumberics(symbolsWithIronMan1234);
   TEST_ASSERT_EQUAL_PTR (symbolsWithIronMan1234 + 6,symbols);
   TEST_ASSERT_EQUAL_STRING("ironman1234",symbols);
}

void test_skipIfNotAlphaNumberics_given_gucci771234_symbol_expect_to_skip_nothing(void)
{
   char * gucci771234Withsymbols = "gucci771234!@#$%";
   char * symbols=  skipIfNotAlphaNumberics(gucci771234Withsymbols);
   TEST_ASSERT_EQUAL_PTR (gucci771234Withsymbols + 0,symbols);
   TEST_ASSERT_EQUAL_STRING(gucci771234Withsymbols,symbols);
}

void test_convertStringToInteger_given_minus_12345678_then_abcde_expect_converted_to_integer(void)
{
   char * numMinus12345678 = "-12345678 abcde";
   char* endPtr = numMinus12345678;
   int num=  convertStringToInteger(&endPtr);
   TEST_ASSERT_EQUAL_PTR (numMinus12345678 +9 ,endPtr);
   TEST_ASSERT_EQUAL(-12345678,num);
}


/*
void test_convertStringToInteger_given_1029394tabitha_expect_return_0_and_NULL_pointer(void)
{
   CEXCEPTION_T ex;
   char * numMinus12345678 = "1029394tabitha";
   char*endPtr = numMinus12345678;
   int num=  -11111;
     Try{
        int v = convertStringToInteger(&endPtr);
        TEST_FAIL_MESSAGE("Expect ERR_VALUE_IS_INVALID to be thrown , but none received.");
        }Catch(ex){
         TEST_ASSERT_EQUAL_MESSAGE(ERR_VALUE_IS_INVALID,ex,"VALUE IS INVALID");
        }
}
*/
