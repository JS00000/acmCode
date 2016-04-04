#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string pt = "";
    string np = "1";
    for (int i = 0; i < n; i++)
    {
    	string t;
    	cin >> t;
    	if (t == "0")
    	{
    		cout << 0 << endl;
    		return 0;
    	}
    	int e = 0;
    	for (int i = t.size()-1; i >= 0; i--)
    	{
    		if (t[i] != '0') break;
    		else
    		{
    			e++;
    			pt += '0';
    		}
    	}
    	string c = t.substr(0,t.size()-e);
    	if (c != "1") np = c;
    }
    cout << np << pt << endl;
}