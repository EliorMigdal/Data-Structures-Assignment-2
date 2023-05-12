#include "Roads.h"

//------------------------------------------------------
void Roads::setNumOfRoads(int _numOfRoads) //Sets number of roads.
{
    if (_numOfRoads < 0)
        throw std::invalid_argument("Invalid input");

    else
        this->numOfRoads = _numOfRoads;
}
//------------------------------------------------------
void Roads::Init() //Initializes data structures.
{
    try
    {
        roadsArr = new Road[numOfRoads];

        for (int i = 0; i < this->numOfRoads; i++)
            roadsArr[i].Road::setRoadNumber(i+1);

        this->maxMinBridges = new MaxHeap(roadsArr, numOfRoads);
    }
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
}
//------------------------------------------------------
void Roads::AddBridge(float h, int r) //Adds a new bridge to the data structure.
{
    if (h <= 0 || r < 0 || r > this->numOfRoads)
        throw std::invalid_argument("Invalid input");

    try{roadsArr[r-1].Road::addBridge(h);}
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
}
//------------------------------------------------------
void Roads::WhichRoad(float height) //WhichRoad function from assignment.
{
    if (height <= 0)
        throw std::invalid_argument("Invalid input");

    else if (this->numOfRoads != 0 && (
            height < this->getRoadsArr()[this->maxMinBridges->MaxHeap::Max() - 1].getMinBridge()
    || this->getRoadsArr()[this->maxMinBridges->MaxHeap::Max() - 1].getMinBridge() == 0))
        cout << this->maxMinBridges->MaxHeap::Max() << endl;

    else
        cout << "0" << endl;
}
//------------------------------------------------------
void Roads::print(int r) //Prints road#r's bridges.
{
    if (r < 0 || r > numOfRoads)
        throw std::invalid_argument("Invalid input");

    roadsArr[r-1].Road::printBridges();
}
//------------------------------------------------------