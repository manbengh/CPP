#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>

// std::map

void checkArgs(int argc, char **argv);
void checkData(std::map<std::string, double> &myData, std::ifstream &myFile);
void compareData(std::map<std::string, double> &myData, std::ifstream &myFile);

#endif