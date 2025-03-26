 #pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"


class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> _targetList;
        TargetGenerator(TargetGenerator const &src);
        TargetGenerator &operator=(TargetGenerator const &src);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *);
        void forgetTargetType(std::string const &);
        ATarget *createTarget(std::string const &);
    
};