#ifndef DATA_STRUCTURES_ASSIGNMENT_2_BRIDGENODE_H
#define DATA_STRUCTURES_ASSIGNMENT_2_BRIDGENODE_H
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

constexpr unsigned short FLOAT_PRECISION = 4;
constexpr unsigned short MAX_IN_HEAP = 0;

class BridgeNode {
    float height = 0;
    BridgeNode* next = nullptr;

public:
    BridgeNode() = default;
    BridgeNode(float _height):height(_height){this->setNext(nullptr);}
    BridgeNode(float _height, BridgeNode* _next):height(_height), next(_next){}

    float getBridgeHeight() const {return height;}
    BridgeNode* getNext() const {return next;}

    void setHeight(float _height) {height = _height;}
    void setNext(BridgeNode* _next) {next = _next;}
};

#endif //DATA_STRUCTURES_ASSIGNMENT_2_BRIDGENODE_H