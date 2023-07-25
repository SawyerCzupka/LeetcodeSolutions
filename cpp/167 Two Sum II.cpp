#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0;
        int high = numbers.size() - 1;

        while (numbers[low] + numbers[high] != target)
        {
            if (numbers[low] + numbers[high] < target)
            {
                low++;
            }

            else if (numbers[low] + numbers[high] > target)
            {
                high--;
            }
        }

        return {low + 1, high + 1};
    }
};