#ifndef DATA_STRUCTURES_ASSIGNMENT_2_GENERAL_H
#define DATA_STRUCTURES_ASSIGNMENT_2_GENERAL_H
#include "Roads.h"

int getRoadsInput() noexcept(false);
void getActionsInput(Roads&, int) noexcept(false);
bool verifyActionInput(char);
void actionOperation(Roads&, char, int) noexcept(false);

#endif //DATA_STRUCTURES_ASSIGNMENT_2_GENERAL_H