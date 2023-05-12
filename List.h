#ifndef DATA_STRUCTURES_ASSIGNMENT_2_LIST_H
#define DATA_STRUCTURES_ASSIGNMENT_2_LIST_H
#include "BridgeNode.h"

class List {
    BridgeNode* head = nullptr;
    BridgeNode* tail = nullptr;
    BridgeNode* minBridge = nullptr;

public:
    List() = default;
    ~List();

    BridgeNode* getHead() const {return head;}
    BridgeNode* getTail() const {return tail;}
    BridgeNode* getMinBridge() const {return minBridge;}

    void setHead(BridgeNode* _newHead) {head = _newHead;}
    void setTail(BridgeNode* _newTail) {tail = _newTail;}
    void setMinBridge(BridgeNode* _newMin) {minBridge = _newMin;}

    void makeEmpty();
    bool isEmpty() const;
    void insertDataToStartOfList(float) noexcept(false);
    void insertDataToEndOfList(float) noexcept(false);
    void addToHead(BridgeNode*);
    void addToTail(BridgeNode*);
};

#endif //DATA_STRUCTURES_ASSIGNMENT_2_LIST_H