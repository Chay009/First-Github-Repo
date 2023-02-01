
/*
NOTE only while printing the elemnts we us temp!=NULL ,in most of the cases we use temp->next!=NULL*/



/*
CREATE A FUNCTION WHICH TAKES A POINTER OF A HEAD NODE AS A ARGUMENT 
BY TRAVERSING 
1. CAN PRINT ALL ELEMENTS 
2.SEARCHING OPERATION CAN ALSO BE PERFORMED



*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
};


Node* CreateSinglyLinkedList(int no_ofnodes)
{

Node* head=NULL;
Node* temp=NULL;


for(int i=0;i<no_ofnodes;i++)
{
    Node* newnode=new Node();
   

    int nodedata;
    cin>>nodedata;
    newnode->data=nodedata;
    if(head==NULL)
    {
        head=newnode;
        temp=head;

    } 
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newnode;

    }

   
}


return head;

}

   /*  FUNTION TO PRINT ELEMENTS OF A GIVEN NODE */


                                                                void PrintElements(Node* head)
                                                                {
                                                                    Node* temp=head;

                                                                while(temp!=NULL)
                                                                {
                                                                cout<<temp->data;
                                                                temp=temp->next;
                                                                }

                                                                }



// CHECK WHETHER THIS FUNCTION IS WORKING OR NOT

void SearchElement(Node* head,int value)
{


Node* temp=head;

while(temp->next!=NULL)
{ 
    if(temp->data==value)
    {
         break;
    }
    else 
    {
                temp=temp->next; 
    }
}


if(temp->data==value)
cout<<"Element Found";
else cout<<"Element not Found";

}


int main()
{

    int no_ofnodes;
    cin>>no_ofnodes;
   
    
    Node*head=CreateSinglyLinkedList(no_ofnodes);
     int element;
   // cout<<"enter elemnet value\n";
    cin>>element;
     SearchElement(head,element);
    
    return 0;
}