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