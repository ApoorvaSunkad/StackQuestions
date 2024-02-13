/*
Given an integer array Arr of size N. For each element in the array, 
check whether the right adjacent element (on the next immediate position) 
of the array is smaller. If next element is smaller, update the current index 
to that element. If not, then  -1.

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
You don't need to read input or print anything. Your task is to complete 
the function immediateSmaller() which takes the array of integers arr and n 
as parameters. You need to change the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/


//Using arrays
//T.C = O(N)
//S.C = O(1)

void immediateSmaller(vector<int>&arr, int n) {
	    vector<int> v;
	    
	    for(int i = 0; i<n-1; i++){
	        if(arr[i+1]<arr[i]){
	            arr[i] = arr[i+1];
	        }else{
	            arr[i] = -1;
	        }
	    }
	    arr[n-1] = -1;
	    
	   // for(int i = 0; i<v.size(); i++){
	   //    arr[i] = v[i];
	   // }
}


//Using stacks

//T.C = O(N)
//S.C = O(N)

void immediateSmaller(vector<int>&arr, int n) {
	//  code here
    stack<int> st;
    
    st.push(arr[0]);
    
    for(int i = 1; i<n; i++){
        if(arr[i]<st.top()){
            arr[i-1] = arr[i];
            st.pop();
        }
        else{
            arr[i-1] = -1;
        }
        st.push(arr[i]);
    }
    arr[n-1] = -1;
}