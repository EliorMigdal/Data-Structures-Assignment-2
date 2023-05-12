#include "MaxHeap.h"

//------------------------------------------------------
MaxHeap::MaxHeap(Road *arrOfRoads, int n) noexcept(false) //Floyd's algorithm w/out fixHeap; Time complexity: Tetha(n);
{
    this->heapSize = this->maxHeap = n;
    try{heapData = new Pair*[n];}
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
    try{
        for (int i = 0; i < n; i++) //Time complexity: Tetha(n);
        {
            heapData[i] = new Pair;
            heapData[i]->heapIndex = i;
            heapData[i]->mutualPointer = &arrOfRoads[i];
            arrOfRoads[i].Road::setMutualPointer(heapData[i]);
        }
    }
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
}
//------------------------------------------------------
MaxHeap::MaxHeap(int _size) noexcept(false) //Allocates memory n sized.
{
    try{this->heapData = new Pair * [_size];}
    catch(std::bad_alloc& error) {throw error;}
    catch(...) {throw std::exception();}
    this->maxHeap = _size;
}
//------------------------------------------------------
MaxHeap::~MaxHeap() //Heap destructor.
{
    for (unsigned int i = 0; i < heapSize; i++)
        delete heapData[i];

    delete[] heapData;
}
//------------------------------------------------------
void MaxHeap::fixHeap(int index) //Fixes heap.
{
    int maxOfThree = index;
    int leftChild = MaxHeap::leftChild(index);
    int rightChild = MaxHeap::rightChild(index);
    int parent = MaxHeap::parent(index);

    if (leftChild < this->heapSize && (heapData[leftChild]->mutualPointer->getMinBridge() == 0 ||
    heapData[leftChild]->mutualPointer->getMinBridge() > heapData[index]->mutualPointer->getMinBridge()))
        maxOfThree = leftChild;

    if (rightChild < this->heapSize && (heapData[rightChild]->mutualPointer->getMinBridge() == 0 ||
    heapData[rightChild]->mutualPointer->getMinBridge() > heapData[maxOfThree]->mutualPointer->getMinBridge())
    && heapData[maxOfThree]->mutualPointer->getMinBridge() > 0)
        maxOfThree = rightChild;

    if (maxOfThree != index)
    {
        std::swap(heapData[index], heapData[maxOfThree]);
        heapData[index]->heapIndex = index;
        heapData[maxOfThree]->heapIndex = maxOfThree;
        MaxHeap::fixHeap(maxOfThree);
    }

    else if (parent >= 0 && parent != index && heapData[parent]->mutualPointer->getMinBridge() > 0 &&
            heapData[parent]->mutualPointer->getMinBridge() < heapData[index]->mutualPointer->getMinBridge())
    {
        std::swap(heapData[index], heapData[parent]);
        heapData[parent]->heapIndex = parent;
        heapData[index]->heapIndex = index;
        MaxHeap::fixHeap(parent);
    }
}
//------------------------------------------------------
unsigned int MaxHeap::DeleteMax() noexcept(false) //Removes maximum object from heap.
{
    if (this->heapSize < 1)
        throw std::invalid_argument("Heap is empty");

    unsigned int output = this->heapData[0]->mutualPointer->getRoadNumber();
    std::swap(this->heapData[MAX_IN_HEAP], this->heapData[heapSize-1]);
    this->heapData[MAX_IN_HEAP]->heapIndex = MAX_IN_HEAP;
    delete this->heapData[heapSize-1];
    this->heapSize--;

    this->fixHeap(MAX_IN_HEAP);
    return output;
}
//------------------------------------------------------
void MaxHeap::insert(Road *_road) noexcept(false) //Inserts new data to the heap.
{
    if (this->maxHeap == this->heapSize)
        throw std::invalid_argument("Heap is already full");

    else
    {
        try{this->heapData[heapSize] = new Pair;}
        catch(std::bad_alloc& error) {throw error;}
        catch(...) {throw std::exception();}

        this->heapData[heapSize]->heapIndex = (int)heapSize;
        this->heapData[heapSize]->mutualPointer = _road;

        this->fixHeap((int)heapSize);
        this->heapSize++;
    }
}
//------------------------------------------------------