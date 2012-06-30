#pragma once

class Object
{
public:
    virtual ~Object()
    {}

    virtual const char *nameForObject() const = 0;
};

#define COLLISION_OBJECT(A) const char *nameForObject() const {return #A;}
