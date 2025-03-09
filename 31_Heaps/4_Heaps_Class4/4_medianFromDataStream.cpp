// ⭐⭐⭐⭐ HEAP KA SABSE IMPORTANT QUESTION HAI YE ⭐⭐⭐⭐

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void callMedian(double& median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap,
int element)
{
    // CASE1: Size of both heaps is the same
    if(minHeap.size() == maxHeap.size())
    {
        if(element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }

    // CASE2: Size of maxHeap is greater than minHeap
    else if(maxHeap.size() > minHeap.size())
    {
        if(element > median)
        {
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }

    // CASE3: Size of minHeap is greater than maxHeap
    else
    {
        if(element > median)
        {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
}

int main()
{
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout << "-> " << median << endl;
    }
    
    return 0;
}

// TC -> O(nlogn)
// SC -> O(n)

// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________
// ____________________________________________________________________________________________________________

/*
// ✅ Doing using signum function (switch case)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int a, int b)
{
    if(a == b)
    {
        return 0;
    }

    if(a > b)
    {
        return 1;
    }

    else      // a < b
    {
        return -1;
    }
}

void callMedian(double& median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap,
int element)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        // CASE1: Size of both heaps is the same
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }

        break;

    case 1:
        // CASE2: Size of maxHeap is greater than minHeap
        if (element > median)
        {
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }

        break;

    case -1:
        // CASE3: Size of minHeap is greater than maxHeap
        if (element > median)
        {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else
        {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        }

        break;
    }
}

int main()
{
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout << "-> " << median << endl;
    }
    
    return 0;
}
*/