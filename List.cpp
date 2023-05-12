#include "List.h"

//------------------------------------------------------
List::~List() //List destructor.
{
    BridgeNode* currNode = this->List::getHead();
    BridgeNode* prevNode = currNode;

    while (currNode != nullptr)
    {
        currNode = currNode->BridgeNode::getNext();
        delete prevNode;
        prevNode = currNode;
    }
}
//------------------------------------------------------
void List::makeEmpty() //Makes a list an empty one.
{
    this->List::setHead(nullptr);
    this->List::setTail(nullptr);
    this->List::setMinBridge(nullptr);
}
//------------------------------------------------------
bool List::isEmpty() const //Checks whether a list is empty.
{
    return this->List::getHead() == nullptr;
}
//------------------------------------------------------
void List::insertDataToStartOfList(float _height) noexcept(false) //Inserts new data to the end of the list.
{
    BridgeNode* node;
    try{node = new BridgeNode(_height, nullptr);}
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
    this->List::addToHead(node);

    if (this->List::getMinBridge() == nullptr ||
        _height < this->List::getMinBridge()->BridgeNode::getBridgeHeight())
        this->List::setMinBridge(node);
}
//------------------------------------------------------
void List::insertDataToEndOfList(float _height) //Inserts new data to the end of the list.
{
    BridgeNode* node;
    try{node = new BridgeNode(_height, nullptr);}
    catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch(...) {throw std::exception();}
    this->List::addToTail(node);

    if (this->List::getMinBridge() == nullptr ||
    _height < this->List::getMinBridge()->BridgeNode::getBridgeHeight())
        this->List::setMinBridge(node);
}
//------------------------------------------------------
void List::addToHead(BridgeNode *_node) //Inserts a node to list's head.
{
    if (this->List::isEmpty())
    {
        this->List::setHead(_node);
        this->List::setTail(_node);
    }

    else
    {
        _node->BridgeNode::setNext(this->List::getHead());
        this->List::setHead(_node);
    }
}
//------------------------------------------------------
void List::addToTail(BridgeNode *_node) //Insert a node to list's tail.
{
    if (this->List::isEmpty())
    {
        this->List::setHead(_node);
        this->List::setTail(_node);
    }

    else
    {
        this->List::getTail()->BridgeNode::setNext(_node);
        this->List::setTail(_node);
    }
}
//------------------------------------------------------