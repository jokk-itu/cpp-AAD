#include "Point2D.h"

Point2D::Point2D(float _x, float _y) : x(_x), y(_y) {}

bool operator<(const Point2D &lp, const Point2D &rp) {
    return lp.x < rp.x && lp.y < rp.y;
}

bool operator==(const Point2D &lp, const Point2D &rp) {
    return lp.x == rp.x && lp.y == rp.y;
}

std::ostream &operator<<(std::ostream &os, const Point2D &point) {
    os << point.x << "," << point.y;
    return os;
}

bool operator>=(const Point2D &lp, const Point2D &rp) {
    return lp.x >= rp.x && lp.y >= rp.y;
}

bool operator>(const Point2D &lp, const Point2D &rp) {
    return lp.x > rp.x && lp.y > rp.y;
}

bool operator<=(const Point2D &lp, const Point2D &rp) {
    return lp.x <= rp.x && lp.y <= rp.y;
}