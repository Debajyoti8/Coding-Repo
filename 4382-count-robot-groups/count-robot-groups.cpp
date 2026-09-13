class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        // TC: O(n)
        // SC: O(1)

        int n = position.size();

        // Initially assume every robot forms a separate group
        int ans = n;

        // Speed of the slowest group/robot on the right side
        int mini = speed.back();

        // Traverse from right to left because a robot can only
        // catch a robot/group present on its right.
        for(int i = n - 2; i >= 0; i--)
        {
            // Current robot will NOT form a separate group if:
            //
            // 1. speed[i] > mini:
            //    Current robot is faster than the slowest group
            //    on its right, so it can eventually catch it.
            //
            // OR
            //
            // 2. position[i+1] - position[i] <= distance:
            //    The current robot and next robot are already close
            //    enough to merge immediately.
            if(mini < speed[i] || position[i+1] - position[i] <= distance)
            {
                // Current robot joins an existing group,
                // so reduce the number of groups.
                ans--;
            }
            else
            {
                // Current robot cannot catch any group on the right,
                // so it remains a separate group.
                //
                // Since it is a surviving group, update 'mini'
                // to its speed for the next robots on the left.
                mini = speed[i];
            }
        }

        return ans;
    }
};