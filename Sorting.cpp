#include "Sorting.h"
#include "main.h"


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
    vector<int> currentList;
    int listSize = (int)numbers.size();

    if (listSize > 1){
        int pivotIndex = listSize/2;
        int pivot = numbers.at(pivotIndex);
        vector<int> lessThanEqual;
        vector<int> greaterThan;

        for (int i=0; i<listSize; i++){
            if (i != pivotIndex) {
                if (numbers.at(i) <= pivot) {
                    lessThanEqual.push_back(numbers.at(i));
                } else {
                    greaterThan.push_back(numbers.at(i));
                }
            }
        }

        lessThanEqual = quickSort(lessThanEqual);
        greaterThan = quickSort(greaterThan);

        currentList.insert(currentList.end(), lessThanEqual.begin(), lessThanEqual.end());
        currentList.push_back(pivot);
        currentList.insert(currentList.end(), greaterThan.begin(), greaterThan.end());
    } else {
        currentList = numbers;
    }
    return currentList;
}

vector<int> Sorting::bucketSort(const vector<int> &numbers, int sortType) {
    vector<int> sorted;
    vector<vector<int>> buckets;
    int numberOfBuckets = 10;

    for (int i=0; i<numberOfBuckets; i++){
        vector<int> bucket;
        buckets.push_back(bucket);
    }

    int bucketRange = main::maxRandomSize / numberOfBuckets;
    for (const auto &num: numbers){
        int index = num / bucketRange;
        if (index == 10){
            index = 9;
        }
        buckets.at(index).push_back(num);
    }

    for (auto &bucket: buckets){
        switch (sortType){
            case 0:
                bucket = quickSort(bucket);
                break;
            case 1:
                bucket = mergeSort(bucket);
                break;
            case 2:
                bucket = insertionSort(bucket);
                break;
            case 3:
                bucket = bubbleSort(bucket);
                break;
            default:
                bucket = quickSort(bucket);
        }
        sorted.insert(sorted.end(), bucket.begin(), bucket.end());
    }
    return sorted;
}
