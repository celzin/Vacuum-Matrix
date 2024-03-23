#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Environment.hpp"
#include "Agent.hpp"
#include <string>
#include <vector>

void ExecuteSimulation(const std::string &inputFilePath, int maxMoves);
void GenerateReports(const std::vector<std::string> &actions_log, const int total_moves, const int cleaned_squares, const int squares_explored, const Environment &environment);

#endif 