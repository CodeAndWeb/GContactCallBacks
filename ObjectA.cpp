#include "ObjectA.hpp"
#include "GContactCallback.hpp"

#include <iostream>
using namespace std;

BEGIN_COLLISION(ObjectA, ObjectB)
END_COLLISION(ObjectA, ObjectB)

void ObjectA::beginContactWithObjectB(Object* otherObject, Collision *c)
{
    cout << "begin contact with B (" << otherObject->nameForObject() << ")" << endl;
}

void ObjectA::endContactWithObjectB(Object* otherObject, Collision *c)
{
    cout << "end contact with B (" << otherObject->nameForObject() << ")" << endl;
}
