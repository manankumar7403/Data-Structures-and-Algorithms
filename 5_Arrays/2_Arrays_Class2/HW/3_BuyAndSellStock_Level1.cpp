// INPUT: prices = [7,1,5,3,6,4]
// OUTPUT: 5 (bought on 2nd day -> 1) and (sold on 5th day -> 6).
// PROFIT = 6 - 1 = 5(max)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i=0; i<prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i]-minPrice);
    }
    return maxPro;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<prices.size(); i++)
    {
        cin >> prices[i];
    }
    cout << "The array is: " << endl;
    for(int i=0; i<prices.size(); i++)
    {
        cout << prices[i] << " ";
    }
    cout << endl;

    cout << "Max profit after selling stock is: " << maxProfit(prices) << endl;
    return 0;
}