#ifndef __HARL_FILTER_H
#define __HARL_FILTER_H

#include <iostream>
#include <string>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl()
    {
        HarlsFunc[0] = &Harl::debug;
        HarlsFunc[1] = &Harl::info;
        HarlsFunc[2] = &Harl::warning;
        HarlsFunc[3] = &Harl::error;
    };
    ~Harl();
    void (Harl::*HarlsFunc[4])( void );
    int  complain( std::string level );
    void switchloop( std::string level );
};

#endif