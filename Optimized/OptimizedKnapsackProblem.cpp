#include <iostream>
using namespace std;
void DPArraySpaceOptimized();
void DPArray();

int main(){
    int intChoice;
    cout << "Enter Choice\n1. 2-D Array Dynamic Programming\n2. 1-D Array Dynamic Programming\n";
    cin >> intChoice;
    if(intChoice == 1){
        DPArray();
    }
    else if(intChoice == 2){
        DPArraySpaceOptimized();
    }
    else{
        cout << "Error Choice!";
    }
    return 0;
}

void DPArraySpaceOptimized(){
    int arrItem[4][2] = {{1, 1}, {2, 6}, {3, 10}, {2, 7}};
    /*
    Item 1: Wt: 1 V: 1
    Item 2: Wt: 2 V: 6
    Item 3: Wt: 3 V: 10
    Item 4: Wt: 2 V: 7
    */
    int intSize = 4, intMaxWeight = 5, i, w;
    int arrDP[intMaxWeight + 1] = {0}; //Uses Dynamic Programming 1D Array, initialized to 0
    for (i = 1; i <= intSize; i++){
        int intItemWeight = arrItem[i - 1][0];
        int intItemValue = arrItem[i - 1][1];
        for(w = intMaxWeight; w >= intItemWeight; --w){ //updates the array from high to low order of weight
            arrDP[w] = max(arrDP[w], arrDP[w - intItemWeight] + intItemValue); //arrDP updates if current value is greater than previous value 
        }
    }
    
    cout << "Maximum Value with " << intMaxWeight << " restriction: " << arrDP[intMaxWeight];
    cout << endl << "1D DP Array: ";
    for(i = 1; i <= intMaxWeight; i++){
        cout << arrDP[i] << " ";
    }
}

void DPArray(){
    int arrItem[4][2] = {{1, 1}, {2, 6}, {3, 10}, {2, 7} }; // {weight, value}
    /*
    Item 1: Wt: 1 V: 1
    Item 2: Wt: 2 V: 6
    Item 3: Wt: 3 V: 10
    Item 4: Wt: 2 V: 7
    */
    int intSize = 4, intMaxWeight = 5;

    // dp[i][w] = max value using first i items with weight limit w
    int arrDP[intSize + 1][intMaxWeight + 1];

    // Initialize all to 0
    for (int i = 0; i <= intSize; i++) {
        for (int w = 0; w <= intMaxWeight; w++) {
            arrDP[i][w] = 0;
        }
    }

    // Fill the DP table
    for (int i = 1; i <= intSize; i++) {
        int intItemWeight = arrItem[i - 1][0];
        int intItemValue = arrItem[i - 1][1];
        for (int w = 0; w <= intMaxWeight; w++) {
            if (intItemWeight <= w) {
                arrDP[i][w] = max(arrDP[i - 1][w], arrDP[i - 1][w - intItemWeight] + intItemValue);
            } else {
                arrDP[i][w] = arrDP[i - 1][w];
            }
        }
    }

    // Print the full DP table
    cout << "DP Table (Rows = items, Columns = weights 0 to " << intMaxWeight << "):\n";
    for (int i = -1; i <= intMaxWeight; i++){
        if(i == -1){
            cout << "\t";
        }
        else
            cout << i << "\t";
    }
    cout << endl;
    //To get the subset of items with maximum value 
    for (int i = 1; i <= intSize; i++) {
        cout << i << "\t";
        for (int w = 0; w <= intMaxWeight; w++) {
            cout << arrDP[i][w] << "\t";
        }
        cout << endl;
    }
    // Print final result
    cout << "\nMaximum value with weight limit " << intMaxWeight << ": " << arrDP[intSize][intMaxWeight] << endl;
    int w = intMaxWeight;
    int i = intSize;
    cout << "\nSubset: ";
    
    while(w > 0 || i > 0){
        if(arrDP[i][w] > arrDP[i - 1][w]){
            cout << i << " ";
            w = w - arrItem[i - 1][0];
        }
        i--;

    }
}
