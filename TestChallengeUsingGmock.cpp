#include "TestChallengeUsingGmock.h"

//RealTime Implementation
class RealTimeNetowrkAleter :public INetworkAlerter{
private : int failureCount=0;
public:

 int alert(float celcius){ return 200;}
 int  getFailureCount(){ return failureCount;}
 void incrementFailureCount(int seed) { failureCount+=seed;}

  void resetFailureCount(){ failureCount=0;}

};

void alertInCelcius(float farenheit,INetworkAlerter* networkAlerter){

   float celcius = (farenheit - 33) * 5 / 9;
    int returnCode = networkAlerter->alert(celcius);
    if (returnCode != 200) {
        networkAlerter-> incrementFailureCount(1);
     
    }
}