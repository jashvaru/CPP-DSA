#include <iostream>
//#include <bits/stdc++.h> //it contains all the standard library
#include <stack>

using namespace std;

int main()
{
	stack <int> s;
	s.push(10);// pushes element on the top of the stack
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 

    while(!s.empty())//returns true is stack is empty
    {
    	cout << "size of stack = " << s.size() << " ";//return size of stack
    	cout << "Top element = " << s.top() << endl; // returns only top element of stack
    	s.pop();// delete top element od stack
    }
    cout << "size of stack = " << s.size() << " ";//return size of stack

    return 0;
}

int ShowStack
