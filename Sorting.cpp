#include "Sorting.h"

vector<int> Sorting::bubbleSort(const vector<int>& numbers){
    vector<int> sorted = numbers;
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

vector<int> Sorting::improvedBubbleSort(const vector<int>& numbers){
    vector<int> sorted = numbers;
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

vector<int> Sorting::mergeSort(const vector<int>& numbers){
    vector<int> currentList;
    int halfSize = (int) numbers.size() / 2;
    vector<int> firstHalf(numbers.begin(), numbers.begin()+halfSize);
    vector<int> secondHalf(numbers.begin()+halfSize, numbers.end());

    if ((firstHalf.size() <= 1) && (secondHalf.size() <= 1)){
        if (firstHalf.empty()){
            currentList.push_back(secondHalf.at(0));
        } else if (secondHalf.empty()){
            currentList.push_back(firstHalf.at(0));
        } else {
            int leftElement = firstHalf.at(0);
            int rightElement = secondHalf.at(0);
            if (leftElement > rightElement){
                currentList.push_back(rightElement);
                currentList.push_back(leftElement);
            } else {
                currentList.push_back(leftElement);
                currentList.push_back(rightElement);
            }
        }
    } else {
        vector<int> firstHalfChain = mergeSort(firstHalf);
        vector<int> secondHalfChain = mergeSort(secondHalf);
        vector<int> tempList;
        int firstIndex = 0;
        int secondIndex = 0;
        int maxFirstIndex = (int)firstHalfChain.size();
        int maxSecondIndex = (int)secondHalfChain.size();
        bool endOfList = false;

        while (!endOfList){
            if ((firstIndex < maxFirstIndex) && (secondIndex < maxSecondIndex)){
                int currentFirst = firstHalfChain.at(firstIndex);
                int currentSecond = secondHalfChain.at(secondIndex);

                if (currentFirst <= currentSecond){
                    currentList.push_back(currentFirst);
                    firstIndex++;
                } else {
                    currentList.push_back(currentSecond);
                    secondIndex++;
                }
            } else if (firstIndex < maxFirstIndex){
                currentList.push_back(firstHalfChain.at(firstIndex));
                firstIndex++;
            } else if (secondIndex < maxSecondIndex){
                currentList.push_back(secondHalfChain.at(secondIndex));
                secondIndex++;
            } else {
                endOfList = true;
            }
        }
    }
    return currentList;
}

vector<int> Sorting::insertionSort(const vector<int>& numbers) {
    vector<int> sorted = numbers;
    int temp;

    for (int i=1; i<sorted.size(); i++){
        temp = sorted.at(i);
        for (int j=i-1; j>=0; j--){
            int currentNumber = sorted.at(j);
            if (currentNumber > temp) {
                sorted.at(j + 1) = currentNumber;
                sorted.at(j) = temp;
            }
        }
    }

    return sorted;
}

vector<int> Sorting::quickSort(const vector<int>& numbers){

}




