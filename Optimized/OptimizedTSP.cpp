#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bitset>

using namespace std;

const int INF = INT_MAX / 2;    // infinity, but avoids integer overflow

int heldKarpAlgorithm(int numCities, const vector<vector<int>>& distanceMatrix, int startCity, vector<vector<int>>& bestRoutes) {
    const int totalSubsets = 1 << numCities;
    vector<vector<int>> dp(totalSubsets, vector<int>(numCities, INF));
    vector<vector<int>> parent(totalSubsets, vector<int>(numCities, -1));   // parent table for reconstruction

    dp[1 << startCity][startCity] = 0;  // starting at startCity

    for (int mask = 1; mask < totalSubsets; mask++) {
        for (int currentCity = 0; currentCity < numCities; currentCity++) {
            if (!(mask & (1 << currentCity))) continue;  // skip if city not in subset
            for (int nextCity = 0; nextCity < numCities; nextCity++) {
                if (mask & (1 << nextCity)) continue;  // skip if city already visited
                int newMask = mask | (1 << nextCity);
                if (dp[newMask][nextCity] > dp[mask][currentCity] + distanceMatrix[currentCity][nextCity]) {
                    dp[newMask][nextCity] = dp[mask][currentCity] + distanceMatrix[currentCity][nextCity];      // updates when better path is found
                    parent[newMask][nextCity] = currentCity;
                }
            }
        }
    }

    // fiind the minimum cost 
    int minCost = INF;
    int fullMask = (1 << numCities) - 1; // all cities visited

    for (int lastCity = 0; lastCity < numCities; lastCity++) {
        if (lastCity == startCity) continue;
        int totalCost = dp[fullMask][lastCity] + distanceMatrix[lastCity][startCity];
        if (totalCost < minCost) {
            minCost = totalCost;
            bestRoutes.clear();     // reset when better path is found
        }
        if (totalCost == minCost) {
            // reconstruct path from parent
            vector<int> path;
            int currentCity = lastCity;
            int currentMask = fullMask;
            while (currentCity != startCity) {
                path.push_back(currentCity);
                int prevCity = parent[currentMask][currentCity];
                currentMask ^= (1 << currentCity);
                currentCity = prevCity;
            }
            reverse(path.begin(), path.end());
            bestRoutes.push_back(path);
        }
    }

    // printing of optimal routes
    cout << "\nThe shortest route(s) is/are: \n";
    for (const auto& route : bestRoutes) {
        cout << startCity;
        for (int city : route) {
            cout << " -> " << city;
        }
        cout << " -> " << startCity << " | Total Distance: " << minCost << endl;
    }

    return minCost;
}

int main() {
    int numCities, startCity;
    cout << "Enter the number of cities: ";
    cin >> numCities;
    
    // asking for input
    vector<vector<int>> distanceMatrix(numCities, vector<int>(numCities));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> distanceMatrix[i][j];
        }
    }
    
    cout << "Enter the starting city (0-based index): ";
    cin >> startCity;

    vector<vector<int>> bestRoutes;
    int minDistance = heldKarpAlgorithm(numCities, distanceMatrix, startCity, bestRoutes);

    cout << "\nMinimum Distance: " << minDistance << endl;
    return 0;
}