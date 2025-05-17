#include <iostream>
using namespace std;

int main() {

    int intArrSize;

    cout << "\nEnter array size: ";
    cin >> intArrSize;

    int* arrContainer = new int[intArrSize];

    cout << "\nEnter " << intArrSize << " integers\n";
    for (int i = 0; i < intArrSize; ++i) {
        cout << "[" << i + 1 << "]: ";
        cin >> arrContainer[i];
    }

    int intTarget;

    cout << "\nEnter target number: ";
    cin >> intTarget;

    // Algorithm starts here
    bool found = false;

    for(int i = 0; i < intArrSize; i++){
        if (arrContainer[i] == intTarget){
            cout << "Present at index " << i << endl;
            found = true;
            break; // optional: stop after finding first match
        }
    }

    if (!found) {
        cout << "Target not present" << endl;
    }

    // Clean up memory
    delete[] arrContainer;

    return 0;
}

