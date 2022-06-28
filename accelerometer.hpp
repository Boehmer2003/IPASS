// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   Accelerometer.hpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


#ifndef V1OOPC_EXAMPLES_ACCELEROMETER_HPP
#define V1OOPC_EXAMPLES_ACCELEROMETER_HPP

class accelerometer {
public:
    virtual int getaccelx() = 0;

    virtual int getaccely() = 0;

    virtual int getaccelz() = 0;


};


#endif //V1OOPC_EXAMPLES_ACCELEROMETER_HPP
