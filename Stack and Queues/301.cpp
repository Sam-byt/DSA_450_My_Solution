// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        char temp;
        
        
        for(auto i : x)
        {
            if(s.empty())
            {
                if(i == '(' || i == '{' || i == '[')s.push(i);
                else return false;
            }
            else{
                temp = s.top();
                if(i == ')'){
                    if(temp == '(')s.pop();
                    else return false;
                }
                else if(i == '}'){
                    if(temp == '{')s.pop();
                    else return false;
                }
                else if(i == ']'){
                    if(temp == '[')s.pop();
                    else return false;
                }
                else s.push(i);
            }
        }
        
        return s.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
