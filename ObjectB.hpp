#pragma once

#include "Object.hpp"

class Collision;

class ObjectB: public Object
{
public:
    // create nameForObject();
    COLLISION_OBJECT(ObjectB)

    // callback for beginning contact with A
    void beginContactWithObjectA(Object* otherObject, Collision *c);
};
