#include <iostream>
using namespace std;

//Function for swapping values
void swapValues(int &intNum1, int &intnum2){
    int temp = intNum1;
    intNum1 = intnum2;
    intnum2 = temp;
}

//Optimized code for selection sort
int optimizedSelectionSort(int arrNumbers[], int intArrLength){
    int intPassCount = 0;
    int intLeftIndex = 0;
    int intRightIndex = intArrLength - 1;
    bool boolSwapped = true;

    //Loops through the array while the left-right indexes do not overlap and elements are still being swapped
    while(intLeftIndex < intRightIndex && boolSwapped == true){
        boolSwapped = false;
        int intMinIndex = intLeftIndex;
        int intMaxIndex = intRightIndex;

        //Finds the minimum and maximum indices in the unsorted part of the array
        for(int i = intLeftIndex; i <= intRightIndex; i++){
            if(arrNumbers[i] < arrNumbers[intMinIndex]){
                intMinIndex = i;
            }
            if(arrNumbers[i] > arrNumbers[intMaxIndex]){
                intMaxIndex = i;
            }
        }

        //Swaps the smallest value to the left
        if(intMinIndex != intLeftIndex){
            swapValues(arrNumbers[intLeftIndex], arrNumbers[intMinIndex]);
            boolSwapped = true;
        } 

        //Handles overlap between the min and max index during swapping
        if(intMaxIndex == intLeftIndex){
            intMaxIndex = intMinIndex;
        }
        
        //Swaps the largest value to the right
        if(intMaxIndex != intRightIndex){
            swapValues(arrNumbers[intRightIndex], arrNumbers[intMaxIndex]);
            boolSwapped = true;
        }

        intLeftIndex++;
        intRightIndex--;
        intPassCount++;
    }
    
    return intPassCount;
}

//Print arrNumbers function
void printArray(int arrNumbers[], int intArrLength){
    for(int i = 0; i < intArrLength; i++){
        cout << arrNumbers[i] << " ";
    }
}

//main function
int main(){
    int arrNumbers[] = {19, 42, 12, 71, 201, 9, 14, 56, 2, 2941, 0, 19};
    int intArrLength = sizeof(arrNumbers) / sizeof(arrNumbers[0]);

    cout << "Unsorted Array: "; printArray(arrNumbers, intArrLength);
    int intPasses = optimizedSelectionSort(arrNumbers, intArrLength);
    cout << "\nSorted Array: "; printArray(arrNumbers, intArrLength);
    cout << "\nNumber of Passes: " << intPasses;

    return 0;
}