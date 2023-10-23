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
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        const int all = (1 << n) - 1; // fully explored graph

        queue<tuple> q; // queue of class tuple type

        
        return manhattanDistance(points[0],points[1]);
    }

    int manhattanDistance(vector<int>& point1, vector<int>& point2){
        return abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
    }
};

int main()
{
    Solution solution;

    // Declare a vector of vectors
    vector<vector<int>> test = {{0,1},{1,0}};

    int result = solution.minCostConnectPoints(test);

    cout << result << endl;

    return 0;
}
