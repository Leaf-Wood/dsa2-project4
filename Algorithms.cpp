#include "Algorithms.hpp"
#include <algorithm>
#include <functional>

std::vector<Bin> onlineFirstFit(const std::vector<float>& items) {
    std::vector<Bin> bins;

    for(float item : items) {
        bool placed = false;

        //scan existing bins for the first one that fits
        for(Bin& bin : bins) {
            if(bin.canFit(item)) {
                bin.addItem(item);
                placed = true;
                break;
            }
        }

        //if didn't fit in existing bin, create new bin
        if(!placed) {
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }
    }

    return bins;
}

std::vector<Bin> onlineNextFit(const std::vector<float>& items) {
    std::vector<Bin> bins;
    
    Bin currentBin;
    for(float item : items) {
        //check only current bin
        if(currentBin.canFit(item)) {
            currentBin.addItem(item);
        } else {
            //add bin to list and create a new bin
            bins.push_back(currentBin);
            currentBin = Bin();
            currentBin.addItem(item);
        }
    }

    bins.push_back(currentBin);

    return bins;
}

std::vector<Bin> onlineBestFit(const std::vector<float>& items) {
    std::vector<Bin> bins;

    for(float item : items) {
        int bestBinIndex = -1;
        float minSpaceLeft = 2.0f;

        //find bin that will be most full if item is there
        for(size_t i=0; i<bins.size(); ++i) { //needs to be size_t because unsigned, or causes warnings
            if(bins[i].canFit(item)) {
                float spaceLeft = bins[i].capacityRemaining - item;
                if(spaceLeft < minSpaceLeft) {
                    minSpaceLeft = spaceLeft;
                    bestBinIndex = i;
                }
            }
        }

        if(bestBinIndex == -1) {
            //no good bins found, make new one
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        } else {
            bins[bestBinIndex].addItem(item);
        }
    }
    return bins;
}

std::vector<Bin> offlineFirstFit(std::vector<float> items) {
    //sort items in descending order, then use online first fit
    std::sort(items.begin(), items.end(), std::greater<float>());
    return onlineFirstFit(items);
}

std::vector<Bin> offlineBestFit(std::vector<float> items) {
    //sort items in descending order, then use online best fit
    std::sort(items.begin(), items.end(), std::greater<float>());
    return onlineBestFit(items);
} 

void evaluatePermutation(int s[], int numElements, const std::vector<float>& originalItems, std::vector<Bin>& bestOptimalBins) {
    //checks if given permutation is better than previous best
    std::vector<float> permutedItems;
    for(int i=0; i<numElements; i++) {
        permutedItems.push_back(originalItems[s[i]]);
    }

    std::vector<Bin> currentResult = onlineFirstFit(permutedItems);
    if(bestOptimalBins.empty() || currentResult.size() < bestOptimalBins.size()) {
        bestOptimalBins = currentResult;
    }
}

bool perm1(int s[], int numElements) {
    int m, k, p , q;
    
    m = numElements - 2;
    while(m >= 0 && s[m] > s[m+1]) {
        m = m - 1;
    }
    
    if(m < 0) return false; //all permutations finished
    
    k = numElements - 1;
    while(s[m] > s[k]) {
        k = k - 1;
    }
    
    std::swap(s[m], s[k]);
    
    p = m + 1;
    q = numElements - 1;
    while(p < q) {
        std::swap(s[p], s[q]);
        p++;
        q--;
    }
    
    return true;
}