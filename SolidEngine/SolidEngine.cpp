//
//  SolidEngine.cpp
//  SolidEngine
//
//  Created by YING JIEH XIA on 2025/1/18.
//

#include <iostream>
#include "SolidEngine.hpp"
#include "SolidEnginePriv.hpp"

void SolidEngine::HelloWorld(const char * s)
{
    SolidEnginePriv *theObj = new SolidEnginePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void SolidEnginePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

