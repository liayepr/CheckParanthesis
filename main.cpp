#include <iostream>
#include <string>
#include <stack> 

using namespace std;

bool CheckParanthesis(string expr)
{
	stack<char> s;
	char temp;

	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
		    s.push(expr[i]);  	// Push the element in the stack 
			continue;
		}

		if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
		{

			if (s.empty())
				return false;

			temp = s.top();
			s.pop();
			if ((temp == '(' && expr[i] == ')') || (temp == '{' && expr[i] == '}') || (temp == '[' && expr[i] == ']'))
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	};

	
	return (s.empty());
}

int main()
{
	string expr1 = "()";
	string expr2 = "()[]{}";
	string expr3 = "(]";

	if (CheckParanthesis(expr1))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	
	if (CheckParanthesis(expr2))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;

	if (CheckParanthesis(expr3))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	
	system("pause");
}