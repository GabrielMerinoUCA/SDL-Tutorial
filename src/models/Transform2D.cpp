#include "Transform2D.hpp"

void Transform2D::setDimensions(const Vector2 &dimensions) {
    this->dimensions = dimensions;
}

void Transform2D::setAbsolutePosition(const Vector2 &absolutePosition) {
    this->absolutePosition = absolutePosition;
    relativePosition = NULL;
    positionOffset = {x: 0, y: 0};
}

void Transform2D::setRelativePosition(
        const Vector2 &relativePosition, 
        const Vector2 &positionOffset
    ) 
{
    this->relativePosition = &relativePosition;
    this->positionOffset = positionOffset;
    absolutePosition = {x: 0, y: 0};
}

bool Transform2D::setPositionOffset(const Vector2 &positionOffset) {
    if(this->isRelativePositionSet()) {
        this->positionOffset = positionOffset;
        return true;
    } 
    LOG("[ERROR]: Cannot set a position offset if relative position isn't being used!");
    return false;
}

SDL_Rect Transform2D::createRect() const {
    SDL_Rect rect;
    if(this->isRelativePositionSet()) {
        rect = {
            x: relativePosition->x + positionOffset.x,
            y: relativePosition->y + positionOffset.y,
            w: dimensions.x,
            h: dimensions.y
        };
        return rect;
    }
    rect = {
        x: absolutePosition.x,
        y: absolutePosition.y,
        w: dimensions.x,
        h: dimensions.y
    };
    return rect;
}

bool Transform2D::isRelativePositionSet() const {
    return relativePosition != NULL;
}

Transform2D::Transform2D(const Vector2 &dimensions) :
    dimensions(dimensions),
    absolutePosition({0, 0}),
    relativePosition(NULL),
    positionOffset({0, 0})
{ }