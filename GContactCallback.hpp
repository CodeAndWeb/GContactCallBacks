//
//  GContactCallback.h
//
//  This class contains the callbacks to call any function inside another class
//  You do not need to use the classes directly. Just use the Macros to register the
//  callbacks
//
//  To register a beginning contact callback use
//
//  BEGIN_COLLISION(A, B)
//  this registers a method A::beginContactWithB(other, collision);
//  which can be called when the contact between A and B begins
//
//  END_COLLISION(A, B)
//  this registers a method A::endContactWithB(other, collision);
//  which can be called when the contact between A and B ends
//
//  Copyright by Andreas Loew / http://www.codeandweb.com
//
//  All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
#pragma once

#include "GCollisionRegistry.hpp"

class Collision;

/**
 * This class provides an interface to call collision functions
 */
class GContactCallbackBase
{
public:
    virtual ~GContactCallbackBase()
    {}

    virtual void collide( Object *receiver, Object *otherObject, Collision *c ) = 0;
};

/**
 * This template class adapts to the destination object and provides
 * a method to call the registered function
 */
template <class T> class GContactCallback : public GContactCallbackBase
{
public:

    /**
     * Register a callback function to be called from collide()
     * @param ftp pointer to the method to call
     */
    GContactCallback(void(T::*fpt)( Object *otherObject, Collision *c ))
    {
        mFpt=fpt;
    };

    /**
     * Calls the registered collision function on receiver,
     * using otherObject and c as parameter
     * @param receiver object to call the callback on
     * @param otherObject parameter to pass to the callback function
     * @param c collision parameter to pass to the callback object
     */
    virtual void collide(Object *receiver, Object *otherObject, Collision *c)
    {
        T* r = dynamic_cast<T*>(receiver);
        (*r.*mFpt)(otherObject, c);
    };

private:
   void(T::*mFpt)(Object *otherObject, Collision *c);
};

/**
 * Macro to register the A:beginContactWithB()
 * @param A class to call the methon on
 * @param B class which A collides with
 */
#define BEGIN_COLLISION(A,B) static bool gBeginContact_##A_##B_registered = theCollisionRegistry()->registerCollision(#A"::beginContactWith"#B,new GContactCallback<A>(&A::begin##ContactWith##B));

/**
 * Macro to register the A:endContactWithB()
 * @param A class to call the methon on
 * @param B class which A collides with
 */
#define END_COLLISION(A,B) static bool gEndContact_##A_##B_registered = theCollisionRegistry()->registerCollision(#A"::endContactWith"#B,new GContactCallback<A>(&A::end##ContactWith##B));

