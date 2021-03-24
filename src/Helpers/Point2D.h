#ifndef DATASTRUCTURES_LIB_POINT2D_H
#define DATASTRUCTURES_LIB_POINT2D_H

#include <ostream>

struct Point2D {
    float x;
    float y;
    Point2D(float, float);
    ~Point2D() = default;
    friend std::ostream& operator<<(std::ostream&, const Point2D&);
    friend bool operator==(const Point2D&, const Point2D&);
    friend bool operator<(const Point2D&, const Point2D&);
    friend bool operator>(const Point2D&, const Point2D&);
    friend bool operator<=(const Point2D&, const Point2D&);
    friend bool operator>=(const Point2D&, const Point2D&);
};

#endif //DATASTRUCTURES_LIB_POINT2D_H
