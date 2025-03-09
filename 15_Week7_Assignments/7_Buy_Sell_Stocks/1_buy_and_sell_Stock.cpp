#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxPro)
{
    // Base case
    if(i == prices.size()) return;

    // ek case solve kardo
    if(prices[i] < minPrice) minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;
    if(todaysProfit > maxPro) maxPro = todaysProfit;

    // Baaki recursion sambhal lega
    maxProfitFinder(prices, i+1, minPrice, maxPro);
}

int maxProfit(vector<int>& prices)
{
    int minPrice = INT_MAX;
    int maxPro = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxPro);
    return maxPro;
}

int main()
{
    vector<int>prices{7,1,5,3,6,4};
    cout << maxProfit(prices);
    cout << endl;
    return 0;
    return 0;
}

// {7,1,5,3,6,4}
// output should be 5 (buy on 2nd day -> 1) & (sell on 5th day -> 6)
// 6-1 = 5 (max Profit)

