/*
Find the largest rectangular area possible in a given histogram where the largest 
rectangle can be made of a number of contiguous bars. For simplicity, assume that 
all bars have the same width and the width is 1 unit, there will be N bars height 
of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12

Explanation: In this example the largest area would be 12 of height 4 and width 3. 
We can achieve this area by choosing 3rd, 4th and 5th bars.


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and 
its size N as inputs and finds the largest rectangular area possible and returns 
the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 10^6
0 ≤ arr[i] ≤ 10^12

*/

vector<long long> nearestSmallertoLeft(long long arr[],int n){

    vector<long long> v;
    
    stack<pair<long long,long long>> st;
    int psuedoIndex = -1;
    
    for(int i = 0; i<n; i++){
        if(st.empty()){
            v.push_back(psuedoIndex);
        }
        else if(!st.empty() && st.top().first < arr[i]){
            v.push_back(st.top().second);
        }
        else if(!st.empty() && st.top().first >= arr[i]){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(psuedoIndex);
            }
            else{
                v.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }
    
    return v;
}
    
vector<long long> nearestSmallertoRight(long long arr[],int n){
    vector<long long> ans;
    
    stack<pair<long long,long long>> st;
    //int psuedoIndex = 7;
    
    for(int i = n-1; i>=0; i--){
        if(st.empty()){
            ans.push_back(n);
        }
        else if(!st.empty() && st.top().first<arr[i]){
            ans.push_back(st.top().second);
        }
        else if(!st.empty() && st.top().first >= arr[i]){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(n);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

public:
//Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n){
    // Your code here
    long long maxi = -1;
    
    vector<long long> right;
    vector<long long> left;
    
    //Store the answers in 2 different vectors
    right = nearestSmallertoRight(arr,n);
    left = nearestSmallertoLeft(arr,n);
    
    //create widthArr and maxArr
    vector<long long> widthArr(n);
    vector<long long> maxArr(n);
    
    for(int i = 0; i<n; i++){
        
        //store right[i]-left[i]-1 in widthArr
        widthArr[i] = right[i]-left[i]-1;
        maxArr[i] = widthArr[i]*arr[i];
        //multiply widthArr[i]*arr[i]
    }
    
    // vector<long long> maxArr(n);
    
    // for(int i = 0; i<widthArr.size();i++){
    //     maxArr[i] = widthArr[i]*arr[i];
    // }
    
    for(int i = 0; i<maxArr.size(); i++){
        if(maxArr[i]>maxi){
            maxi = maxArr[i];
        }
        //Calculate max ele from the maxArr
    }
    
    return maxi;
        
}