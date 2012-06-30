#include "ObjectB.hpp"
#include "GContactCallback.hpp"

#include <iostream>
using namespace std;

BEGIN_COLLISION(ObjectB, ObjectA)

void ObjectB::beginContactWithObjectA(Object* otherObject, Collision *c)
{
    cout << "begin contact with B (" << otherObject->nameForObject() << ")" << endl;
}

