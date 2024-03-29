/*
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) 
are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

*/

//Question available on Leetcode and GFG

//T.C = O(3N)
//S.C = O(3N)

int trap(vector<int>& height) {

    int n = height.size();
    
    //First we need to create arrays to store the maximum left and
    //maximum right elements from the given array.

    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    
    maxLeft[0] = height[0];
    
    //taking maximum from left to right
    for(int i = 1; i<n; i++){
        maxLeft[i] = max(maxLeft[i-1],height[i]);
    }
    
    //taking maximum from right to left
    maxRight[n-1] = height[n-1];
    for(int i = n-2; i>=0; i--){
        maxRight[i] = max(maxRight[i+1],height[i]);
    }
    
    vector<long long> water(n);
    long long totWater = 0;
    
    //Formula to calculate water stored at each building 
    for(int i = 0; i<n; i++){
        water[i] = min(maxLeft[i],maxRight[i]) - height[i];
    }
    
    for(int i = 0; i<water.size();i++){
        totWater+=water[i];
    }
    
    return totWater;
}