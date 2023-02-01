/*
THE DATA VALUES OF NODES ARE GIVEN AS INPUTS WE MUST WRITE A FUNCTION TO ADD CREATE NODE WITH THE GIVEN DATA AND FORM LINKEDLIST

*/


#include <bits/stdc++.h>
using namespace std;


class Node
{
    public :
    int data;
    Node*next;


    Node()
    {
        this->data=data;
        this->next=NULL;


    }
};

   

                                                        void PrintElements(Node* head)
                                                        {
                                                            Node* temp=head;

                                                        while(temp!=NULL)
                                                        {
                                                        cout<<temp->data<< "->";
                                                        temp=temp->next;
                                                        }

                                                        }
  
  
  
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



int main()
{

    int no_ofnodes;
    cin>>no_ofnodes;
    
    Node*head=CreateSinglyLinkedList(no_ofnodes);
    
     PrintElements(head);
    
    return 0;
}