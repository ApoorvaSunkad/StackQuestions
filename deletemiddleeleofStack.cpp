/*
Given a stack, delete the middle element of the stack without using any additional data structure.
Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.
 
Example 1:

Input: 
Stack = {10, 20, 30, 40, 50}
Output:
ModifiedStack = {10, 20, 40, 50}
Explanation:
If you print the stack the bottom-most element will be 10 and the top-most 
element will be 50. Middle element will be element at index 3 from bottom, 
which is 30. Deleting 30, stack will look like {10 20 40 50}.
Example 2:

Input: 
Stack = {10 20 30 40}
Output:
ModifiedStack = {10 30 40}

Explanation:

If you print the stack the bottom-most element will be 10 and the top-most 
element will be 40. Middle element will be element at index 2 from bottom, 
which is 20. Deleting 20, stack will look like {10 30 40}.

Your Task:
You don't need to read input or print anything. Complete the function 
deleteMid() which takes the stack and its size as input parameters and 
modifies the stack in-place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

//using extra stack

void deleteMid(stack<int>&s, int sizeOfStack){
        // code here.. 
        
        int middle = (sizeOfStack) / 2;

        // Create a temporary stack to store elements
        stack<int> tempStack;

        // Copy elements to tempStack until reaching middle
        for (int i = 1; i <= middle; ++i) {
          tempStack.push(s.top());
          s.pop();
        }

        // Skip the middle element
        s.pop();

        // Copy back the remaining elements
        while (!tempStack.empty()) {
          s.push(tempStack.top());
          tempStack.pop();
        }
}


//Using recursion

void findMid(stack<int>&s, int cnt, int size){
    //base case
    if(cnt == size/2){
        s.pop();
        return;
    }
    if(s.empty()){
        return;
    }
    
    int num = s.top();
    
    s.pop();
    
    findMid(s,cnt+1,size);
    s.push(num);
}
public:
//Function to delete middle element of a stack.
void deleteMid(stack<int>&s, int sizeOfStack)
{
    // code here.. 
    
    int cnt = 0;
    findMid(s,cnt,sizeOfStack);
}