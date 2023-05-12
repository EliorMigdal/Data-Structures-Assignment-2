#include "Road.h"

//------------------------------------------------------
float Road::getMinBridge() const //Returns a road's lowest bridge.
{
    if (this->minBridge == nullptr)
        return 0.0;

    else
        return this->minBridge->getBridgeHeight();
}
//------------------------------------------------------
void Road::addBridge(float _height) noexcept(false) //Adds a new bridge.
{
    this->listOfBridges.insertDataToEndOfList(_height);

    if (this->minBridge == nullptr || _height < this->minBridge->getBridgeHeight())
        this->minBridge = this->listOfBridges.List::getMinBridge();
}
//------------------------------------------------------
void Road::printBridges() //Prints road's bridges.
{
    BridgeNode* currNode = this->listOfBridges.getHead();

    while (currNode != nullptr)
    {
        cout << fixed << std::setprecision(FLOAT_PRECISION)
        << currNode->getBridgeHeight();
        currNode = currNode->getNext();

        if (currNode)
            cout << ", ";
    }

    cout << "\n";
}
//------------------------------------------------------