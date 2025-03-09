// #include <iostream>
// using namespace std;

// int main()
// {
//     int row = 5;
//     int col = 3;

//     int** arr = new int*[5];

//     for(int i=0; i<row; i++)
//     {
//         arr[i] = new int[col];
//     }

//     // printing
//     for(int i=0; i<row; i++)
//     {
//         for(int j=0; j<col; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }

//     // Deallocate
//     for(int i=0; i<row; i++)
//     {
//         delete[] arr[i];
//     }
//     delete[] arr;
//     return 0;
// }

// __________________________________________________________________________________________________

// Par hum toh double vector bana lenge jo stack pe chalta hai

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int row = 5;
//     int col = 6;
//     vector<vector<int> > arr(row, vector<int>(col, 0));
//     for(int i=0; i<row; i++)
//     {
//         for(int j=0; j<col; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }