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

public:
    BinomialHeap();
    ~BinomialHeap() = default;

    const unsigned int size() const;
    bool empty() const;
    void pop();
    const T& top();
    void push(T&);
    //front : iterator
    //back : iterator
};

template<typename T, class Compare>
BinomialHeap<T, Compare>::BinomialHeap() : N(0), comparator() {}

template<typename T, class Compare>
const unsigned int BinomialHeap<T, Compare>::size() const {
    return N;
}

template<typename T, class Compare>
bool BinomialHeap<T, Compare>::empty() const {
    return N == 0;
}

template<typename T, class Compare>
void BinomialHeap<T, Compare>::pop() {
    //iterate the heap for the top element
    //merge the children of the top element
    //delete the top element
    //insert that new merged tree into the heap
}

template<typename T, class Compare>
void BinomialHeap<T, Compare>::push(T& value) {
    auto node = std::make_shared<Node>(value);
    //check the first entry for same order
    //if the same order exists, start merge, recurse check through the heap
    //N++
}

template<typename T, class Compare>
const T& BinomialHeap<T, Compare>::top() {
    setTop();
    return *_top;
}

template<typename T, class Compare>
void BinomialHeap<T, Compare>::setTop() {
    T prioritised = heap.front();
    for(auto &tree : heap) {
        prioritised = (comparator(prioritised, tree)) ? prioritised : tree;
    }
}

#endif //DATASTRUCTURES_LIB_BINOMIALHEAP_H
