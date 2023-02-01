




// THE CODE IS STILL NOT COMPLETED
#include<bits/stdc++.h>
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
// CASE 1 DELETING HEAD
Node* DeleteHeadNode(Node*head)
{
     Node*temp=head;

    if(head==NULL)
    {
        cout<<"NO NODE TO DELETE";

    }
    else
    {
        
       //  saving the node which has to  be deleted
        Node* x=head;
        head=temp->next;
                //delete the node that has to be deleted 
                   
    }



        return head;
}

// DELETING LASTNODE
Node* DeleteLastNode(Node*head)
{
     if(head==NULL)
     {
        head=NULL;
        cout<<"no node to show";


     }

     else
     {
        Node*temp=head;
        while(temp->next!=NULL)
        {
           temp=temp->next;
        }
          ;

     }

    return head;
}

int main()
{

    int no_ofnodes;
    cin>>no_ofnodes;


    Node*head=CreateSinglyLinkedList(no_ofnodes);
   
     PrintElements(head);
     cout<<"\n";
     
     
     
     
     //CASE 1
     Node*HeadAfterDeleteHeadNode=DeleteHeadNode(head);

    PrintElements(HeadAfterDeleteHeadNode);
    cout<<"\n";

    // CASE 2
    Node* HeadAfterDeleteLastNode=DeleteHeadNode(head);
    PrintElements(HeadAfterDeleteLastNode);



    return 0;
}