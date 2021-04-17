#ifndef PROJ2_ROCK_H
#define PROJ2_ROCK_H

#include "Tool.h"

class Rock : public Tool
{
public:
    Rock(int s)
    {
        setStrength(s);
        type = 'r';
    }
};

#endif //PROJ2_ROCK_H