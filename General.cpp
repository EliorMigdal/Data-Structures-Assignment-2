#include "General.h"

//------------------------------------------------------
int getRoadsInput() //Reads initial roads input.
{
    int input;
    cin >> input;
    if (input < 0)
        throw std::invalid_argument("Invalid input");

    return input;
}
//------------------------------------------------------
void getActionsInput(Roads& roadsSystem, int numOfRoads) //Reads actions input.
{
    int numOfActions;
    cin >> numOfActions;
    if (numOfActions < 0)
        throw std::invalid_argument("Invalid input");

    cin.ignore();
    int counter = 0;

    while (counter != numOfActions)
    {
        char action = (char)getchar();

        if (!verifyActionInput(action) || (counter == 0 && action != 'a') || (counter > 0 && action == 'a'))
            throw std::invalid_argument("Invalid input");

        else
        {
            try{actionOperation(roadsSystem, action, numOfRoads);}
            catch(std::invalid_argument& error) {throw std::invalid_argument(error);}
            catch(...) {throw std::exception();}
        }

        if (counter > 0)
            cin.ignore();

        counter++;
    }
}
//------------------------------------------------------
inline bool verifyActionInput(char action) //Verifies action input.
{
    return (action >= 'a' && action <= 'd');
}
//------------------------------------------------------
void actionOperation(Roads& roadsSystem, char action, int numOfRoads) //Operates per action.
{
    float height;
    int roadNum;
    cin.ignore();

    switch(action){
        default:
            break;
        /////////////////////////////////////////////////////////////////////////////////////////
        case 'a':
            try
            {
                roadsSystem.setNumOfRoads(numOfRoads);
                roadsSystem.Roads::Init();
            }
            catch(std::invalid_argument& error) {throw std::invalid_argument(error);}
            catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
            catch(...) {throw std::exception();}

            break;
        /////////////////////////////////////////////////////////////////////////////////////////
        case 'b':
            cin >> height;
            cin >> roadNum;

            try{roadsSystem.AddBridge(height, roadNum);}
            catch(std::invalid_argument& error) {throw std::invalid_argument(error);}
            catch(std::bad_alloc& error) {throw std::bad_alloc(error);}
            catch(...) {throw std::exception();}

            roadsSystem.getHeap().fixHeap(roadsSystem.getRoadsArr()[roadNum-1].getMutualPointer()->heapIndex);
            break;
        /////////////////////////////////////////////////////////////////////////////////////////
        case 'c':
            cin >> height;

            try{roadsSystem.WhichRoad(height);}
            catch(std::invalid_argument& error) {throw std::invalid_argument(error);}
            catch(...) {throw std::exception();}

            break;
        /////////////////////////////////////////////////////////////////////////////////////////
        case 'd':
            cin >> roadNum;

            try{roadsSystem.print(roadNum);}
            catch(std::invalid_argument& error) {throw std::invalid_argument(error);}
            catch(...) {throw std::exception();}

            break;
    }
}
//------------------------------------------------------