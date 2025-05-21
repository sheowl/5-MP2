#include <iostream>
using namespace std;

class TransposeLS {
public:
    int transposeSearch(int arrNumbers[], int intSize, int intTarget, int &intPasses) {
        intPasses = 0;
        for (int intIndex = 0; intIndex < intSize; ++intIndex) {
            intPasses++;
            if (arrNumbers[intIndex] == intTarget) {
                if (intIndex > 0) {
                    int intTemp = arrNumbers[intIndex];
                    arrNumbers[intIndex] = arrNumbers[intIndex - 1];
                    arrNumbers[intIndex - 1] = intTemp;
                    return intIndex - 1;
                } else {
                    return 0;
                }
            }
        }
        return -1;
    }
};
