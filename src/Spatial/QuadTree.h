#ifndef DATASTRUCTURES_QUADTREE_H
#define DATASTRUCTURES_QUADTREE_H

#include <memory>
#include <vector>
#include <cmath>
#include <iostream>
#include <exception>
#include <map>
#include "../Exceptions/PointNotWithinBoxException.cpp"
#include "../Exceptions/BoxOutOfBoundsException.cpp"
#include "../Exceptions/BoxPositionIsNotSupportedException.cpp"
#include "../Helpers/Point2D.h"
#include "../Helpers/BoundingBox.h"
#include "../Helpers/BoxPosition.cpp"

template<typename T>
class QuadTree {
    struct Node {
        Node() = default;
        virtual ~Node() = default;
    };
    struct Internal : public Node {
        std::shared_ptr<Node> topLeft;
        std::shared_ptr<Node> topRight;
        std::shared_ptr<Node> botLeft;
        std::shared_ptr<Node> botRight;
        Internal() = default;
        ~Internal() override = default;
    };
    struct Leaf : public Node {
        std::map<Point2D, T> data;
        explicit Leaf(std::pair<const Point2D, T> _data) : Node() {
            data[_data.first] = _data.second;
        }
        ~Leaf() override = default;
    };

private:
    std::shared_ptr<Node> root;
    std::unique_ptr<BoundingBox> box;
    const float THRESHOLD = 1.0F;

    std::shared_ptr<QuadTree::Node> insert(const std::pair<Point2D, T>&, const std::shared_ptr<Node>&, const BoundingBox&);
    void search(const BoundingBox&, const std::shared_ptr<Node>&, std::vector<std::pair<const Point2D, T>>&, const BoundingBox&);
    std::shared_ptr<QuadTree::Node> remove(const Point2D&, const std::shared_ptr<Node>&, const BoundingBox&);

    Point2D getMid(const BoundingBox&);
    BoxPosition getPosition(const BoundingBox&, const Point2D&);
    bool isBoxThresholdReached(const BoundingBox&);
    BoundingBox getBoundingBox(BoxPosition&&, const BoundingBox&);
    bool isBoundary(const Point2D&, const BoundingBox&);
    bool isBoundary(const BoundingBox&, const BoundingBox&);

public:
    explicit QuadTree(const BoundingBox);
    QuadTree(const std::vector<std::pair<Point2D, T>>&, const BoundingBox);
    ~QuadTree();

    std::vector<std::pair<const Point2D, T>> search(const BoundingBox&);
    void insert(const std::pair<Point2D, T>&);
    void remove(const Point2D&);
};

#include "QuadTree.tpp"

#endif //DATASTRUCTURES_QUADTREE_H
