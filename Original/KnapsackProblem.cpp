#include <iostream>
using namespace std;

int main() {

    int n, maxWeight, sizeCounter = 0;
    cout << "Enter size: ";
    cin >> n;
    cout <<"\nEnter max weight: ";
    cin >> maxWeight;
    int item[n][2];
    for (sizeCounter = 0; sizeCounter < n; sizeCounter++){
        cout << "Enter weight of Item " << sizeCounter + 1 << ": ";
        cin >> item[sizeCounter][0];
        cout << "\nEnter Value of Item " << sizeCounter + 1 << ": ";
        cin >> item[sizeCounter][1];
    }
    int mask, i;
    int totalWeight, totalValue;
    int highestValue = 0;
    for(mask = 0; mask < (1 << n); mask++){ 
        totalWeight = 0; 
        totalValue = 0; 
        
        cout << endl; 
        cout << "Subset: "; 
        for(i = 0; i < n; i++){ 
            if(mask & (1 << i)){ 
                totalWeight += item[i][0]; 
                totalValue += item[i][1]; 
                cout << i + 1 << " "; 
            } 
        }
        if(totalWeight <= maxWeight){ 
            if(highestValue < totalValue){ 
                highestValue = totalValue; 
            }
        }
        else{ 
            cout << "\nExceeds Max Weight!\n"; 
        }
        cout << endl << "Total Weight: " << totalWeight << endl << "Total Value: " << totalValue << endl; 
    }
    cout << "Highest value with total with " << maxWeight << "kg restriction: " << highestValue; 

    return 0;
}
