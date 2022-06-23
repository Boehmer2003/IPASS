//
// Created by benja on 23/06/2022.
//

#ifndef V1OOPC_EXAMPLES_SUPERCLASS_HPP
#define V1OOPC_EXAMPLES_SUPERCLASS_HPP
#include "hwlib.hpp"

class superclass {


    virtual void starting()=0;
public:
    virtual int test()=0;
    virtual int getGyrox()=0;
    virtual int getGyroy()=0;
    virtual int getGyroz()=0;
    virtual int getaccelx()=0;
    virtual int getaccely()=0;
    virtual int getaccelz()=0;
    virtual int temperature()=0;
};


#endif //V1OOPC_EXAMPLES_SUPERCLASS_HPP
