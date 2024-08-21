#include "TestChallengeUsingGmock.h"
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::FloatEq;

//Mock Class
class NetworkAlerterMock:public INetworkAlerter{
public:
MOCK_METHOD(int, alert,(float celcius));
MOCK_METHOD( int,  getFailureCount,());
MOCK_METHOD( void ,incrementFailureCount,(int seed));
MOCK_METHOD(void, resetFailureCount,());
};


TEST(AlertCelciusTestSuite,InteractionTesting){
    NetworkAlerterMock mockObj;
    //Expectation 
      EXPECT_CALL(
          mockObj,
          alert(FloatEq(37.7778))).
          Times(1).
          WillRepeatedly(Return(500));
    //Interaction
    alertInCelcius(100.00004,&mockObj);
  
}