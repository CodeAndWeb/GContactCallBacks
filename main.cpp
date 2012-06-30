#include "GContactCallback.hpp"

#include "ObjectA.hpp"
#include "ObjectB.hpp"

#include "Collision.hpp"

#include "GCollisionRegistry.hpp"

int main(int argc, char**argv)
{
    // create some objects
    ObjectA *a1 = new ObjectA();
    ObjectB *b1 = new ObjectB();
    Collision *c = new Collision();

    // call the collision callbacks
    theCollisionRegistry()->callCollision(a1, b1, c, "begin");
    theCollisionRegistry()->callCollision(a1, b1, c, "end");

    theCollisionRegistry()->callCollision(b1, a1, c, "begin");
    theCollisionRegistry()->callCollision(b1, a1, c, "end"); // that one is not registered
}

