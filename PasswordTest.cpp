/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, special_char_err){
	Password myPassword;
	bool actual = myPassword.has_mixed_case("A#a^ABoo");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, case_mixer){
	Password myPassword;
	bool actual = myPassword.has_mixed_case("AbadAsBoao");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, low_caser){
	Password myPassword;
	bool actual = myPassword.has_mixed_case("onwejfnkjnd");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, upper_caser){
	Password myPassword;
	bool actual = myPassword.has_mixed_case("JHBEFNDNM");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, mixed_case_leading){
	Password myPassword;
	int actual = myPassword.count_leading_characters("RrrRrRrR");
	bool actualB=myPassword.has_mixed_case("RrrRrRrR");
	EXPECT_EQ(true,actualB);
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, all_five_leading){
	Password myPassword;
	int actual = myPassword.count_leading_characters("DDDDD");
	ASSERT_EQ(5,actual);
}

TEST(PasswordTest, three_of_five_leading){
	Password myPassword;
	int actual = myPassword.count_leading_characters("lllfm");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, empty_pass){
	Password myPassword;
	int actual = myPassword.count_leading_characters("");
	bool actualB = myPassword.has_mixed_case("");
	EXPECT_EQ(0,actual);
	ASSERT_EQ(false,actualB);
}