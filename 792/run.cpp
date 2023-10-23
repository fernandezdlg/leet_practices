#include <iostream>
#include <string>
#include <vector>
#include <queue>

// #include <map>
// #include <algorithm>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
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
        else  // error
        {
            // return error message
            return false;
        }
    }
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int ct = 0;

        // transform vector<string>& words into priority queue<vector>&
        priority_queue<queue<string>> q;
        queue<string>                 p;

        for (const string& word : words)
        {
            // reinitialize p
            p = queue<string>();
            for (const char& c : word)
            {
                // push character into p
                p.push(c);
            }
            q.push(p);
        }

        return ct;
    }
};


int main()
{
    Solution sol;

    string         test1 = "abcde";
    vector<string> test2 = { "a", "bb", "acd", "ace" };

    int a = sol.numMatchingSubseq(test1, test2);
    cout << a << endl;

    return 0;
}
