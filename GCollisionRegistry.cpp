#include "GCollisionRegistry.hpp"
#include "GContactCallback.hpp"
#include "Object.hpp"

#include <iostream>
#include "stdio.h"

using namespace std;

GCollisionRegistry* theCollisionRegistry()
{
    static GCollisionRegistry* instance = new GCollisionRegistry();
    return instance;
}


GCollisionRegistry::GCollisionRegistry()
{
}

bool GCollisionRegistry::registerCollision(const char *name, GContactCallbackBase *callBack)
{
    cout << "registering " << name << " as " << (long)callBack << endl;
    mCallBackMap[std::string(name)] = callBack;
    return true;
}

void GCollisionRegistry::callCollision(Object *from, Object *to, Collision *c, const char *beginEnd)
{
    const char *nameA = from->nameForObject();
    const char *nameB = to->nameForObject();
    char functionName[255];
    sprintf(functionName, "%s::%sContactWith%s", nameA, beginEnd, nameB);

    map<string,GContactCallbackBase*>::const_iterator it = mCallBackMap.find(functionName);
    if(it != mCallBackMap.end())
    {
        (*it).second->collide(from, to, c);
    }
}
