#ifndef DATASTRUCTURES_LIB_BOUNDINGBOX_H
#define DATASTRUCTURES_LIB_BOUNDINGBOX_H

#include "Point2D.h"

struct BoundingBox {
    const Point2D topLeft;
    const Point2D botRight;
    BoundingBox(Point2D, Point2D);
    ~BoundingBox() = default;
    bool isIntersecting(const BoundingBox&) const;
    bool isWithinBox(const Point2D&) const;
    Point2D getMid() const;
};


#endif //DATASTRUCTURES_LIB_BOUNDINGBOX_H
