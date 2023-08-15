#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int totalSum = 0;
        int n = nums.size();

        int numSum = 0;

        for (int i = 0; i <= n; i++)
        {
            totalSum += i;
        }

        for (int i = 0; i < n; i++)
        {
            numSum += nums[i];
        }

        return totalSum - numSum;
    }
};