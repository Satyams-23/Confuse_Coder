// Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

// brute force approach
// Approach: The brute force approach is simple, for each bar, we calculate the area of the largest rectangle that can be formed including that bar. We then return the maximum of all the areas calculated. The time complexity for this approach is O(n^2).

// intuition behind the approach is to find the left and right boundary of the rectangle for each bar and then calculate the area of the rectangle
// to find the left boundary of the rectangle we will traverse the array from the current bar to the left and find the first bar which is smaller than the current bar and store its index in the left array and similarly for the right boundary we will traverse the array from the current bar to the right and find the first bar which is smaller than the current bar and store its index in the right array and then calculate the area of the rectangle using the formula (right[i]-left[i]-1)*heights[i] and return the maximum of all the areas calculated

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n), right(n); //
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top(); //
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl; // 10
    return 0;
}
