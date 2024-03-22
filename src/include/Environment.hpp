// environment.hpp

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class Environment {
public:
    Environment(const std::string &file_path);

    void LoadFromFile(const std::string &file_path);
    void Print() const;
    bool IsDirty(int x, int y) const;
    void Clean(int x, int y);
    int GetSize() const;
    int CountRemainingDirtySquares() const;
    int GetValueAt(int x, int y) const;

private:
    std::vector<std::vector<int>> grid;
    int size;
};

#endif // ENVIRONMENT_HPP
