#ifndef PROJ2_TOOL_H
#define PROJ2_TOOL_H

class Tool {
protected:
    int strength;
    char type;

public:
    Tool(): strength{0}, type{'n'}
    {}

    void setStrength(int s)
    {
        strength = s;
    }

    bool fight(Tool t)
    {
        if(type == 'r')
        {
            if(t.type == 'p')
                return 0.5 * static_cast<float>(strength) > t.strength;
            else
                return 2 * strength > t.strength;
        }
        else if(type == 'p')
        {
            if(t.type == 'r')
                return 2 * strength > t.strength;
            else
                return 0.5 * static_cast<float>(strength) > t.strength;
        }
        else
        {
            if(t.type == 'r')
                return 0.5 * static_cast<float>(strength) > t.strength;
            else
                return 2 * strength > t.strength;
        }
    }
};

#endif //PROJ2_TOOL_H