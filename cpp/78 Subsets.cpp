#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> output;

        for (int i = 0; i < n; i++)
        {
            int numOutputs = output.size();
            output.push_back(vector<int>{nums[i]});

            for (int j = 0; j < numOutputs; j++)
            {
                vector<int> temp(output[j].begin(), output[j].end());
                temp.push_back(nums[i]);

                output.push_back(temp);
            }
        }

        output.push_back(vector<int>());

        return output;
    }
};