//interface
class INetworkAlerter{
public:
virtual ~INetworkAlerter(){}
virtual int alert(float celcius)=0;
virtual int  getFailureCount()=0;
virtual void incrementFailureCount(int seed)=0;
virtual void resetFailureCount()=0;
};

void alertInCelcius(float farenheit,INetworkAlerter* networkAlerter);