/*
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. 
Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated 
stack/deque.

Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at 
the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion 
becomes [9, 7, 1, 4, 5].

Follow Up :
Try to do this without using any other data structure.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <=100
1 <= N <= 10^4
0 <= 'X’ and 'MY_STACK[i]’ <= 10^5

Time limit: 1 second
Sample input 1 :
2
3 8
4 3 2
4 5
6 2 4 9
Sample Output 1 :
8 4 3 2
5 6 2 4 9


*/


//T.C = O(N)
//S.C = O(N)

#include <bits/stdc++.h> 
void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s,x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}



//Another modification or new approach to this problem if the return type is 
//stack

/*
You are given a stack st of n integers and an element x. You have to insert x 
at the bottom of the given stack. 

Note: Everywhere in this problem, the bottommost element of the stack is shown 
first while priniting the stack.

Example 1:

Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
Example 2:

Input:
n = 3
x = 4
st = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
Your Task:

You don't need to read input or print anything. Your task is to complete the 
function insertAtBottom() which takes a stack st and an integer x as inputs and 
returns the modified stack after insertion.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
0 <= x, elements of stack <= 109

*/


//Using extra stack
//T.C = O(N)
//S.C = O(N)
stack<int> insertAtBottom(stack<int> st,int x){
        
    stack<int>temp;
    int n=st.size();
    for(int i=0;i<n;i++){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    
    for(int i=0;i<n;i++){
        st.push(temp.top());
        temp.pop();
    }
    return st;
        
}


//Using recursion

 stack<int> insertAtBottom(stack<int> st,int x){
    
    //Base case
    if(st.empty()){
        st.push(x);
        return st;
    }
    
    int num = st.top();
    st.pop();
    
    st = insertAtBottom(st,x);
    st.push(num);
    
    return st;
        
}