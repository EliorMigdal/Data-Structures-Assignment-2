#ifndef DATA_STRUCTURES_ASSIGNMENT_2_MAXHEAP_H
#define DATA_STRUCTURES_ASSIGNMENT_2_MAXHEAP_H
#include "Road.h"

class MaxHeap {
    Pair** heapData = nullptr;
    unsigned int heapSize = 0;
    unsigned int maxHeap = 0;

    inline static int leftChild(int index) {return (2*index)+1;}
    inline static int rightChild(int index) {return (2*index)+2;}
    inline static int parent(int index) {return (index-1)/2;}
public:
    MaxHeap() = default;
    MaxHeap(int) noexcept(false);
    MaxHeap(Road*, int) noexcept(false);
    ~MaxHeap();

    void fixHeap(int);
    unsigned int Max() {return heapData[MAX_IN_HEAP]->mutualPointer->getRoadNumber();}
    unsigned int DeleteMax() noexcept(false);
    void insert(Road*) noexcept(false);
};

#endif //DATA_STRUCTURES_ASSIGNMENT_2_MAXHEAP_H