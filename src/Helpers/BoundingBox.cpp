#include "BoundingBox.h"

BoundingBox::BoundingBox(const Point2D _topLeft, const Point2D _botRight) : topLeft(_topLeft), botRight(_botRight) {}

/**
 * <summary>
 * Checks whether the box is intersecting with this box
 * </summary>
 * @param box
 * @return whether the box intersects this box
 */
bool BoundingBox::isIntersecting(const BoundingBox &box) const {
    return isWithinBox(box.topLeft)
           || isWithinBox(box.botRight)
           || isWithinBox(Point2D(box.topLeft.x, box.botRight.y))
           || isWithinBox(Point2D(box.botRight.x, box.topLeft.y));
}

/**
 * <summary>
 * Checks whether the point is within the box
 * </summary>
 * @param point
 * @return whether the Point is within the box
 */
bool BoundingBox::isWithinBox(const Point2D &point) const {
    return point.x >= topLeft.x &&
           point.y <= topLeft.y &&
           point.x <= botRight.x &&
           point.y >= botRight.y;
}

/**
 * <summary>
 * Calculate the MidPoint of the BoundingBox
 * </summary>
 * @return the MidPoint
 */
Point2D BoundingBox::getMid() const {
    return Point2D((topLeft.x + botRight.x) / 2,
                   (topLeft.y + botRight.y) / 2);
}
