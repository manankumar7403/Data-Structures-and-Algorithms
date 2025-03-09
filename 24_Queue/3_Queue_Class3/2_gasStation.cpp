// 🔴🔴🔴🔴 LEETCODE 134 -> Gas Station 🔴🔴🔴🔴
/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next
(i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the
circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be
unique.

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

Constraints:
n == gas.length == cost.length
1 <= n <= 10^5
0 <= gas[i], cost[i] <= 10^4
*/

// ________________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // kitna petrol kam pad gya
    int deficit = 0;
    // kitna petrol bacha hua hai
    int balance = 0;
    // circuit kaha se start kiya hai
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i]; // curr balance = purana balance + refill - cost
        if (balance < 0)
        {
            deficit = deficit + balance; // jitne petrol ki kami padi(curr se next petrol pump pe jaane ke liye) usse deficit me store kar liya
            start = i + 1;        // aur agle index se start kar rhe jaha se aage nhi ja pa rhe kyuki let's
            // say 1st,2nd,3rd gas station ki gas mila kar itna nhi ho pa rhi ki 4th gas station par pahuch jaye
            // toh 2nd aur 3rd gas station ki gas se bhi nahi pahuch payenge. Toh is logic ko use karte hue kyuki
            // hume circular gas station ka ek chakkar kaatna hai hum ith index(current index) + 1 se shuru karte hai

            // new index se start karke 1 revolution karne ki try kar rhe hai dobara se
            balance = 0;
        }
    }

    if (deficit + balance >= 0) // agar next index (start=i+1) se start kar rhe hai aur baaki sab gas stations pe
    // travel kar pa rhe hai toh deficit+balance >= 0 hoga kyuki jo deficit tha usko poora karna ke liye gas mil
    // gyi hai toh matlab start sahi position hai aur hume ussi se start karna chahiye -> eliminates the circular nature of the question
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout << "Enter the number of gas stations: " << endl;
    cin >> n;
    vector<int> gas(n);
    cout << "Enter the amount of gas:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> gas[i];
    }

    vector<int> cost(n);
    cout << "Enter the cost(distance):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cout << "Start at station " << canCompleteCircuit(gas, cost);
    cout << endl;
    return 0;
}

// Bohot zyada important question hai -> revisit

// TC -> O(n)
// SC -> O(1)