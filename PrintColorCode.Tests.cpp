#include "PrintColorCode.h"
#include <string>
#include <gtest/gtest.h>
#include <vector>
//TestDouble, FakeDependnecy, Stub , Dumb
void FakePrinter(int colorCode, const char* majorColor,const char* minorColor){

}

//hand made mock
std::vector<std::string> coloCodeManual;
void FakePrinterMock(int colorCode, const char* majorColor,const char* minorColor){
      std::string majorColorString(majorColor);
      std::string minorColorString(minorColor);
      std::string manualItem=colorCode + "|"+majorColorString+"|"+minorColorString;
      coloCodeManual.push_back(manualItem);
}
class FakePrinterTestDouble:public IPrinter{

public:
      void print(int colorCode, const char* majorColor,const char* minorColor){
      }
};
TEST(PrintColorCodeTestSuite, AssertColorCodeManualItemsCount){
//Arrange
  int expectedCount=25;
 //Act
  int actualCount=printColorMap(&FakePrinter);
  //Assert
  ASSERT_EQ(expectedCount,actualCount);
  
}
TEST(PrintColorCodeTestSuite, AssertColorCodeManualItemsCountUsingStub){
//Arrange
  int expectedCount=25;
  FakePrinterTestDouble dependency;
 //Act
  int actualCount=printColorMap(&dependency);
  //Assert
  ASSERT_EQ(expectedCount,actualCount);
  
}
/*
TEST(PrintColorCodeTestSuite, AssertColorCodeManualItemsCountUsingLamda){
//Arrange
  int expectedCount=25;

 //Act
  int actualCount=printColorMap([](int colorcode,const char* majorColor,const char* minorColor) { });
  //Assert
  ASSERT_EQ(expectedCount,actualCount);
  
}
*/
TEST(PrintColorCodeTestSuite, InteractionTestig){
//Arrange
  std::string expectedManulaContent="2|White|Orange";

 //Act
  printColorMap(&FakePrinterMock);
  //Assert
     std::string recoredContent= coloCodeManual[1];
  ASSERT_EQ(recoredContent,expectedManulaContent);
  
}