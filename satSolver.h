#ifndef SAT_H
#define SAT_H

#include <vector>

bool satCallingMiniSat(unsigned int numVar, std::vector<std::vector<int>> &cnf); // return the SAT result of cnf by calling MiniSAT

#endif
