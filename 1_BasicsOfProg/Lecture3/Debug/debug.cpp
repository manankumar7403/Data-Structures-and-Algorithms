// Q1 The below code snippet has some errors. Let’s debug it and make it compile & run successfully.
// void main() {
// 	int i=0;
// 	i=i+1;
// 	cout<<i:
// 	/*print i \*//i=i+1
// 	cout<<++i;
// }

// SOLUTION

// #include <iostream>
// using namespace std;
// int main()
// {
//     int i=0;
//     i=i+1;
//     cout<<i<<endl;
//     cout<<++i;
//     return 0;
// }

// Q2 Below code should print the sum of ‘i’ and ‘j’.
// void main() {
// 	short i=2300, j=4322;
// 	cout>>"i+j=">>-(i+j);
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main()
// {
//     short i=2300,j=4322;
//     cout<<"i+j= "<<i+j;
// }

// Q3 Find perimeter of a rectangle.
// void main() {
// 	float l, b;
// 	P = 2(l+b);
// 	printf("Perimeter=", P);
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main()
// {
//     float l,b,P;
//     cout<<"Enter the length of the rectangle: ";
//     cin>>l;
//     cout<<"Enter the breadth of the rectangle: ";
//     cin>>b;
//     P=2*(l+b);
//     cout<<"Perimeter of the rectangle is: "<<P;
//     return 0;
// }

// Q4 Print solid square pattern.
// void main() {
// 		int n;
//     cin>>n;
//     for (int i=0; i<n; ++i) {
//         for (int j=0; j<n; ++i) {
//             cout<<"*\n";
//         }
//         cout<<endl;
//     }
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main()
// {
//     int rows,columns;
//     cout<<"Enter the number of rows: ";
//     cin>>rows;
//     cout<<"Enter the number of columns: ";
//     cin>>columns;
//     for (int i=0; i<rows; i++)
//     {
//         for (int j=0; j<columns; j++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// Q5 Check given number is Prime or not.
// int main(){
// 	int n;
// 	cin >> n;
// 	bool isPrime = true;
//   for(int i=2;i<n;i++){
//       if(i%n == 0){
//           isPrime = false; break;
//       }
//   }
// 	if(isPrime){
// 		cout<<"Prime"<<endl;	
// 	}
// 	else{
// 		cout<<"Not Prime"<<endl;	
// 	}
//   return 0;
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Enter a number to check if it's prime or not: ";
//     cin>>n;
//     bool isPrime = true;
//     for (int i=2; i<n; i++)
//     {
//         if (n%i==0)
//         {
//             isPrime = false;
//             break;
//         }
//     }
//     if (n<=0 || n==1) {
//         isPrime = false;
//     }
//     if(isPrime)
//     {
//         cout<<n<<" is a prime number!"<<endl;
//     }
//     else
//     {
//         cout<<n<<" is not a prime number!"<<endl;
//     }
//     return 0;
// }

// Q6 Print Numeric Hollow Inverted Half Pyramid.
// void main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;++i){
//         for(int j=j+1;j<=n;j++){
//             if(j==i+1 || j == n - i - 1 || i == 0){
//                 cout<<j;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main()
// {
//     int rows;
//     cout<<"Enter the number of rows: ";
//     cin>>rows;
//     for (int i=0; i<rows; i++)
//     {
//         for (int j=i+1; j<=rows; j++)
//         {
//             if (j==i+1 || j==rows || i==0)
//             {
//                 cout<<j<<" ";
//             }
//             else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// Q7. Print following pattern.
// int main() {
//   int n;
//   std::cin>>n;
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n - i - 1; j++) {
//       printf("  ");
//     }
//     for (int j = i; j < i; j++) {
//       printf("%d ", j);
//     }
//     int ele = 2 * (n - i - 1);
//     for (int j = 1; j <= i - 1; j++) {
//       printf("%d ", ele--);
//     }
//     printf("\n");
//   }
//   return 0;
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main() {
//   int rows;
//   cout<<"Enter the number of rows: ";
//   cin>>rows;
//   for (int i=1; i<=rows; i++)
//   {
//     for (int j=1; j<=rows-i; j++)
//     {
//       cout<<"  ";
//     }
//     for (int j=i; j<2*i; j++)
//     {
//       cout<<j<<" ";
//     }
//     int ele = 2 * (i - 1);
//     for (int j = 1; j <= i - 1; j++)
//     {
//       cout<<ele--<<" ";
//     }
//     cout<<endl;
//   }
//   return 0;
// }

// Q8. Print hollow full pyramid pattern.
// void main(){
//     int n;
//     cin>>n;
//     for (int i=0; i<n; ++i) {
//         for (int j=0; j<n*2-1; ++j) {
// 		        int k=0;
//             if(j<n-i-1){
//                 cout<<" ";
//             }
//             else if(k < 2*i+1){
//                 if(k==0 || k == 2*i - 1 || i == n - 1){
//                     cout<<"*";
//                 }
//                 else{
//                     cout<<" ";
//                 }
//             }
//             else{
//                 cout<<" ";
//             } k++;
//         }
//         cout<<endl;
//     }
// }

// SOLUTION
// #include <iostream>
// using namespace std;
// int main(){
//     int rows;
//     cout<<"Enter the number of rows: ";
//     cin>>rows;
//     for (int i=0; i<rows; i++) {
//         int k=0;
//         for (int j=0; j<rows*2-1; j++) { /*always 0 to 9*/
//             if(j<rows-i-1){
//                 cout<<" ";
//             }
//             else if(k < 2*i+1){
//                 if(k==0 || k == 2*i || i == rows - 1){
//                     cout<<"*";
//                 }
//                 else{
//                     cout<<" ";
//                 }
//                 k++;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }