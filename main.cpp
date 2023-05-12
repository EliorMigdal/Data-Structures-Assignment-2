//Data Structures programming assignment#2
//By Elior Migdal, 313455321
#include "General.h"

int main() {
    Roads roadsSystem;
    int numOfRoads;
    try
    {
        numOfRoads = getRoadsInput();
        getActionsInput(roadsSystem, numOfRoads);
    }
    catch(std::invalid_argument& error) {cout << error.what() << endl;}
    catch(std::bad_alloc& error) {throw error;}
    catch(...) {throw std::exception();}

    return 0;
}