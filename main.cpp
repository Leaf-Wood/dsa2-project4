#include <iostream>
#include <fstream>
#include <vector>

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

    std::cout << "Successfully parsed " << items.size() << " valid items:\n";
    for (float item : items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}