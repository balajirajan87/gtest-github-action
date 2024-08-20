#include "StringCalculator.h"
#include <gtest/gtest.h>

//Fixture
class StringCalculatorAddTestFixture:public testing::Test{
  protected:
    //Common Reusable Code
    StringCalculator calculator;
    //Hook Callbacks
};

TEST_F(StringCalculatorAddTestFixture,_when_passed_a_single_number_returns_0_for_empty_string){
 //Arrange
  string input="";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture,when_passed_a_single_number_returns_0_for_zero){
 //Arrange
  string input="0";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_a_single_number_returns_1_for_one){
 //Arrange
  string input="1";
  int expectedsum=1;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_multiple_comma_delimited_numbers_returns_their_sum){
 //Arrange
  string input="1,2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_multiple_comma_delimited_numbers_returns_their_sum_1){
 //Arrange
  string input="1,2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_delimited_with_newline_and_comma_returns_their_sum){
 //Arrange
  string input="1\n2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_delimited_with_newline_and_comma_returns_the_sum_based_on_that_delimiter){
 //Arrange
  string input="//;\n1;2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, string_calculator_add_when_passed_negative_number_throws_an_exception_listing_invalid_values){
  string input="1,-2,-4,5";
  ASSERT_THROW(calculator.Add(input),invalid_argument);
}
TEST_F(StringCalculatorAddTestFixture, string_calculator_add_when_passed_numbers_over_1000_ignores_them){
 //Arrange
  string input="42,1001,3";
  int expectedsum=45;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_multicharacter_delimiter_uses_that_delimiter_to_sum_values){
 //Arrange
  string input="//[***]\n8***2***3";
  int expectedsum=13;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_multiple_delimiters_sums_on_each_delimiter){
 //Arrange
  string input="//[*][%]\n4*2%3";
  int expectedsum=9;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST_F(StringCalculatorAddTestFixture, when_passed_multiple_multicharacter_delimiters_sums_on_each_delimiter_1){
 //Arrange
  string input="//[**][%^]\n4**1%^9";
  int expectedsum=14;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}