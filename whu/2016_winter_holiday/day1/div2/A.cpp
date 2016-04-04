#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	int i = 0;
	string str;
	char c;
	stack<char> mystack;
	// cin >> str;
	// while(i<str.length())
	// {
	// 	c = str[i]; 
	// 	if (c=='<'||c=='['||c=='{'||c=='(') mystack.push(c);
	// 	else if (c=='>')
	// 	{
	// 		if (mystack.top()=='<')
	// 		{
	// 			mystack.pop();
	// 		}
	// 		// else if (mystack.top()==)
	// 		{
	// 			/* code */
	// 		}
	// 	}
	// 	i++;
	// }
	mystack.push('c');
	cout << mystack.top() << '\n';
	mystack.pop();
	// mystack.push('d');
	cout << mystack.top() << '\n';
	return 0;
}
