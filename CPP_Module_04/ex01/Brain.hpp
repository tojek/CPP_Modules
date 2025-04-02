#pragma once
#include <string>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& other);

    std::string getIdea(int index);
    void setIdea(int index, std::string idea);
};