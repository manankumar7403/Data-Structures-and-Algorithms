#include <iostream>
#include <vector>
using namespace std;

int findMissingElement(vector<int>& sortedVector) {
    int start = 0;
    int end = sortedVector.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (sortedVector[mid] == mid + 1)
        {
            // Missing element is on the right side
            start = mid + 1;
        }
        else
        {
            // Missing element is on the left side
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return start + 1;
}

int main() {
    vector<int> sortedVector = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int missingElement = findMissingElement(sortedVector);
    cout << "Missing element: " << missingElement << endl;
    return 0;
}

