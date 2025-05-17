#include <iostream>
using namespace std;

int main() {
    // Predefined static array
    int arrContainer[] = {10, 20, 30, 40, 50};
    int intArrSize = sizeof(arrContainer) / sizeof(arrContainer[0]);

    // Target to find
    int intTarget;
    cout << "Enter target number: ";
    cin >> intTarget;

    // Linear search algorithm inside main
    bool found = false;
    for (int i = 0; i < intArrSize; ++i) {
        if (arrContainer[i] == intTarget) {
            cout << "Present at index " << i << endl;
            found = true;
            break; // optional, stops at first match
        }
    }

    if (!found) {
        cout << "Target not present" << endl;
    }

    return 0;
}
