#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <vector>
#include "Sorting.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;


std::chrono::system_clock::time_point startTime;
std::chrono::system_clock::time_point endTime;
int maxRandomSize = 1000000;

vector<int> readFile(int size, bool fromFile);
void displayTimeTaken(const string& sortType, int listSize);
void generateFile(int size);
string generateRandomNumber();


int main() {

    int listSizes[] = {10, 20, 50, 100, 1000, 10000, 20000, 50000, 100000, 1000000};

    vector<int> rawNumbers = readFile(100, true);
    vector<int> numbersToSort = rawNumbers;

//    for (const auto &size: listSizes){
//        numbersToSort = readFile(size);
//
//        startTime = std::chrono::high_resolution_clock::now();
//        bubbleSort(numbersToSort);
//        endTime = std::chrono::high_resolution_clock::now();
//        displayTimeTaken("Bubble", (int) numbersToSort.size());
//    }

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::bubbleSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Bubble", (int) numbersToSort.size());

    numbersToSort = rawNumbers;

    startTime = std::chrono::high_resolution_clock::now();
    Sorting::improvedBubbleSort(numbersToSort);
    endTime = std::chrono::high_resolution_clock::now();
    displayTimeTaken("Improved Bubble", (int) numbersToSort.size());


    // init file setup
//    generateFile(10);
//    generateFile(20);
//    generateFile(50);
//    generateFile(100);
//    generateFile(1000);
//    generateFile(10000);
//    generateFile(20000);
//    generateFile(50000);
//    generateFile(100000);
//    generateFile(1000000);

    return 0;
}


void displayTimeTaken(const string &sortType, int listSize){
    auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(microDuration);
    auto secondsDuration = std::chrono::duration_cast<std::chrono::seconds>(milliDuration);

    cout << sortType << " sort: " << listSize << endl;
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
    }
    return numbers;
}

string generateRandomNumber(){
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, maxRandomSize);

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
            cout << number << endl;
        }
        file.close();
        cout << "Save successful - " << filename << endl;
    }
    else {
        cout << "Error: Unable to save to file";
    }
}
