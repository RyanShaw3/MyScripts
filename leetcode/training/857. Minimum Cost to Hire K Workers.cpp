#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<int> idxs(n, 0);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int &a, int &b)
             { return quality[a] * wage[b] > quality[b] * wage[a]; });
        int sumQ = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(quality[idxs[i]]);
            sumQ += quality[idxs[i]];
        }
        double ans = sumQ * ((double)wage[idxs[k - 1]] / quality[idxs[k - 1]]);
        for (int i = k; i < n; i++)
        {
            int idx = idxs[i];
            if (quality[idx] < pq.top())
            {
                sumQ = sumQ - pq.top() + quality[idx];
                pq.pop();
                pq.push(quality[idx]);
                ans = min(ans, sumQ * ((double)wage[idx] / quality[idx]));
            }
        }
        return ans;
    }
};
