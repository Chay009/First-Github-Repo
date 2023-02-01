#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
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

Node* ReverseLinkedList(Node*head)
{
     Node*previous=NULL;
    while(head!=NULL)
    {
        Node*next=head->next;
        head->next=previous;
        previous=head;
        head=next;
    }
    //INSTEAD OF THREE POINTERS FROM ONLINE CODE I HAVE USED HEAD AS EXTRA POINTER BUT AFTER THIS HEAD CHANGES TO NULL 
    // LAST TIME THE LOOP RUNS NEXT ASSIGNS TO NULL SO DUE TO LAST LINE HEAD ALSO TO NULL AND PREVIOUS
    //    - POINTS TO NEW HEAD SOME AMKING IT HEAD 
    head=previous;



    return head;
}








int main()
{

    int no_ofnodes;
    cin>>no_ofnodes;
    Node*head=CreateSinglyLinkedList(no_ofnodes);;
     PrintElements(head);
     
     Node*newhead= ReverseLinkedList(head);
     cout<<"\n";
     PrintElements(newhead);
    
    return 0;
}