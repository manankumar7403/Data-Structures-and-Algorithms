//🔴🔴🔴🔴 Allocate minimum number of pages 🔴🔴🔴🔴

// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books,
// with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the student with the most books
// allocated to him gets the minimum number of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order
// (see the explanation for better understanding).

// Example 1:
// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113, which is selected as the output.

// Example 2:
// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as {15,17} and {20}.

// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 10^5
// 1 <= A [ i ] <= 10^6
// 1 <= M <= 10^5
// ____________________________________________________________________________________________

#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol) // sol is the mid only as mid will be the answer
{
    int pageSum = 0; // will store the current page sum
    int student = 1; // how many allocated?
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol) // if the number of pages in the current book are greater than the solution, it cannot be allocated
        {
            return false;
        }
        if (pageSum + A[i] > sol) // if the current sum and book to be allocated have more number of pages than the solution, we go to the next student.
        {
            student++;
            pageSum = A[i]; // Giving the book to the next student
            if (student > M)
            {
                return false; // students exceeded maximum students
            }
        }
        else
        {
            pageSum = pageSum + A[i]; // current pagesum + A[i] pages of current book not more than the solution, we will keep on adding
        }
    }
    return true;
}

// Function to find minimum number of pages.
int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1; // students greater than books, some will not be allocated a book

    // creating the search space using start and end
    int start = 0;
    int end = accumulate(A, A + N, 0); // start point of arr, end point of arr, initial sum
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(A, N, M, mid))
        {
            // store ans
            ans = mid;
            // minimize the solution to be more precise, therefore search left
            end = mid - 1; // if solution found, we will try to minimize it -> as small as possible
        }
        else
        {
            // solution not found in the current search space, search right
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int N, M;
    cout << "Enter the number of books: " << endl;
    cin >> N;
    cout << "Enter the number of students: " << endl;
    cin >> M;
    int A[N];
    cout << "Enter the number of pages in each book: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Book " << (i + 1) << ": ";
        cin >> A[i];
    }

    int result = findPages(A, N, M);

    if (result != -1)
    {
        cout << "The minimum number of pages each student should read is: " << result << endl;
    }
    else
    {
        cout << "Not possible to allocate books such that each student gets at least one book." << endl;
    }
    return 0;
}

// Time Complexity: O(N log M)
// Space Complexity: O(1)