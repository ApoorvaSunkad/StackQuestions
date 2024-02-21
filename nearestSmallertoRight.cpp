/*
Given an integer array Arr of size N. For each element in the array, 
check whether the right adjacent element (on the next immediate position) 
of the array is smaller. If next element is smaller, update the current 
index to that element. If not, then  -1.

Example 1:

Input:
N = 5
Arr[] = {4, 2, 1, 5, 3}
Output:
2 1 -1 3 -1
Explanation: Array elements are 4, 2, 1, 5
3. Next to 4 is 2 which is smaller, so we
print 2. Next of 2 is 1 which is smaller,
so we print 1. Next of 1 is 5 which is
greater, so we print -1. Next of 5 is 3
which is smaller, so we print 3.  Note
that for last element, output is always 
going to be -1 because there is no element
on right.
Example 2:

Input:
N = 6
Arr[] = {5, 6, 2, 3, 1, 7}
Output:
-1 2 -1 1 -1 -1
Explanation: Next to 5 is 6 which is
greater, so we print -1.Next of 6 is 2
which is smaller, so we print 2. Next
of 2 is 3 which is greater, so we
print -1. Next of 3 is 1 which is
smaller, so we print 1. Next of 1 is
7 which is greater, so we print -1.
Note that for last element, output is
always going to be -1 because there is
no element on right.
Your Task:  
You don't need to read input or print anything. Your task is to complete the 
function immediateSmaller() which takes the array of integers arr and n as 
parameters. You need to change the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^7
1 ≤ Arr[i] ≤ 10^5

*/

//Brute force: Two nested loops
//T.C = O(N^2)
//S.C = O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> nearestsmaller(int arr[], int n){
    
    vector<int> v;
   
    for(int i = 0; i<n; i++){
        int nextSmall = -1;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[i]){
                nextSmall = arr[j];
                break;
            }
        }
        v.push_back(nextSmall);
    }
    return v;
}
int main()
{
    int arr[] = {5,6,2,3,1,7};
    int n = 6;
    vector<int>ans;
    ans = nearestsmaller(arr,n);
    
    for(int i = 0; i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}


//Optimised solution with Stacks
//Whenever we have 2 nested loops and J loop is dependent on I that means
//we can use stacks here


//T.C = O(2N)
//S.C = O(N) //worst case
#include <bits/stdc++.h>
using namespace std;

vector<int> nearestsmaller(int arr[], int n){
    
    vector<int> v;
    
    stack<int> s;
    
    for(int i = n-1; i>=0; i--){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && s.top()<arr[i]){
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top()>=arr[i]){
            while(!s.empty() && s.top()>=arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    int arr[] = {4,5,2,10,8};
    int n = 5;
    vector<int>ans;
    ans = nearestsmaller(arr,n);
    
    for(int i = 0; i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}