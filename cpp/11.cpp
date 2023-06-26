#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int maxArea = 0;

        int i = 0, j = n - 1;

        while (i < j)
        {
            maxArea = max(min(height[i], height[j]) * (j - i), maxArea);

            if (height[i] > height[j])
            {
                j--;
            }

            else
            {
                i++;
            }
        }

        return maxArea;
    }
};