#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
//insert node at begining;
node* createn(node* h,int x)
{
    node* l=new node(x);
    l->next=h;
    return l;
}
//insert at end;
node* createnat_end(node* h,int x)
{
    node* l=new node(x);
    node* p=h;
    while(p->next!=NULL)
    p=p->next;
    p->next=l;
    return h;
}
//insert at pos....
node* createnat_pos(node* h,int x,int k)
{
    node* l=new node(x);
    node* p=h;
    int n=1;
    while(p->next!=NULL)
    {
    p=p->next;
    n++;
    if(n==k)
    {
        node* ll=p->next;
        p->next=l;
        l->next=ll;
        
    }
    }
    
    return h;
}
//delete first
node* delhead(node* h)
{
    if(h==NULL)return NULL;
    node* t=h->next;
    
    delete h;
    return t;
}
//delete endl
node* delend(node* h)
{
    if(h==NULL)return NULL;
    node* p=h;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    node* t=p->next;
    // cout<<t->data;
    p->next=NULL;
    delete t;
    return h;
}
//delete pos
node* delpos(node* h,int k)
{
    if(h==NULL)return NULL;
    node* p=h;
    int n=1;
    while(p->next->next!=NULL)
    {
        p=p->next;
        n++;
        if(n==k-1)
        {
             node* t=p->next;
             if(p->next->next!=NULL)
                p->next=p->next->next;
            else{
                delete t;
                p->next=NULL;
                return h;
            }
             delete t;
        }
    }
   
    // cout<<t->data;
    
    return h;
}

//display ll
void printn(node* h)
{
    node* p=h;
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    node* l=new node(5);
    l->next=new node(4);
    //different way to create.....
    l=createn(l,10);
    l=createn(l,8);
    l=createnat_end(l,7);
    l=createnat_pos(l,9,3);
    
    l=delhead(l);
     l is = delend(l);
  l=delpos(l,4);
    printn(l);
    return 0;
}
