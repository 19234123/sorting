#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <utility>
#include <vector>
#include "Sorting.h"
#include "main.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

std::chrono::system_clock::time_point startTime;
std::chrono::system_clock::time_point endTime;


vector<int> readFile(int size, bool fromFile);
void displayTimeTaken(const string& sortType, int listSize);
void generateFile(int size);
string generateRandomNumber();
vector<int> callSort(vector<int> numbers, vector<int> (*func)(vector<int>));
void runMultipleTimes(int numberOfRuns, vector<int> (*func)(vector<int>), const vector<int>& numbers);

int main() {
    int listSizes[] = {10, 20, 50, 100, 500, 1000, 2000, 5000, 100000,
                       20000, 50000, 100000, 1000000, 2000000, 5000000, 10000000,
                       20000000, 50000000, 100000000};


    const vector<int> rawNumbers = readFile(1000, true);
    vector<int> numbersToSort = rawNumbers;

//    for (const auto &size: listSizes){
//        numbersToSort = readFile(size);
//
//        startTime = std::chrono::high_resolution_clock::now();
//        bubbleSort(numbersToSort);
//        endTime = std::chrono::high_resolution_clock::now();
//        displayTimeTaken("Bubble", (int) numbersToSort.size());
//    }

//    numbersToSort = Sorting::bucketSort(numbersToSort);
//
//
//    for (const auto &num: numbersToSort){
//        cout << num << endl;
//    }

//    startTime = std::chrono::high_resolution_clock::now();
//    Sorting::bubbleSort(numbersToSort);
//    endTime = std::chrono::high_resolution_clock::now();
//    displayTimeTaken("Bubble", (int) numbersToSort.size());
//
//    numbersToSort = rawNumbers;
//
//    startTime = std::chrono::high_resolution_clock::now();
//    Sorting::improvedBubbleSort(numbersToSort);
//    endTime = std::chrono::high_resolution_clock::now();
//    displayTimeTaken("Improved Bubble", (int) numbersToSort.size());
//
//    numbersToSort = rawNumbers;

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::insertionSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Insertion", (int) numbersToSort.size());

    numbersToSort = rawNumbers;

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::bucketSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Bucket", (int) numbersToSort.size());

    numbersToSort = rawNumbers;

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::mergeSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Merge", (int) numbersToSort.size());

    numbersToSort = rawNumbers;

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::mergeSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Quick", (int) numbersToSort.size());

    numbersToSort = rawNumbers;

    //runMultipleTimes(5, reinterpret_cast<vector<int> (*)(vector<int>)>(&Sorting::mergeSort), numbersToSort);



    // init file setup
//    generateFile(3);
//    generateFile(5);
//    generateFile(10);
//    generateFile(20);
//    generateFile(50);
//    generateFile(100);
//    generateFile(500);
//    generateFile(1000);
//    generateFile(2000);
//    generateFile(5000);
//    generateFile(10000);
//    generateFile(20000);
//    generateFile(50000);
//    generateFile(100000);
//    generateFile(200000);
//    generateFile(500000);
//    generateFile(1000000);
//    generateFile(2000000);
//    generateFile(5000000);
//    generateFile(10000000);
//    generateFile(20000000);
//    generateFile(50000000);
//    generateFile(100000000);

    return 0;
}

void runMultipleTimes(int numberOfRuns, vector<int> (*func)(vector<int>), const vector<int>& numbers){
    //std::chrono::system_clock::time_point sumTimes;
    std::chrono::system_clock::time_point::duration sumTime;// = (startTime - startTime);

    for (int i=0; i<numberOfRuns; i++){
        startTime = std::chrono::high_resolution_clock::now();
        callSort(numbers, func);
        endTime = std::chrono::high_resolution_clock::now();

        auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        sumTime += microDuration;
    }

    cout << "average: " << (sumTime.count() / numberOfRuns) << endl;
}

vector<int> callSort(vector<int> numbers, vector<int> (*func)(vector<int>)){
    return func(std::move(numbers));
}


void displayTimeTaken(const string &sortType, int listSize){
    auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(microDuration);
    auto secondsDuration = std::chrono::duration_cast<std::chrono::seconds>(milliDuration);

    cout << sortType << " sort: " << listSize << " numbers" << endl;
    //cout << "Total execution time (Nanoseconds): " << nanoDuration.count() << endl;
    cout << "Total execution time (Microseconds): " << microDuration.count() << endl;
    cout << "Total execution time (Milliseconds): " << milliDuration.count() << endl;
    cout << "Total execution time (Seconds): " << secondsDuration.count() << endl;
    cout << endl;
}

vector<int> readFile(int size, bool fromFile){
    vector<int> numbers;

    if (fromFile) {
        string filename = std::to_string(size);
        filename += ".txt";

        std::ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (std::getline(file, line)) {
                numbers.push_back(std::stoi(line));
            }
        }
    } else {
        for (int i=0; i<size; i++){
            numbers.push_back(std::stoi(generateRandomNumber()));
        }
        cout << size << " numbers generated!\n\n";
    }
    return numbers;
}

string generateRandomNumber(){
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, main::maxRandomSize);

    return std::to_string(distribution(rng));
}

void generateFile(int size){
    string filename = std::to_string(size);
    filename += ".txt";

    std::ofstream file (filename);
    if (file.is_open()) {
        for (int i=0; i<size; i++) {
            string number = generateRandomNumber();
            file << number << endl;
            //cout << number << endl;
        }
        file.close();
        cout << "Save successful - " << filename << endl;
    }
    else {
        cout << "Error: Unable to save to file";
    }
}
