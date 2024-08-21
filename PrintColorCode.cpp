#include <iostream>
#include <assert.h>
#include "PrintColorCode.h"

void printOnTerminal(int colorCode,const char* majorColor,const char* minorColor){
    std::cout<<colorCode<<"|"<<majorColor<<"|"<<minorColor<<std::endl;
}
int printColorMap(void (*printer)(int colorCode,const char* majorColor,const char* minorColor)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printer(i * 5 + j , majorColor[i], minorColor[i] );
            //std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

//C++
int printColorMap(IPrinter* printer){
 const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printer->print(i * 5 + j , majorColor[i], minorColor[i] );
            //std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

//C++
int printColorMap(std::function<void(int,const char*,const char*)> printer){
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printer(i * 5 + j , majorColor[i], minorColor[i] );
            //std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}