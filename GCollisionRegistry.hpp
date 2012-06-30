#pragma once

#include <map>

class GContactCallbackBase;
class Collision;
class Object;

class GCollisionRegistry
{
public:
    bool registerCollision(const char *name, GContactCallbackBase *callBack);
    void callCollision(Object *from, Object *to, Collision *c, const char *beginEnd);
private:
    GCollisionRegistry();
    friend GCollisionRegistry* theCollisionRegistry();

    std::map<std::string, GContactCallbackBase *> mCallBackMap;
};

GCollisionRegistry* theCollisionRegistry();

