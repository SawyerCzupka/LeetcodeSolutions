// Longest Repeating Character Replacement

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other
uppercase English character. You can perform this operation at most k times.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.

Status: PASSED
*/

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int left = 0, right = 0;
        int maxRepeating = 0;
        int ans = -1;
        unordered_map<char, int> mp;

        while (right < n)
        {
            mp[s[right]]++; // When the window expands, increment char count

            maxRepeating = max(maxRepeating, mp[s[right]]);
            int window_size = right - left + 1;

            if (window_size - maxRepeating > k)
            {
                mp[s[left]]--;
                left++;
            }

            window_size = right - left + 1;
            ans = max(ans, window_size);
        }

        return ans;
    }
};