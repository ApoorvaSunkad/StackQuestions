/*
Given an infix expression in the form of string str. Convert this infix '
expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is 
in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator 
is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater 
than + equals to -. Ignore the right associativity of ^.

Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function 
infixToPostfix() that takes a string(Infix Expression) as a parameter 
and returns a string(postfix expression). The printing is done automatically 
by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 ≤ |str| ≤ 105


*/


//Please refer Algorithm for better understanding.

//T.C = O(N)+O(N)
//S.C = O(N)+O(N) N = Length of the input string

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s) {

    string ans = "";
        stack<char> st;
        
        int i = 0, n = s.length();
        
        while(i<n){
            char ch = s[i];
            if((ch >='A' && ch <='Z') || (ch >='a' && ch <='z') || (ch >='0' && ch <='9')){
                ans+=ch;
            }else if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && precedence(ch)<= precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                    
                }
                st.push(ch);
            }
            i++;
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
  
}