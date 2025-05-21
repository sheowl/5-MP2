#include <iostream>
using namespace std;

class TraditionalLS {
public:
    int linearSearch(int arrNumbers[], int intSize, int intTarget, int &intPasses) {
        intPasses = 0;
        for (int intIndex = 0; intIndex < intSize; ++intIndex) {
            intPasses++;
            if (arrNumbers[intIndex] == intTarget) {
                return intIndex;
            }
        }
        return -1;
    }
};
