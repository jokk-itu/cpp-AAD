template<typename T>
QuadTree<T>::QuadTree(const BoundingBox _box) {
    box = std::make_unique<BoundingBox>(_box);
    root = std::make_shared<Internal>();
}

template<typename T>
QuadTree<T>::QuadTree(const std::vector<std::pair<Point2D, T>> &points, const BoundingBox _box) {
    root = std::make_shared<Internal>();
    box = std::make_unique<BoundingBox>(_box);

    for (auto &point : points) {
        insert(point);
    }
}

template<typename T>
QuadTree<T>::~QuadTree() = default;

/**
 * <summary>
 * Removes a Point and its' accompanying data
 * </summary>
 * @tparam T
 */
template<typename T>
void QuadTree<T>::remove(const Point2D &point) {
    auto temp = std::dynamic_pointer_cast<Internal>(root);
    if (!box->isWithinBox(point))
        throw PointNotWithinBoxException();
    root = remove(point, root, *box);
}

/**
 * <summary>
 * Removes a Point and its' accompanying data.
 * Does so by iterating recursively until a Leaf is reached,
 * then removes the Point and the data it holds.
 * </summary>
 * @tparam T
 */
template<typename T>
std::shared_ptr<typename QuadTree<T>::Node>
QuadTree<T>::remove(const Point2D &point, const std::shared_ptr<Node> &node, const BoundingBox &_box) {
    auto leafNode = std::dynamic_pointer_cast<Leaf>(node);
    if (isBoxThresholdReached(_box) && leafNode) {
        if (leafNode->data.contains(point)) {
            leafNode->data.erase(leafNode->data.find(point));
            if(leafNode->data.empty())
                return nullptr;
            return node;
        }
        throw std::invalid_argument("The Point does not exist");
    } else if(isBoxThresholdReached(_box)) {
        throw std::invalid_argument("The Point does not exist");
    }

    auto internalNode = std::dynamic_pointer_cast<Internal>(node);
    switch (getPosition(_box, point)) {
        case TOPLEFT: {
            auto topLeftBox = getBoundingBox(TOPLEFT, _box);
            internalNode->topLeft = !internalNode->topLeft
                                    ? remove(point, std::make_shared<Internal>(), topLeftBox)
                                    : remove(point, internalNode->topLeft, topLeftBox);
            break;
        }
        case TOPRIGHT: {
            auto topRightBox = getBoundingBox(TOPRIGHT, _box);
            internalNode->topRight = !internalNode->topRight
                                     ? remove(point, std::make_shared<Internal>(), topRightBox)
                                     : remove(point, internalNode->topRight, topRightBox);
            break;
        }
        case BOTLEFT: {
            auto botLeftBox = getBoundingBox(BOTLEFT, _box);
            internalNode->botLeft = !internalNode->botLeft
                                    ? remove(point, std::make_shared<Internal>(), botLeftBox)
                                    : remove(point, internalNode->botLeft, botLeftBox);
            break;
        }
        case BOTRIGHT: {
            auto botRightBox = getBoundingBox(BOTRIGHT, _box);
            internalNode->botRight = !internalNode->botRight
                                     ? remove(point, std::make_shared<Internal>(), botRightBox)
                                     : remove(point, internalNode->botRight, botRightBox);
            break;
        }
        default:
            throw BoxPositionIsNotSupportedException();
    }
    return internalNode;
}


/**
 * <summary>
 * Inserts a point into the tree
 * </summary>
 * @param point
 */
template<typename T>
void QuadTree<T>::insert(const std::pair<Point2D, T> &data) {
    auto temp = std::dynamic_pointer_cast<Internal>(root);
    if (!box->isWithinBox(data.first))
        throw PointNotWithinBoxException();
    root = insert(data, root, *box);
}

/**
 * <summary>
 * Inserts a point recursively into the tree.
 * It rebuilds the tree after insertion.
 * </summary>
 * @param point
 * @param node
 * @param _box
 * @return rebuilding node, ending with the root
 */
template<typename T>
std::shared_ptr<typename QuadTree<T>::Node>
QuadTree<T>::insert(const std::pair<Point2D, T> &data, const std::shared_ptr<Node> &node, const BoundingBox &_box) {
    auto leafNode = std::dynamic_pointer_cast<Leaf>(node);
    if (isBoxThresholdReached(_box) && !leafNode) {
        return std::make_shared<Leaf>(data);
    } else if (isBoxThresholdReached(_box) && leafNode) {
        leafNode->data[data.first] = data.second;
        return leafNode;
    }
    auto internalNode = std::dynamic_pointer_cast<Internal>(node);
    switch (getPosition(_box, data.first)) {
        case TOPLEFT: {
            auto topLeftBox = getBoundingBox(TOPLEFT, _box);
            internalNode->topLeft = !internalNode->topLeft
                                    ? insert(data, std::make_shared<Internal>(), topLeftBox)
                                    : insert(data, internalNode->topLeft, topLeftBox);
            break;
        }
        case TOPRIGHT: {
            auto topRightBox = getBoundingBox(TOPRIGHT, _box);
            internalNode->topRight = !internalNode->topRight
                                     ? insert(data, std::make_shared<Internal>(), topRightBox)
                                     : insert(data, internalNode->topRight, topRightBox);
            break;
        }
        case BOTLEFT: {
            auto botLeftBox = getBoundingBox(BOTLEFT, _box);
            internalNode->botLeft = !internalNode->botLeft
                                    ? insert(data, std::make_shared<Internal>(), botLeftBox)
                                    : insert(data, internalNode->botLeft, botLeftBox);
            break;
        }
        case BOTRIGHT: {
            auto botRightBox = getBoundingBox(BOTRIGHT, _box);
            internalNode->botRight = !internalNode->botRight
                                     ? insert(data, std::make_shared<Internal>(), botRightBox)
                                     : insert(data, internalNode->botRight, botRightBox);
            break;
        }
        default:
            throw BoxPositionIsNotSupportedException();
    }
    return internalNode;
}

/**
 * <summary>
 * Search for points inside a BoundingBox
 * </summary>
 * @param query
 * @return all the points inside the given BoundingBox
 */
template<typename T>
std::vector<std::pair<const Point2D, T>> QuadTree<T>::search(const BoundingBox &query) {
    auto temp = std::dynamic_pointer_cast<Internal>(root);
    if (!box->isIntersecting(query))
        throw BoxOutOfBoundsException();

    std::vector<std::pair<const Point2D, T>> points;
    search(query, root, points, *box);
    return points;
}

/**
 * <summary>
 * Searching the tree recursively, for points inside a given query BoundingBox
 * </summary>
 * @param query
 * @param node
 * @param points
 * @param _box
 */
template<typename T>
void QuadTree<T>::search(const BoundingBox &query,
                         const std::shared_ptr<Node> &node,
                         std::vector<std::pair<const Point2D, T>> &points,
                         const BoundingBox &_box) {
    if (!node)
        return;

    auto internalNode = std::dynamic_pointer_cast<Internal>(node);
    if (!internalNode) {
        auto leafNode = std::dynamic_pointer_cast<Leaf>(node);
        for (auto &pair : leafNode->data) {
            points.push_back(pair);
        }
        return;
    }

    auto topLeft(getBoundingBox(TOPLEFT, _box));
    auto topRight(getBoundingBox(TOPRIGHT, _box));
    auto botLeft(getBoundingBox(BOTLEFT, _box));
    auto botRight(getBoundingBox(BOTRIGHT, _box));

    if (query.isIntersecting(topLeft) || topLeft.isIntersecting(query))
        search(query, internalNode->topLeft, points, topLeft);
    if (query.isIntersecting(botRight) || botRight.isIntersecting(query))
        search(query, internalNode->botRight, points, botRight);
    if (query.isIntersecting(topRight) || topRight.isIntersecting(query))
        search(query, internalNode->topRight, points, topRight);
    if (query.isIntersecting(botLeft) || botLeft.isIntersecting(query))
        search(query, internalNode->botLeft, points, botLeft);
}

/**
 * <summary>
 * Gets a BoxPosition calculated by the given BoundingBox and a point inside the BoundingBox
 * </summary>
 * @param _box
 * @param point
 * @return the Position of the point inside the given BoundingBox
 */
template<typename T>
BoxPosition QuadTree<T>::getPosition(const BoundingBox &_box, const Point2D &point) {
    if (!_box.isWithinBox(point))
        throw PointNotWithinBoxException();

    if (getBoundingBox(TOPLEFT, _box).isWithinBox(point))
        return TOPLEFT;
    else if (getBoundingBox(BOTLEFT, _box).isWithinBox(point))
        return BOTLEFT;
    else if (getBoundingBox(TOPRIGHT, _box).isWithinBox(point))
        return TOPRIGHT;
    else
        return BOTRIGHT;
}

/**
 * <summary>
 * Used to determine whether a BoundingBox has reached the Threshold.
 * Then the BoundingBox can contain LeafNodes or InternalNodes.
 * </summary>
 * @param _box
 * @return whether the BoundingBox has reached Threshold of being a LeafNode
 */
template<typename T>
bool QuadTree<T>::isBoxThresholdReached(const BoundingBox &_box) {
    return std::abs(_box.topLeft.x - _box.botRight.x) <= THRESHOLD &&
           std::abs(_box.topLeft.y - _box.botRight.y) <= THRESHOLD;
}

/**
 * Getting one of the four BoundingBoxes inside a given BoundingBox
 * @param pos
 * @param _box
 * @return one of four BoundingBoxes
 */
template<typename T>
BoundingBox QuadTree<T>::getBoundingBox(BoxPosition &&pos, const BoundingBox &_box) {
    auto mid = _box.getMid();
    switch (pos) {
        case TOPLEFT:
            return BoundingBox(_box.topLeft, mid);
        case TOPRIGHT:
            return BoundingBox(Point2D(mid.x, _box.topLeft.y),
                               Point2D(_box.botRight.x, mid.y));
        case BOTLEFT:
            return BoundingBox(Point2D(_box.topLeft.x, mid.y),
                               Point2D(mid.x, _box.botRight.y));
        case BOTRIGHT:
            return BoundingBox(mid, _box.botRight);
        default:
            throw BoxPositionIsNotSupportedException();
    }
}


