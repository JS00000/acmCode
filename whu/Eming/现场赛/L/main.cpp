#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    string str,ip,id,device;
    set<string> ipSet,idCSet,idMSet;
    cin >> n;
    int j = 0;
    for (int i = 0; i<n; i++)
    {
        cin >> str ; 
        if  (str=="Logout")
        {
            cin >> ip;
            if (!ipSet.erase(ip))
            {
                cout << "Logout Fail\n";                    
            }
            else
            {
                ipSet.erase(ip);
                cout << "Logout Success\n"; 
            }
        }
        else if (str=="Login")
        {
            cin >> id >> ip >> device;
            if (ipSet.find(ip)==ipSet.end())
            {
               ipSet.insert(ip);
            }
            else
            {
                cout << "IP has been registered\n";
                continue;
            }
            if (device=="M")
            {
                if(idMSet.find(id)==idMSet.end())
                {
                     idMSet.insert(id);      
                }            
                else 
                {
                     cout << "Device Limit exceeded\n"; 
                     continue;
                }
            }
            else
            {
                if(idCSet.find(id)==idCSet.end())
                {
                     idCSet.insert(id);      
                }            
                else 
                {
                     cout << "Device Limit exceeded\n"; 
                     continue;
                }
            }
            cout << "Login Success\n"; 
        }
    }
    return 0;
}
