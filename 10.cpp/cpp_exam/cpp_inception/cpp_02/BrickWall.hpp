#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget{
    public:
        BrickWall();
        ~BrickWall();
        // ATarget clone();
        virtual ATarget *clone() const;
};