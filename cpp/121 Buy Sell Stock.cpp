#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    { // n^2
        int maxProfit = 0;

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            int current = prices[i];

            for (int j = i - 1; j >= 0; j--)
            {
                int thisProfit = current - prices[j];

                if (thisProfit > maxProfit)
                {
                    maxProfit = thisProfit;
                }
            }
        }

        return maxProfit;
    }

    int maxProfit2(vector<int> &prices)
    { // tabular dynamic programming
        int n = prices.size();
        vector<int> maxPriceFromN(n, 0);

        maxPriceFromN[n - 1] = prices[n - 1]; // Max price for last element is itself
        for (int i = n - 2; i >= 0; i--)
        {
            maxPriceFromN[i] = max(maxPriceFromN[n + 1], prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, maxPriceFromN[i] - prices[i]);
        }

        return maxProfit;
    }

    int maxProfit3(vector<int> &prices)
    {
    }
};