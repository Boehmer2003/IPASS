// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   Gyroscope.hpp
//       Part of :   IPASS
//
//       Copyright Benjamin Boehmer 2022.
//
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
