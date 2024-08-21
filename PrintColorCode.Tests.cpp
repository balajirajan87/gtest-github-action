#include "PrintColorCode.h"
#include <gtest/gtest.h>

//TestDouble, FakeDependnecy, Stub , Dumb
void FakePrinter(int colorCode, const char* majorColor,const char* minorColor){
  
}
TEST(PrintColorCodeTestSuite, AssertColorCodeManualItemsCount){
//Arrange
  int expectedCount=25;
 //Act
  int actualCount=printColorMap(&FakePrinter);
  //Assert
  ASSERT_EQ(expectedCount,actualCount);
  
}
