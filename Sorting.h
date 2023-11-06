#include <vector>

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

using std::vector;

class Sorting {

public:
    vector<int> static bubbleSort(vector<int> numbers);
    vector<int> static improvedBubbleSort(vector<int> numbers);
    vector<int> static selectionSort(vector<int> numbers);
    vector<int> static insertionSort(vector<int> numbers);
    vector<int> static quickSort(vector<int> numbers);
    vector<int> static mergeSort(vector<int> numbers);

};


#endif //SORTING_SORTING_H
