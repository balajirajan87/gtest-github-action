#include <gtest/gtest.h>
#include "TestChallenge.h"

int networkAltererStub(float celcius){
    return 500;
}

float celciusArg;
int callCount;
int networkAltererMock(float celcius){
      celciusArg=celcius;
      ++callCount;
  return 500;
}

TEST(TestChallengeTestSuite, StateTesting){
//Arrange
  int expectedFailureCount=1;
  float inputTemp = 100;
   setCount(0);
 //Act
  alertInCelcius(inputTemp,&networkAltererStub);
  //Assert
  ASSERT_EQ(expectedFailureCount, getCount());
  
}
TEST(TestChallengeTestSuite, InteractionTesting){
//Arrange
  int expectedFailureCount=1;
  float inputTempInF = 100.00004;
 setCount(0);
  float expectedCelciusToBeReceivedByDependency=37.7778;
 //Act
  alertInCelcius(inputTempInF,&networkAltererMock);
  
  //Assert
  EXPECT_EQ(expectedFailureCount, getCount());//state Based 
  EXPECT_FLOAT_EQ(celciusArg, expectedCelciusToBeReceivedByDependency);//state Based 
  EXPECT_EQ(callCount,1);
  
  
}