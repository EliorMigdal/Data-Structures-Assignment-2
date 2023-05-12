#ifndef DATA_STRUCTURES_ASSIGNMENT_2_ROADS_H
#define DATA_STRUCTURES_ASSIGNMENT_2_ROADS_H
#include "MaxHeap.h"

class Roads {
    Road* roadsArr = nullptr;
    int numOfRoads = 0;
    MaxHeap* maxMinBridges = nullptr;

public:
    Roads() = default;
    ~Roads(){delete[] roadsArr; delete maxMinBridges;}

    MaxHeap& getHeap() {return *maxMinBridges;}
    Road* getRoadsArr() const {return roadsArr;}

    void setNumOfRoads(int) noexcept(false);

    void Init() noexcept(false);
    void AddBridge(float, int) noexcept(false);
    void WhichRoad(float) noexcept(false);
    void print(int) noexcept(false);
};

#endif //DATA_STRUCTURES_ASSIGNMENT_2_ROADS_H