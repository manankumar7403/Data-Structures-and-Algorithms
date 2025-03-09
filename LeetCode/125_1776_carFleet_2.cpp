// 🔴🔴LEETCODE 1776 -> Car Fleet 2🔴🔴
/*
There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of
length n, where cars[i] = [positioni, speedi] represents:
positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that
positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same
position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will
have the same position and the same speed, which is the initial speed of the slowest car in the fleet.
Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if
the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.

Example 1:
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed
1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.

Example 2:
Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]

Constraints:
1 <= cars.length <= 10^5
1 <= positioni, speedi <= 10^6
positioni < positioni+1
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    vector<double> answer(cars.size(), -1); // collision time of ith car with next car
    stack<int> st;                          // will store the index of the cars which are ahead than than current car

    for (int i = cars.size() - 1; i >= 0; i--)
    {
        // check if car ahead of current car is faster?
        while (!st.empty() && cars[st.top()][1] >= cars[i][1])
        {
            // collision impossible, pop
            st.pop();
        }
        while (!st.empty())
        {
            // collisionTime is calculated as (dist2-dist1)-(speed1-speed2)
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
            // collisionTime should either be less than other possible collision or -1(cars ahead wont collide before)
            // collisionTime of car at say 1pos with 2pos should be less than 2pos with 3pos otherwise 2 and 3 will collide before
            if (answer[st.top()] == -1 || colTime <= answer[st.top()])
            {
                answer[i] = colTime;
                break; // breaks as soon as collision time is found, stops inner loop, move on to the next car
            }
            st.pop(); // curr car i collTime with car at TOS > collTime of the car at TOS with some other car ahead(colTime > answer[st.top()] or answer[st.top()] == -1), jo gaadi aage hai vo pehle kisi se collide kar gyi hai, toh usse collide nhi karenge
        }
        st.push(i);
    }
    return answer;
}

int main()
{
    int n;
    cout << "Enter the number of cars:" << endl;
    cin >> n;
    vector<vector<int>>cars(n, vector<int>(2));
    cout << "Enter the position and speed of the cars:" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> cars[i][j];
        }
    }
    vector<double>collisionTime = getCollisionTimes(cars);
    for(auto i: collisionTime)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O(n)
// SC -> O(n)