/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
Your Task:

You don't need to read input or print anything. Your task is to complete the 
function Reverse() which takes the stack St as input and reverses the given stack.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of the stack <= 104
-109 <= Each element of the stack <= 109
Sum of N over all test cases doesn't exceeds 106
Array may contain duplicate elements. 


*/

//Extreme brute force: Easy peasy
//very interesting problem

//T.C = O(N)
//S.C = O(1)
void Reverse(stack<int> &St){
    while (!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }
}

//Using an extra stack
//T.C = O(N)
//S.C = O(N)

void Reverse(stack<int> &St){
    stack<int> temp;
    while(!St.empty()){
        int curr = St.top();
        St.pop();
        temp.push(curr);
    }
    St = temp;
}

//using Recursion

//T.C = O(N^2)
//S.C = O(1)

void insertAtBottom(stack<int> &S, int ele){
    
    //Base case
    if(S.empty()){
        S.push(ele);
        return;
    }
    
    int num = S.top();
    S.pop();
    
    //Recursive call
    insertAtBottom(S,ele);
    
    S.push(num);
}
public:
void Reverse(stack<int> &St){
    
    //Base case
    if(St.empty()){
        return;
    }
    
    int num = St.top();
    St.pop();
    
    //Recursive call
    Reverse(St);
    
    insertAtBottom(St,num);

}