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
        T value;
        int order;
        std::shared_ptr<Node> parent;
        std::shared_ptr<Node> sibling;
        std::shared_ptr<Node> child;
        Node() : order(0) {};
        explicit Node(T value) : order(0), value(value) {};
        Node(T value, int order) : order(order), value(value) {};
        ~Node() = default;
    };

    unsigned int N;
    std::unique_ptr<T> min;
    std::list<std::shared_ptr<Node>> heap;
    const Compare comparator;

public:
    BinomialHeap();
    ~BinomialHeap() = default;

    const unsigned int size() override const;
    const bool empty() override const;
    void pop();
    const T& top();
    void push();
    //front : iterator
    //back : iterator
};

template<typename T, class Compare>
BinomialHeap<T, Compare>::BinomialHeap() : N(0) {}

template<typename T, class Compare>
unsigned int BinomialHeap<T, Compare>::size() {
    return N;
}

template<typename T, class Compare>
bool BinomialHeap<T, Compare>::empty() {
    return N == 0;
}

template<typename T, class Compare>
void BinomialHeap<T, Compare>::pop() {
    return;
}

template<typename T, class Compare>
void BinomialHeap<T, Compare>::push() {
    return;
}

template<typename T, class Compare>
T& BinomialHeap<T, Compare>::top() {

}

#endif //DATASTRUCTURES_LIB_BINOMIALHEAP_H
