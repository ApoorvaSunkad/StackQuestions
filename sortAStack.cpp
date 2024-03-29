/*
You’re given a stack consisting of 'N' integers. Your task is to sort this stack 
in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not 
remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive 
or zero.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 100
1 <=  'N' <= 100
1 <= |'V'| <= 10^9

Where |V| denotes the absolute value of any stack element.

Time limit: 1 sec
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
Explanation of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 
and -7 being the smallest element is present at the last. 
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 
18>14, 14>-3 and -5 being the smallest element is present at the last. 


*/


//Brute force:This is not recommended

void SortedStack(stack<int>&s)
{
   //Your code here
   vector<int>v;
   while(!s.empty())
   {
       v.push_back(s.top());
       s.pop();
   }
   sort(v.begin(), v.end());
   for(int i=0;i<v.size();i++)
   {
       s.push(v[i]);
   }
}

//T.C = O(N^2)
//S.C = O(N)

void sortedInsert(stack<int>&s, int ele){
	if(s.empty() || (!s.empty() && s.top()<ele)){
		s.push(ele);
		return;
	}

	int n = s.top();
	s.pop();

	sortedInsert(s,ele);
	s.push(n);
}
void sortStack(stack<int> &stack)
{
	//Base case
   if(stack.empty()){
       return;
   }
   
   int num = stack.top();
   stack.pop();
   
   //Recursive call
   sortStack(stack);
   
   sortedInsert(stack,num);
}