#include <vector>

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

using std::vector;

class Sorting {

public:
    vector<int> static bubbleSort(const vector<int>& numbers);
    vector<int> static improvedBubbleSort(const vector<int>& numbers);
    vector<int> static quickSort(const vector<int>& numbers);
    vector<int> static mergeSort(const vector<int>& numbers);
    vector<int> static insertionSort(const vector<int>& numbers);

};


#endif //SORTING_SORTING_H
