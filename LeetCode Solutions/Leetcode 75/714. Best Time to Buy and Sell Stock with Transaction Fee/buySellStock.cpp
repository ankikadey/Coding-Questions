#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int sell = 0;
        int hold = INT_MIN;

        for (const int price : prices)
        {
            sell = max(sell, hold + price);
            hold = max(hold, sell - price - fee);
        }

        return sell;
    }
};