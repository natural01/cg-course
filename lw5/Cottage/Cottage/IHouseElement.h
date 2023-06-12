#pragma once

class IHouseElement
{
public:
    IHouseElement& operator=(const IHouseElement&) = delete;
    virtual void Draw() const = 0;

protected:
    virtual ~IHouseElement() = default;
};