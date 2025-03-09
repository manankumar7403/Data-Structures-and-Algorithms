// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting.
// The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the
// function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8).
// A cook with a rank R can cook 1 prata in the first R minutes, 1 more prata in the next 2R minutes,
// 1 more prata in 3R minutes and so on (he can only cook a complete prata)
// (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next
// 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes
// also he can cook only 3 pratas as he does not have enough time for the 4th prata).
// The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

// Input
// The first line tells the number of test cases. Each test case consist of 2 lines.
// In the first line of the test case we have P the number of prata ordered. In the next line the first
// integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a
// cook.

// Output
// Print an integer which tells the number of minutes needed to get the order done.

// Example
// Input:
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Output:
// 12
// 36
// 1

// ____________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int>& cooksRanks, int nP, int mid)
{
    int currP = 0; // initial cooked prata count
    for(int i=0; i<cooksRanks.size(); i++)   // cooksRanks.size() gives the number of cooks
    {
        int R = cooksRanks[i], j=1;
        // R=cooksRanks[i] -> taking out the rank of each cook
        // j=1 -> we had to calculate the time taken according to ranks like 1R+2R+3R+....
        // so 1,2,3 will be taken care of by 'j'.
        
        int timeTaken = 0;     // calculates the current total sum of time taken by cooks

        while(true)
        {
            if(timeTaken + j * R <= mid)        // if the time taken (initially) + j*R(time for current prata being made) is less than equal to 'mid' -> total time available, the current cook will keep on making pratas
            {
                currP++;                        // keep on making pratas
                timeTaken = timeTaken + j * R;  // add the time of current prata(j*R) in the original time (timeTaken)
                j++;                            // increase the time according to rank constraint (1R+2R+3R+4R..) j is number 1,2,3,4......
            }
            else
            // if total time taken is more than available time then break and we will go to the for loop
            // again and i will be updated so we will move to the next cook(int R = cooksRanks[i], j=1)
            // R=cooksRanks[i] -> taking out the rank of each cook
            {
                break;
            }
        }
        if(currP >= nP)           // equal or more number of pratas made than ordered, so returns true
        {
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int>& cooksRanks, int nP)
{
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());  // finding the highest rank of cook 
    int end = highestRank * (nP * (nP + 1) / 2);         // giving all the pratas to the cook with the highest rank -> maximum time(most inefficient cook) will be taken -> end of search space
    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(isPossibleSolution(cooksRanks, nP, mid))    // checking whether in 'mid' time all the pratas could be made
        {
            // true, so we will store the ans first
            ans = mid;
            // then, we will try to minimize the time and check whether we get a better solution
            end = mid-1;            
        }
        else
        {
            // couldn't find a solution in the current search space, so we will move to the right to find a solution
            start = mid+1;
        }
    }
    return ans;
}

int main()
{
    int T;
    cout << "Enter the number of test cases: " << endl;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        int nP, nC;
        cout << "Enter the number of pratas for test case " << (i+1) <<": ";
        cin >> nP;
        cout << "Enter the number of cooks for test case " << (i+1) <<": ";
        cin >> nC;
        vector<int> cooksRanks;
        for(int j=0; j<nC; j++)
        {
            int R;
            cout << "Rank cook " << (j+1) <<": ";
            cin >> R;
            cooksRanks.push_back(R);
        }
        cout << "Number of minutes to get the order done: " << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    }
    return 0;
}