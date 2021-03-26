#ifndef DATASTRUCTURES_LIB_BINOMIALHEAP_H
#define DATASTRUCTURES_LIB_BINOMIALHEAP_H

#include <memory>
#include <list>
#include <algorithm>
#include <vector>
#include <exception>
#include <queue>

template<typename T, class Compare = std::less<T>>
class BinomialHeap {
private:
    struct Node {
        const T value;
        unsigned int order;
        std::shared_ptr<Node> parent;
        std::shared_ptr<Node> sibling;
        std::shared_ptr<Node> child;
        Node() : order(0) {};
        explicit Node(T _value) : order(0), value(_value) {};
        Node(T _value, int _order) : order(_order), value(_value) {};
        ~Node() = default;
    };

    unsigned int N;
    std::unique_ptr<const T> _top;
    std::list<std::shared_ptr<Node>> heap;
    const Compare comparator;

    void setTop();
    std::shared_ptr<Node> getTop();

public:
    BinomialHeap();
    ~BinomialHeap() = default;

    const unsigned int size() const;
    bool empty() const;
    void pop();
    const T& top();
    void push(const T);
    //front : iterator
    //back : iterator
};

template<typename T, class Compare>
BinomialHeap<T, Compare>::BinomialHeap() : N(0), comparator() {}

/**
 * <summary>
 * Returns the size of the heap as an unsigned int
 * Since the size can't be negative
 * </summary>
 * @tparam T
 * @tparam Compare
 * @return size of heap
 */
template<typename T, class Compare>
const unsigned int BinomialHeap<T, Compare>::size() const {
    return N;
}

/**
 * <summary>
 * Returns whether the heap is empty
 * </summary>
 * @tparam T
 * @tparam Compare
 * @return is heap empty
 */
template<typename T, class Compare>
bool BinomialHeap<T, Compare>::empty() const {
    return N == 0;
}

/**
 * <summary>
 * Pops the top node off the heap
 * Then merges the new tree into the heap
 * </summary>
 * @tparam T
 * @tparam Compare
 */
template<typename T, class Compare>
void BinomialHeap<T, Compare>::pop() {
    getTop();
    //merge the children of the top element
    //delete the top element
    //--N
    //insert that new merged tree into the heap
}

/**
 * <summary>
 * Inserts a new value into the heap
 * Then merges the new node inside the heap
 * It does so recursively
 * </summary>
 * @tparam T
 * @tparam Compare
 * @param value
 */
template<typename T, class Compare>
void BinomialHeap<T, Compare>::push(const T value) {
    auto node = std::make_shared<Node>(value);
    if(!_top || comparator(value, *_top))
        _top = std::make_unique<const T>(value);

    if(heap.front()->order == 0) {
        //if the same order exists, start merge, recurse check through the heap
    }
    ++N;
}

/**
 * <summary>
 * Get the top value as a const reference
 * </summary>
 * @tparam T
 * @tparam Compare
 * @return the top
 */
template<typename T, class Compare>
const T& BinomialHeap<T, Compare>::top() {
    setTop();
    return *_top;
}

/**
 * <summary>
 * Iterates the heap, and sets the value from the top node
 * </summary>
 * @tparam T
 * @tparam Compare
 */
template<typename T, class Compare>
void BinomialHeap<T, Compare>::setTop() {
    auto prioritised = heap.front()->value;
    for(auto &tree : heap) {
        prioritised = (comparator(prioritised, tree->value)) ? prioritised : tree->value;
    }
    _top = std::make_unique<const T>(prioritised);
}

/**
 * <summary>
 * Returns an iterator of the top node in the heap
 * </summary>
 * @tparam T
 * @tparam Compare
 * @return top node in heap
 */
template<typename T, class Compare>
std::shared_ptr<typename BinomialHeap<T, Compare>::Node>
BinomialHeap<T, Compare>::getTop() {
    auto prioritised = heap.begin();
    for(auto &tree : heap) {
        prioritised = (comparator(prioritised->value, tree->value)) ? prioritised : tree;
    }
    return prioritised;
}

#endif //DATASTRUCTURES_LIB_BINOMIALHEAP_H
