#ifndef DATA_STRUCTURES_ASSIGNMENT_2_ROAD_H
#define DATA_STRUCTURES_ASSIGNMENT_2_ROAD_H
#include "List.h"

struct Pair;

class Road {
    unsigned int roadNumber = 0;
    List listOfBridges;
    BridgeNode* minBridge = nullptr;
    Pair* mutualPointer = nullptr;

public:
    Road() = default;
    Road& operator=(const Road&) = default;
    Road& operator=(Road&&) = default;
    ~Road() = default;

    unsigned int getRoadNumber() const {return roadNumber;}
    Pair* getMutualPointer() const {return mutualPointer;}
    float getMinBridge() const;

    void setRoadNumber(unsigned int _roadNumber) {roadNumber = _roadNumber;}
    void setMutualPointer(Pair* _address) {mutualPointer = _address;}

    void addBridge(float _height);
    void printBridges();
};

struct Pair{
    Road* mutualPointer = nullptr;
    int heapIndex = 0;
};

#endif //DATA_STRUCTURES_ASSIGNMENT_2_ROAD_H