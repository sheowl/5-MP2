#include <iostream>
using namespace std;

class TraditionalLS;
class BidirectionalLS;
class TransposeLS;

#include "TraditionalLS.cpp"
#include "BidirectionalLS.cpp"
#include "TransposeLS.cpp"

int main() {
    int intArrSize;

    cout << "Enter array size: ";
    cin >> intArrSize;

    int* arrNumbers = new int[intArrSize];

    cout << "Enter " << intArrSize << " integers:\n\n";
    for (int intIndex = 0; intIndex < intArrSize; ++intIndex) {
        cout << "[" << intIndex + 1 << "]: ";
        cin >> arrNumbers[intIndex];
    }

    int intChoice;

    while (true) {
        cout << "\n\n---------------------------------\n"
             << "|    Linear/Sequential Search    |\n"
             << "---------------------------------\n\n";
        cout << "Menu:\n"
             << "(1) Traditional Linear Search\n"
             << "(2) Bidirectional Linear Search\n"
             << "(3) Transpose Linear Search\n"
             << "(0) Exit\n";
        cout << "\nChoose an option within the menu: ";
        cin >> intChoice;

        int intTarget;
        cout << "\nEnter value to search: ";
        cin >> intTarget;

        int intResult = -1;
        int intPasses = 0;

        switch (intChoice) {
            case 1: {
                TraditionalLS objTraditional;
                intResult = objTraditional.linearSearch(arrNumbers, intArrSize, intTarget, intPasses);
                break;
            }
            case 2: {
                BidirectionalLS objBidirectional;
                intResult = objBidirectional.bidirectionalSearch(arrNumbers, intArrSize, intTarget, intPasses);
                break;
            }
            case 3: {
                TransposeLS objTranspose;
                intResult = objTranspose.transposeSearch(arrNumbers, intArrSize, intTarget, intPasses);
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Invalid choice.\n";
                continue;
        }

        if (intResult != -1) {
            cout << "\nTarget found at index: " << intResult << endl;
        } else {
            cout << "\nValue not found.\n";
        }

        cout << "\nNumber of passes: " << intPasses << endl;

        cout << "\nCurrent array: { ";
        for (int intIndex = 0; intIndex < intArrSize; ++intIndex) {
            cout << arrNumbers[intIndex];
            if (intIndex != intArrSize - 1)
                cout << ", ";
        }
        cout << " }" << endl;
    }

    delete[] arrNumbers;
    return 0;
}
