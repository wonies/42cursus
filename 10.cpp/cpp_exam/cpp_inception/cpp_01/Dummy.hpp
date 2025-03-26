#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget{
    public:
        Dummy();
        ~Dummy();
        // ATarget clone();
        virtual ATarget *clone() const;
};