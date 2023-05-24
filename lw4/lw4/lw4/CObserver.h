#pragma once

class CObserver 
{
public:
    virtual void Update(void (*f)(CObserver*)) = 0;
};