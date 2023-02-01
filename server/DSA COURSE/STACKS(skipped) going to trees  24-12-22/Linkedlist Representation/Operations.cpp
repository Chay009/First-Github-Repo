
// DESCRIPTION OF FUNCTIONS 

//1. IsEmpty - funtion tells whether stack is empty or not returns true  if empty else false.
//2. IsFull  - generally linkedlists have no size limit
//             buts fails when heap memory is full and if  newnode can't be created then heap memory is full
//3. pop   - deletes the top element and also prints its value
//4. push -  add new element to stack



#include <bits/stdc++.h>
using namespace std;



class SinglylinkedListNode{
    public :
    int data;
    SinglylinkedListNode* next;


    SinglylinkedListNode()
    {
        this->data=data;
        this->next=NULL;

    }
};









   /*  FUNTION TO PRINT ELEMENTS OF A GIVEN NODE */


                                                                void PrintElements(SinglylinkedListNode* top)
                                                                {
                                                                    SinglylinkedListNode* temp=top;

                                                                while(temp!=NULL)
                                                                {
                                                                cout<<temp->data<<"->";
                                                                temp=temp->next;
                                                                }
                                                                cout<<"\n";

                                                                }


                                                                



bool IsEmpty(SinglylinkedListNode*head)
{
    SinglylinkedListNode* top=head;

    if(top==NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


bool IsFull(SinglylinkedListNode* head)
{

    // creating a new node 
   SinglylinkedListNode* newnode=new SinglylinkedListNode();


   // if that is created it has some adress if not node is not created implying that there is no space and 
   //  it is simply a NULL value

   if(newnode==NULL)
   {
    return true;
   }
   else
   {
    return false;
   }
    
    

}








   
   
  
    
    
   







int main()
{


    

    
   
    
    return 0;










    
}