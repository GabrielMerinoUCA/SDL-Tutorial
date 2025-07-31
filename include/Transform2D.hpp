#pragma once
#include <SDL2/SDL.h>
#include "Vector2.hpp"
#include "global.hpp"

class Transform2D {
//Attributes
public:
    // should be linked to the Game entity, used only if absolutePosition is 0
    Vector2 dimensions;
    
protected:
    Vector2 positionOffset; // this is like the actual relative position but whatever
    const Vector2 *relativePosition; // this one is like the origin position
    Vector2 absolutePosition;

//Methods
public:
    virtual void setDimensions(const Vector2 &dimensions);
    /**
     * Sets absolutePosition while restarting positionOffset and relativePosition to 0/NULL
     * @param absolutePosition is the position relative to the window
     */
    virtual void setAbsolutePosition(const Vector2 &absolutePosition);
    /**
     * Sets relativePosition where 
     * @param relativePosition is the origin position and 
     * @param positionOffset is the position relative to it
     */
    virtual void setRelativePosition(const Vector2 &relativePosition, const Vector2 &positionOffset);
    /**
     * @return false if the relative position isn't set; thus ins't being used
     */
    virtual bool setPositionOffset(const Vector2 &positionOffset);
    virtual SDL_Rect createRect() const;

protected:
    virtual bool isRelativePositionSet() const;
    Transform2D();
    Transform2D(const Vector2 &dimensions);
};