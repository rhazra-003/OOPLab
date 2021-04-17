#ifndef PROJ2_PAPER_H
#define PROJ2_PAPER_H

#include "Tool.h"

class Paper : public Tool
{
public:
    Paper(int s)
    {
        setStrength(s);
        type = 'p';
    }
};

#endif //PROJ2_PAPER_H