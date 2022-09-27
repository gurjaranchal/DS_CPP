#include <bits/stdc++.h>
using namespace std;
//time complexity (n*2^n)
void gensub(string s)
{
    int i,j,k,n=s.size();
    int m=pow(2,n);
    for(i=0;i<m;i++)
    {
        int nn=i;
        string a="";
        while(nn)
        {
            if(nn%2==1)
            a=a+"1";
            else 
            a=a+"0";
           nn=nn/2; 
        }
        int mm=0;
        while(mm<n)
        {
            if(a[mm]=='1')
            cout<<s[mm];
            
            mm++;
        }
        cout<<endl;
    }
}
int main()
{
    string s="abcd";
    gensub(s);
    return 0;
}
