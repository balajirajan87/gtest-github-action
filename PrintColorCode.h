#include <functional>
int printColorMap(void(*printer)(int colorCode,const char* majorColor,const char* minorColor));

class IPrinter{
public:
      virtual ~IPrinter(){}
      virtual void print(int colorCode,const char* majorColor,const char* minorColor)=0;
};

int printColorMap(IPrinter* printer);

int printColorMap(std::function<void(int,const char*,const char*)> printer);