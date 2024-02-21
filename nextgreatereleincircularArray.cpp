/*
Given a circular integer array nums (i.e., the next element of 
nums[nums.length - 1] is nums[0]), return the next greater number for every 
element in nums.

The next greater number of a number x is the first greater number to its 
traversing-order next in the array, which means you could search circularly 
to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109


*/

//Optimised solution using stack

//T.C = O(2N + 2N) = O(N)
//S.C = O(N)

//Tip: the nature of the array is circular so when finding the next greater element. 
//To handle circular traversal, you need to traverse the array twice. One way 
//to do this is by doubling the length of the array and considering the indices 
//modulo the original length.

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;

        stack<int> s;

        int n = nums.size();

        for(int i = 2 * n - 1; i >= 0; i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n){
                if(!s.empty()){
                    v.push_back(s.top());
                }else{
                    v.push_back(-1);
                }
            }
            s.push(nums[i%n]);
        }
        reverse(v.begin(), v.end());
        return v;
}