class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;            // Start by giving 1 candy to the first child
        int i = 1;
        int n = ratings.size();

        while (i < n) {

            // Case 1: Equal ratings — just give 1 candy and move on
            if (ratings[i] == ratings[i - 1]) {
                sum++;          // Flat → all get 1
                i++;
                continue;
            }

            // Case 2: Increasing slope (like 1 → 2 → 3 )
            int up = 1;         // Length of up-slope (start at 1)
            while (i < n && ratings[i] > ratings[i - 1]) {
                up++;           // Increase slope height
                sum += up;      // Give increasing candies (1,2,3...)
                i++;
            }

            // Case 3: Decreasing slope (like 3 → 2 → 1 )
            int down = 0;       // Length of down-slope
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;         // Increase downward slope count
                sum += down;    // Give candies decreasing (but 1,2,3... in sum logic)
                i++;
            }
            down++;             // Include the turning point (peak itself)

            //  Peak Adjustment
            // If the down slope is longer or equal to up slope,
            // then the peak was not given enough candies earlier,
            // so we add extra (down - up) to balance it.
            if (down > up) {
                sum += down - up;
            }
        }

        return sum;
    }
};
