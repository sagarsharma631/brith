/*
  AUTHOR - SAGAR SHARMA
  
  Question - Check if paranthesis can be balanced if '*' can be replaced by '(' or ')' or ''

*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isBalanced(const string& str, string temp, int index) {

	auto checkBalance = [](const string& str) -> bool {
		stack<char> st;
		int index = 0;
		while (index != str.length()) {
			if (str[index] == ')') {
				if (!st.empty()) {
					if (st.top() == '(')
						st.pop();
					else
						return false;
				}
				else {
					return false;
				}
			}
			else {
				st.push('(');
			}
			++index;
		}
		return (!st.empty()) ? false : true;
	};

	for (int i = index; i < str.length(); ++i) {
		if (str[i] == '*') {
			return isBalanced(str, temp, i + 1) || isBalanced(str, temp + '(', i + 1) || isBalanced(str, temp + ')', i + 1);
		}
		else {
			temp += str[i];
		}
	}
	
	return checkBalance(temp);
}
