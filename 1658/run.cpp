#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif

#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>


using namespace std;


class Solution
{
public:
    void vectorToQueue(const vector<int>& nums, queue<int>& q)
    {
        for (const int& num : nums)
        {
            q.push(num);
        }
    }
    // int function to sum all of queue<int> q

    int minOperations(vector<int>& nums, int x)
    {
        int minSum;
        int maxSum;

        queue<int> q;
        vectorToQueue(nums, q);

        
    }
};


int main()
{
    Solution solution;

    vector<int> test = { 1, 10, 1 };

    int result = solution.minOperations(test);

    cout << result << endl;
    return 0;
}
