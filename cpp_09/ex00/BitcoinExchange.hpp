#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>

// std::map

void check_args(int argc, char **argv);
void checkData(std::map<std::string, double> &myData, std::ifstream &myFile);

#endif