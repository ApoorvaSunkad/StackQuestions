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

//T.C = O(N)
//S.C = O(N) N = Length of the input string

int precd(char c){
    if(c == '^')return 3;
    if(c == '/' or c == '*')return 2;
    if(c == '-' or c == '+')return 1;
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s) {

    // Your code here
    int n = s.length();
    string ans = "";
    stack<char> st;

    for(int i = 0;i < n;i++){
        if((s[i] >= 'a' and s[i] <= 'z') and s[i] >= 'A' and s[i] <= 'Z'){
            ans += s[i];
        }
        else{
            while(!st.empty() and s[i] != '(' and s[i] != ')' and precd(st.top()) >= precd(s[i])){
                if(st.top() != '(')ans += st.top();
                else break;
                st.pop();
            }
            if(s[i] == ')'){
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}