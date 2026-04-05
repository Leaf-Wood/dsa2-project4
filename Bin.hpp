#ifndef BIN_HPP
#define BIN_HPP

#include <vector>

struct Bin {
    float capacityRemaining;
    std::vector<float> items;

    Bin() : capacityRemaining(1.0f) {}

    bool canFit(float itemSize) const {
        return capacityRemaining >= itemSize;
    }

    void addItem(float itemSize) {
        items.push_back(itemSize);
        capacityRemaining -= itemSize;
    }
};

#endif