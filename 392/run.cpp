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



class Solution {
public:
    bool isSubsequence(string s, string t) {
        // put s and t into queues
        queue<char> tq;
        for (const char& c : t)
        {
            tq.push(c);
        }
        queue<char> sq;
        for (const char& c : s)
        {
            sq.push(c);
        }

        // find first character in sq in tq, while popping tq
        while (!tq.empty())
        {
            if (tq.front() == sq.front())
            {
                sq.pop();
            }
            tq.pop();
        }
        
        if (sq.empty())
        {
            return true;
        }
        else if (tq.empty())
        {
            return false;
        }
        else //error
        {
            //return error message
            return false;
        }
    }
};


int main()
{
    Solution solution;

    vector<string> strings = {"acd","adbce"};

    bool result = solution.isSubsequence(strings[0], strings[1]);

    cout << result << endl;
    return 0;
}
