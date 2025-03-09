// 🔴🔴LEETCODE 3232 -> Find If Digit Game Can Be Won🔴🔴
/*
You are given an array of positive integers nums.
Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit
numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly
greater than the sum of Bob's numbers.
Return true if Alice can win this game, otherwise, return false.

Example 1:
Input: nums = [1,2,3,4,10]
Output: false
Explanation:
Alice cannot win by choosing either single-digit or double-digit numbers.

Example 2:
Input: nums = [1,2,3,4,5,14]
Output: true
Explanation:
Alice can win by choosing single-digit numbers which have a sum equal to 15.

Example 3:
Input: nums = [5,5,5,25]
Output: true
Explanation:
Alice can win by choosing double-digit numbers which have a sum equal to 25.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 99
*/
// ___________________________________________________________________________________________________

#include<iostream>
#include<vector>
using namespace std;

bool canAliceWin(vector<int> &nums)
{
    int singleDigitSum = 0;
    int doubleDigitSum = 0;
    int totalSum = 0;
    for (int num : nums)
    {
        if (num >= 1 && num <= 9)
        {
            singleDigitSum = singleDigitSum + num;
        }
        else if (num >= 10 && num <= 99)
        {
            doubleDigitSum = doubleDigitSum + num;
        }
        totalSum = totalSum + num;
    }
    int BobDoubleDigitSum = totalSum - singleDigitSum;
    int BobSingleDigitSum = totalSum - doubleDigitSum;
    return (singleDigitSum > BobDoubleDigitSum) || (doubleDigitSum > BobSingleDigitSum);
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    if(canAliceWin(nums))
    {
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    return 0;
}