#pragma once
#include "CObserver.h"

class CObservable 
{
public:
    virtual void notifyObservers() = 0;
};