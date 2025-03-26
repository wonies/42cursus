#pragma once

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> _targetList;
        TargetGenerator(TargetGenerator const &src);
        TargetGenerator& operator=(TargetGenerator const &src);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *ptr);
        void forgetTargetType(std::string  const &type);
        ATarget *createTarget(std::string const &type);
};