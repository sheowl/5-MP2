#include <iostream>
using namespace std;

class BidirectionalLS {
public:
    int bidirectionalSearch(int arrNumbers[], int intSize, int intTarget, int &intPasses) {
        intPasses = 0;

        for (int intIndex = 0; intIndex <= intSize / 2; ++intIndex) {
            intPasses++;
            if (arrNumbers[intIndex] == intTarget){
                return intIndex;
            } else if (arrNumbers[intSize - 1 - intIndex] == intTarget){
                return intSize - 1 - intIndex;
            }
        }
        return -1;
    }
};
