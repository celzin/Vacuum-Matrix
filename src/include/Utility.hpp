#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Environment.hpp" 
#include "Agent.hpp" 
#include <vector>
#include <string>

void ExecuteAgent(Environment &environment, Agent &agent, std::vector<std::string> &actions_log, int max_moves);
void GenerateReports(const std::vector<std::string> &actions_log, const Environment &environment, const Agent &agent, int total_moves, int cleaned_squares, int squares_explored);

#endif
