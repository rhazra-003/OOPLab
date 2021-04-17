#ifndef PROJ2_SCISSORS_H
#define PROJ2_SCISSORS_H

#include "Tool.h"

class Scissors : public Tool
{
public:
    Scissors(int s)
    {
        setStrength(s);
        type = 's';
    }
};

#endif //PROJ2_SCISSORS_H