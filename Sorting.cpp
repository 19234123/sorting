#include "Sorting.h"

vector<int> Sorting::bubbleSort(vector<int> numbers){
    vector<int> sorted = std::move(numbers);
    int changed;
    do {
        changed = 0;
        for (int i=1; i<sorted.size(); i++){
            if (sorted.at(i-1) > sorted.at(i)){
                int temp = sorted.at(i-1);
                sorted.at(i-1) = sorted.at(i);
                sorted.at(i) = temp;
                changed++;
            }
        }
    } while (changed != 0);
    return sorted;
}

vector<int> Sorting::improvedBubbleSort(vector<int> numbers){
    vector<int> sorted = std::move(numbers);
    int changed;
    int lastIndex = (int) sorted.size();
    do {
        changed = 0;
        for (int i=1; i<lastIndex; i++){
            if (sorted.at(i-1) > sorted.at(i)){
                int temp = sorted.at(i-1);
                sorted.at(i-1) = sorted.at(i);
                sorted.at(i) = temp;
                changed++;
            }
        }
        lastIndex--;
    } while (changed != 0);
    return sorted;
}


vector<int> Sorting::insertionSort(vector<int> numbers){
}

vector<int> Sorting::selectionSort(vector<int> numbers){
}

vector<int> Sorting::quickSort(vector<int> numbers){
}

vector<int> Sorting::mergeSort(vector<int> numbers){
}
