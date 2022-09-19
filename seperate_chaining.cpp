#include<bits/stdc++.h>
#define size 10

using namespace std;
struct node
{
    int data;
    struct node *next;
};
node *chain[size];
void initilaz()
{
  
    for(int i = 0; i < size; i++)
        chain[i] = NULL;
}

void insertnode(int value)
{
    node *newNode=new node();
    newNode->data = value;
    newNode->next = NULL;

    int key = value % size;
     if(chain[key] == NULL)
        chain[key] = newNode;

    else
    {
        node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
bool search(int val){
    int i;
   int key=val%size;
   
        node *temp = chain[key];
     
       while(temp)
        {
            if(temp->data==val)return 1;
         
            temp = temp->next;
        }
     
    
    
    return 0;
}
void display()
{
    for(int i = 0; i < size; i++)
    {
        node *temp = chain[i];
        cout<<i<<" : ";
       while(temp)
        {
            cout<<temp->data<<"-->";
         
            temp = temp->next;
        }
      cout<<endl;
    }
}
int main()
{
    initilaz();
    insertnode(20);
    insertnode(10);
    insertnode(19);
    insertnode(45);
    cout<<search(23)<<endl;
    cout<<search(20)<<endl;
    
    display();

    return 0;
  
}
