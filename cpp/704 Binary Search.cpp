#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        return binary_search(nums, target, 0, n - 1);
    }

    int binary_search(vector<int> &nums, int target, int start_index, int end_index)
    {
        int n = end_index - start_index;
        int middle = start_index + (n / 2);

        if (n + 1 == 1)
        {
            return (nums[middle] == target) ? middle : -1;
        }

        else if (n + 1 == 2)
        {
            int left = binary_search(nums, target, start_index, middle);
            int right = binary_search(nums, target, middle + 1, end_index);

            return (right > left) ? right : left;
        }

        else if (n + 1 >= 3)
        {
            if (nums[middle] == target)
            {
                return middle;
            }

            else if (nums[middle] > target)
            {
                return binary_search(nums, target, start_index, middle - 1);
            }

            else
            {
                return binary_search(nums, target, middle + 1, end_index);
            }
        }

        return -1;
    }

    int search2(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};