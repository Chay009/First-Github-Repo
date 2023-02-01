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

//CASE 1 : ADD NODE AT FIRST OF THE LINKED LIST

Node* AddNodeAtFirst(Node* head,int nodevalue)
{
Node* newnode=new Node();
newnode->data=nodevalue;

if(head==NULL)
{
head=newnode;
}
else 
{
    newnode->next=head;
    head=newnode;
}



    return head;
}

// CASE 2 : ADD NODE AT LAST (TAIL) OF THE LINKED LIST
Node* AddNodeAtLast(Node*head,int nodevalue)
{


    Node* newnode=new Node();
     newnode->data=nodevalue;
    if(head==NULL)
    {
     
     head=newnode;   
    }

    else
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newnode;
    }   



    return head;
} 



/* CASE 3 : TO ADD AT GIVEN INDEX

we cant add node at index 0 since its head therefore for that case use specific function

## IN NOTE OUR CASE WE ARE USING INDEXING SAME AS ARRAY I.E STARTS FROM 0


INDEX   0   1   2   3   4
 EXAMPLE 1->2->100->21->    add at index 2 and VALUE is 15 
        1->2->15->100->21->
                                        */
Node*AddNodeAtGivenIndex(Node*head,int index,int nodevalue)
{

Node* newnode=new Node();
newnode->data=nodevalue;
 Node*temp=head;;

if(head==NULL)
{
    head=newnode;
   
}
else
{    // to add that index we must stop at one index before it.

    for(int i=0;i<index-1;i++)
    {
        temp=temp->next;
         
    }

    newnode->next=temp->next;
    temp->next=newnode;

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
    

int nodevalue;
cin>>nodevalue;


// ##NOTE THE ABOVE FUNCTION OONE AT TIME SINCE THE VALUES MAY OVERWRITTEN


//TO ADD AT FIRST
/*Node* NewHeadNode=AddNodeAtFirst(head,nodevalue);

PrintElements(NewHeadNode); cout<<"after insertion of node at head\n";



// TO ADD AT LAST
Node*Headafterinsertionattail=AddNodeAtLast(head,nodevalue);
PrintElements(Headafterinsertionattail); 
cout<<"after insertion of node at last\n";*/


// TO ADD AT GIVEN INDEX
int index;
cin>>index;
Node*HeadAfterInsertionAtGivenIndex=AddNodeAtGivenIndex(head,index, nodevalue);
PrintElements(HeadAfterInsertionAtGivenIndex);





    
    return 0;
}