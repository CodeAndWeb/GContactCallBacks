#pragma once

#include "Object.hpp"

class Collision;

class ObjectA: public Object
{
public:
    // create nameForObject();
    COLLISION_OBJECT(ObjectA)

    // callback for beginning contact with B
    void beginContactWithObjectB(Object* otherObject, Collision *c);

    // callback for ending contact with B
    void endContactWithObjectB(Object* otherObject, Collision *c);
};
