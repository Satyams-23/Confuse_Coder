// factorial of a number using recursion

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }

//     return n * factorial(n - 1);
// }

// int main()
// {
//     int n = 5;
//     cout << factorial(n) << endl;
//     return 0;
// }

// fibonacci series using recursion

// #include <iostream>
// using namespace std;

// int fibonacci(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int main()
// {
//     int n = 5;
//     cout << fibonacci(n) << endl;
//     return 0;
// }

// sum of digits of a number using recursion

// #include <iostream>
// using namespace std;

// int sumOfDigits(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     return n % 10 + sumOfDigits(n / 10);
// }

// int main()
// {
//     int n = 12345;
//     cout << sumOfDigits(n) << endl;
//     return 0;
// }

// sum of natural numbers using recursion

// #include <iostream>
// using namespace std;

// int sumOfNaturalNumbers(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     return n + sumOfNaturalNumbers(n - 1);
// }

// int main()
// {
//     int n = 5;
//     cout << sumOfNaturalNumbers(n) << endl;
//     return 0;
// }

// how many ways to reverse a string using recursion

// #include <iostream>
// #include <string>
// using namespace std;

// void substr(string s, string ans)
// {
//     if (s.size() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     char ch = s[0];
//     string ros = s.substr(1);
//     substr(ros, ans);
//     substr(ros, ans + ch);
//     cout << ans << endl;
// }

// void reverse(string s)
// {
//     if (s.size() == 0)
//     {
//         return;
//     }

//     reverse(s.substr(1));           //  s.substr(1) means from 1 to end of the string s
//     cout << s.substr(0, 1) << endl; // s.substr(0, 1) means from 0 to 1 of the string s
//     cout << s[0];                   // s[0] means first character of the string s
// }

// int main()
// {
//     string s = "hello";
//     reverse(s);
//     cout << endl;
//     return 0;
// }

// how to binary search using recursion in an array of integers using recursion in c++

// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int> &arr, int target, int start, int end)
// {
//     if (start > end)
//     {
//         return -1;
//     }

//     int mid = start + (end - start) / 2; // to avoid overflow error in case of large numbers we use this formula to calculate mid point of the array or vector
//     if (arr[mid] == target)
//     {
//         return mid;
//     }
//     else if (arr[mid] > target)
//     {
//         return binarySearch(arr, target, start, mid - 1);
//     }
//     else
//     {
//         return binarySearch(arr, target, mid + 1, end);
//     }
//     // cout << mid << endl;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int target = 5;
//     cout << binarySearch(arr, target, 0, arr.size() - 1) << endl;
//     return 0;
// }

// how to find in not sorted array using recursion in c++

// #include <iostream>
// #include <vector>
// using namespace std;

// int find(vector<int> &arr, int target, int start)
// {
//     if (start == arr.size())
//     {
//         return -1;
//     }

//     if (arr[start] == target)
//     {
//         return start;
//     }

//     return find(arr, target, start + 1);
// }

// int main()
// {
//     vector<int> arr = {1, 2, 5, 1, 1, 2, 6, 7, 8, 9};
//     int target = 5;
//     cout << find(arr, target, 0) << endl;
//     return 0;
// }