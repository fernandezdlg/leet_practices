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
// #include <vector>
// #include <iostream>
// #include <numeric>
// #include <queue>
// #include <set>


// using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        // Using a set to store pairs of the sum of soldiers and their respective row indices
        set<pair<int, int>> soldiers;

        // Calculate the sum of soldiers for each row and store in the min heap
        for(int row = 0; row < mat.size(); row++) {
            int soldierCount = findSoldierCount(mat[row]);
            soldiers.insert({soldierCount, row}) ;
        }

        // Get the k weakest rows from the set
        vector<int> weakestRows;
        auto ptr = soldiers.begin() ;
        for(int i = 0 ; i < k ; i ++){
            weakestRows.push_back(ptr->second);
            ptr++ ;
        }
        return weakestRows;
    }

// Custom comparator to sort based on values while keeping track of indices
    static bool compareWithIndices(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.second < b.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    
    int findSoldierCount(vector<int> &row) {
        int left = 0, right = row.size() - 1;

        // Perform binary search to find the count of soldiers
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};



int main()
{
    Solution solution;

    vector<vector<int>> test = { { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
                                 { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                 { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    // Declare a vector of vectors
    int k = 1;


    vector<int> result = solution.kWeakestRows(test, k);

    cout << result[0] << endl;
    // cout << result[1] << endl;
    // cout << result[2] << endl;
    // cout << result[3] << endl;

    return 0;
}
