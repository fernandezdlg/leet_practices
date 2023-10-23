#include <vector>
#include <iostream>
#include <numeric>

using namespace std;  // Add this line to use the std namespace

class Solution {
public:
    int candy(vector<int>& ratings) {
        const short int n = ratings.size();
        vector<short int> candies(n, 1);

        for (size_t i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (size_t i = n - 1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                candies[i-1] = max(candies[i-1], static_cast<short int>(candies[i] + 1));
            }
        }

        return reduce(candies.begin(), candies.end(), 0);
    }
};


int main()
{
    Solution solution;  // Create an instance of the Solution class

    vector<int> rating = { 1, 0, 4 };  // Use curly braces to initialize the vector

    int result = solution.candy(rating);  // Call the candy function on the instance

    cout << result << endl;  // Print the result
    return 0;
}
