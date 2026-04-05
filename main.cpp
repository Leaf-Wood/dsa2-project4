#include <iostream>
#include <fstream>
#include <vector>
#include "Algorithms.hpp"

void printBin(const std::string& name, const std::vector<Bin>& bins) {
    std::cout << name << ":\n";
    for(size_t i=0; i<bins.size(); ++i) {
        std::cout << "  b" << (i+1) << ": ";
        for(size_t j=0; j<bins[i].items.size(); ++j) {
            std::cout << bins[i].items[j] << ", ";
        }
        std::cout << "\n";
    }
    std::cout <<"\n";
}

int main() {
    const std::string INPUT_FILE = "items.txt";
    
    //open file
    std::ifstream inputFile(INPUT_FILE);
    if(!inputFile) {
        std::cout << "Could not open file " << INPUT_FILE << "\n";
        return 1;
    }

    //read first line to get number of items
    int numItems;
    if(!(inputFile >> numItems)) {
        std::cout << "Could not read numItems from file " << INPUT_FILE << "\n";
        return 1;
    }

    //read rest of file to get all items
    std::vector<float> items;
    float currentItem;
    int itemsRead = 0;

    while (inputFile >> currentItem && itemsRead < numItems) {
        itemsRead++;

        if(currentItem <= 0.0f || currentItem > 1.0f) { //f makes it float instead of double
            //invalid item
            std::cout << "Warning: Invalid item (" << currentItem << ") discarded.\n";
            continue;
        }

        items.push_back(currentItem);
    }

    inputFile.close();

    /*
    std::cout << "Successfully parsed " << items.size() << " valid items:\n";
    for (float item : items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    */

    //run all algorithms
    std::vector<Bin> onlineFirst = onlineFirstFit(items);
    std::vector<Bin> onlineNext  = onlineNextFit(items);
    std::vector<Bin> onlineBest  = onlineBestFit(items);
    std::vector<Bin> offlineFirst = offlineFirstFit(items);
    std::vector<Bin> offlineBest  = offlineBestFit(items);

    //find optimal algorithm
    std::vector<int> s(items.size());
    for(size_t i=0; i<items.size(); ++i) {
        s[i] = i; //create array of indicies for each item
    }

    std::vector<Bin> bestOptimalBins;
    unsigned long long counter = 1; 
    unsigned long long operations = 1;
    for(int i=numItems; i>1; --i) {
        operations *= i;
    }
    unsigned long long interval = operations / 50;
    std::cout << operations << " operations need to be run. Each dot is 2%.\n";
    std::cout << "==========|------------------------------------------------|\n";
    std::cout << "Progress: " << std::flush;
    evaluatePermutation(s.data(), s.size(), items, bestOptimalBins);
    while(perm1(s.data(), s.size())) {
        evaluatePermutation(s.data(), s.size(), items, bestOptimalBins);
        counter++;
        if (counter % interval == 0) {std::cout << "." << std::flush; }
    }


    //print output
    std::cout << "\n\nPolicy\t\t\tTotal Bins Used\n";
    std::cout << "Optimal Solution\t" << bestOptimalBins.size() << "\n";
    std::cout << "Online Algorithm\n";
    std::cout << "     First Fit\t\t" << onlineFirst.size() << "\n";
    std::cout << "     Next Fit\t\t" << onlineNext.size() << "\n";
    std::cout << "     Best Fit\t\t" << onlineBest.size() << "\n";
    std::cout << "Offline Algorithm\n";
    std::cout << "     First Fit\t\t" << offlineFirst.size() << "\n";
    std::cout << "     Best Fit\t\t" << offlineBest.size() << "\n\n";

    printBin("Optimal", bestOptimalBins);
    printBin("Online First Fit", onlineFirst);
    printBin("Online Next Fit", onlineNext);
    printBin("Online Best Fit", onlineBest);
    printBin("Offline First Fit", offlineFirst);
    printBin("Offline Best Fit", offlineBest);

    return 0;
}