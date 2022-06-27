// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   Gyroscope.hpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


#ifndef V1OOPC_EXAMPLES_GYROSCOPE_HPP
#define V1OOPC_EXAMPLES_GYROSCOPE_HPP
class gyroscope{
    public:
    virtual int getGyrox()=0;
    virtual int getGyroy()=0;
    virtual int getGyroz()=0;







};



#endif //V1OOPC_EXAMPLES_GYROSCOPE_HPP
