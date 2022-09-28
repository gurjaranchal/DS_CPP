// Recursion By Aditiya Verma
#include <bits/stdc++.h>
using namespace std;
struct node{
    int d;
    node* left;
    node* right;
    node(int x)
    {
        d=x;
        left=NULL;
        right=NULL;
    }
};
void print_1_to_n(int n)
{
    if(n==0)return;
    //Head Recursion
    print_1_to_n(n-1);
    cout<<n<<" ";
}
void print_n_to_1(int n)
{
    if(n==0)return;
    cout<<n<<" ";
    //Tail Recursion
    print_n_to_1(n-1);
}
int height_of_BT(node* r)
{
    if(r==NULL)return 0;
    int lh=height_of_BT(r->left);
    int rh=height_of_BT(r->right);
    return 1+max(lh,rh);
    
}
void insert_ele(vector<int>& a,int temp)
{
    if(a.size()==0 or a[a.size()-1]<=temp)
    {
        a.push_back(temp);
        return;
    }
    int temp2=a[a.size()-1];
    a.pop_back();
    insert_ele(a,temp);
    a.push_back(temp2);
    
}

void sort_an_arry(vector<int>& a)
{
    if(a.size()==1)return;
    int temp=a[a.size()-1];
    a.pop_back();
    sort_an_arry(a);
    insert_ele(a,temp);
}

void insert_ele_in_stk(stack<int>& a,int temp)
{
    if(a.size()==0 or a.top()<=temp)// a.top()>=temp in ascending order
    {
        a.push(temp);
        return;
    }
    int temp2=a.top();
    a.pop();
    insert_ele_in_stk(a,temp);
    a.push(temp2);
    
}

void sort_an_stk(stack<int>& a)
{
    if(a.size()==1)return;
    int temp=a.top();
    a.pop();
    sort_an_stk(a);
    insert_ele_in_stk(a,temp);
}
//Josephus Problem..,game of death in order....
void solve_prob(vector<int>& v,int k,int index)
{
    if(v.size()==1)
    {
         cout<<v[0];
        return;
    }
     index=(index+k)%v.size();
     v.erase(v.begin()+index);
     solve_prob(v,k,index);
}
int main()
{
    // print 1 to n
    print_n_to_1(5);
    cout<<endl;
    
    // print n to 1
    print_1_to_n(5);
     cout<<endl;
     
     //find height of tree
    node* r=new node(2);
    r->left=new node(3);
    r->right=new node(4);
    r->left->left=new node(5);
    r->left->left->right=new node(6);
    cout<<height_of_BT(r);
    cout<<endl;
    
    //sort an array
    vector<int> v{2,4,1,7,8,0,6};
    sort_an_arry(v);
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;
    
    //sort a stack
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(8);
    st.push(0);
    st.push(6);
    sort_an_stk(st);
    while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }
    cout<<endl;
    
    //Josephus Problem....
    vector<int> vv;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    vv.push_back(i);
    int ans=0,index=0;
    solve_prob(vv,k-1,index);
    cout<<endl;
    
    

    return 0;
}
