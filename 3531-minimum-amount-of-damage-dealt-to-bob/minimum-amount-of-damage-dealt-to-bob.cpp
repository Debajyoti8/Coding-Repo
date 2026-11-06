
/*
Time Complexity: O(N log N)
- Calculate threat ratios: O(N)
- Sort enemies: O(N log N)
- Calculate total damage: O(N)

Space Complexity: O(N)
- Store threat ratios and original enemy indices.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {

        int n = damage.size();

        // Store {time_to_kill / damage, original_index}
        vector<pair<double, int>> threat(n);

        // Calculate the threat ratio for every enemy
        for (int i = 0; i < n; i++) {

            // Calculate the number of attacks required to kill enemy i
            double time_to_kill = ceil((double)health[i] / power);

            // Store the ratio along with the original index
            threat[i] = {time_to_kill / damage[i], i};
        }

        // Greedy sorting:
        // Kill enemies with smaller (time_to_kill / damage) ratio first
        // This is equivalent to sorting (damage / time_to_kill) in descending order
        sort(threat.begin(), threat.end());

        // Stores the minimum total damage received by Bob
        ll totalDamage = 0;

        // Initially, all enemies are alive
        // Calculate the combined damage dealt by all enemies per second
        ll cumulativeDamage = accumulate(damage.begin(), damage.end(), 0LL);

        // Process enemies in the optimal killing order
        for (int i = 0; i < n; i++) {

            // Retrieve the original index of the current enemy
            int idx = threat[i].second;

            // Calculate the time required to kill this enemy
            int time_to_kill = ceil((double)health[idx] / power);

            // All currently alive enemies deal damage during this time
            totalDamage += cumulativeDamage * time_to_kill;

            // The current enemy is now eliminated
            // Remove its damage contribution from the cumulative damage
            cumulativeDamage -= damage[idx];
        }

        // Return the minimum total damage received by Bob
        return totalDamage;
    }
};
