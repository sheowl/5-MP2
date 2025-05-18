#include <iostream>
using namespace std;

int main() {
    int arrItem[4][2] = {{1, 1}, {2, 6}, {3, 10}, {2, 7}}; //{weight, value}
    /*
    Item 1: Wt: 1 V: 1
    Item 2: Wt: 2 V: 6
    Item 3: Wt: 3 V: 10
    Item 4: Wt: 2 V: 7
    */
    int intSize = 4; //No. of Items
    int intMask, i; 
    int intTotalWeight, intTotalValue;
    int intMaxWeight = 5, intHighestValue = 0;
    for(intMask = 0; intMask < (1 << intSize); intMask++){ // to get all possible subsets 
        intTotalWeight = 0; 
        intTotalValue = 0; 
        cout << "\nSubset: "; 
        for(i = 0; i < intSize; i++){ // to know if the item is included in the subset
            if(intMask & (1 << i)){ //using bitwise AND operation
                intTotalWeight += arrItem[i][0]; 
                intTotalValue += arrItem[i][1]; 
                cout << i + 1 << " "; 
            } 
        }
        if(intTotalWeight <= intMaxWeight){ //if current subset item weight does not exceed max weight
            if(intHighestValue < intTotalValue){  // if current highest value is less than current subset item value 
                intHighestValue = intTotalValue;  // make the currect subset item value the highest value 
            }
        }
        else{ // if current subset item weight exceeds 
            cout << "\nExceeds Max Weight!\n"; 
        }
        cout << endl << "Total Weight: " << intTotalWeight << endl << "Total Value: " << intTotalValue << endl;  //prints every total weight and total value
    }
    cout << "Highest value with total with " << intMaxWeight << " kg restriction: " << intHighestValue; //prints highest value
    return 0;
}
