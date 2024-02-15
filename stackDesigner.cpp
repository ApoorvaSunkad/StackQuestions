/*
You are given an array arr of size N. You need to push the elements of the 
array into a stack and then print them while popping.

Example 1:

Input:
n = 5
arr = {1 2 3 4 5}
Output:
5 4 3 2 1
Example 2: 

Input: 
n = 7
arr = {1 6 43 1 2 0 5}
Output: 
5 0 2 1 43 6 1
 

Your Task:
Since this is a function problem, you don't need to take any input. 
Just complete the provided functions _push() and _pop().

Constraints:
1 <= Ai <= 107




*/

//T.C = O(N)
//S.C = O(N)

stack<int>_push(int arr[],int n)
{
   //return a stack with all elements of arr inserted in it
   stack<int> s;
   for(int i = 0; i<n; i++){
       s.push(arr[i]);
   }
   return s;
}

/* _pop function to print elements of the stack
   remove as well
*/
void _pop(stack<int> s)
{
    //print top and pop for each element until it becomes empty
    int n = s.size();
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}