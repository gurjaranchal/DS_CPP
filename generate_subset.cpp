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
// for array
void gensub_int(int s[],int n)
{
    int i,j,k;
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
//by recursion (ip-op method)
void gensub_rec(string ip,string op)
{
    if(ip.size()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op,op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    gensub_rec(ip,op1);
    gensub_rec(ip,op2);
}
int main()
{
    string s="abcd";
    int arr[]={1,2,3,4};
    gensub_int(arr,4);
    gensub(s);
    string ip="abc",op="";
    gensub_rec(ip,op);
    return 0;
}
