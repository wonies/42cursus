#ifndef __SED_H
#define __SED_H

#include <iostream>
#include <fstream>
#include "stream.hpp"

class Sed
{
private:
    FileSystem _fname;
    std::string _src;
    std::string _dest;
public:
   Sed(const std::string &_fname, const std::string &_src, const std::string &_dest);
   void  program(void);
};


#endif