#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <chrono>

using namespace std;

int countHelium(vector<int> containerStructure) {
    auto start = chrono::steady_clock::now();
    int totalCount = 0;
    int leftBound = 0;
    int rightBound = containerStructure.size() - 1;
    int maxLeftBoundReached = false;
    int maxRightBoundReached = false;
    while (leftBound < rightBound) {
        if (!maxLeftBoundReached) {
            int indexShift = 1;
            int tempCount = 0;
            while (leftBound + indexShift < rightBound &&
                   containerStructure[leftBound + indexShift] < containerStructure[leftBound]) {
                tempCount += containerStructure[leftBound] - containerStructure[leftBound + indexShift];
                indexShift++;
            }
            if (containerStructure[leftBound + indexShift] >= containerStructure[leftBound]) {
                totalCount += tempCount;
                leftBound += indexShift;
            } else {
                maxLeftBoundReached = true;
            }
        }
        if (!maxRightBoundReached) {
            int indexShift = 1;
            int tempCount = 0;
            while (rightBound - indexShift > leftBound &&
                   containerStructure[rightBound - indexShift] < containerStructure[rightBound]) {
                tempCount += containerStructure[rightBound] - containerStructure[rightBound - indexShift];
                indexShift++;
            }
            if (containerStructure[rightBound - indexShift] >= containerStructure[rightBound]) {
                totalCount += tempCount;
                rightBound -= indexShift;
            } else {
                maxRightBoundReached = true;
            }
        }
    }
    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
    return totalCount;
}

int main() {
    assert(6 == countHelium({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
    assert(8 == countHelium({0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2}));
    assert(9 == countHelium({4, 2, 0, 3, 2, 5}));
    assert(83 == countHelium({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3}));
    return 0;
}
