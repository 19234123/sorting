#include <vector>

#ifndef SORTING_MAIN_H
#define SORTING_MAIN_H

class main{

public:
    vector<int> readFile(int size, bool fromFile);

    void displayTimeTaken(const string& sortType, int listSize);
    void generateFile(int size);
    string generateRandomNumber();
};
#endif //SORTING_MAIN_H
