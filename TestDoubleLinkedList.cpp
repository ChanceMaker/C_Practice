#include <iostream>
using namespace std;
struct Node { 
   int data; 
   struct Node *prev; 
   struct Node *next; 
}; 
void addNodeAtPos(int, int);
void head_insert(int);
void tail_insert(int);

struct Node* head = NULL;
struct Node* tail = NULL; 

void head_insert(int newdata) { 
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data  = newdata; 
   newnode->prev = NULL;
   newnode->next = head;     
   if(head !=  NULL) //not an empty list
      head->prev = newnode ;

   head = newnode; 
}
void tail_insert(int newdata){
   //Make new node and place the data in it.
   struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
   newnode->data = newdata;

   newnode->next = NULL;
   if(head == NULL){
      head = newnode;
   }else{
      struct Node* tmp = head;
      while(tmp->next != NULL){
         tmp = tmp->next;
      }
      tmp->next = newnode;
   }

}   
void display() { 
   struct Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
  } 
} 
int main() { 
   head_insert(3);
   head_insert(1);
   head_insert(7);
   head_insert(2);
   head_insert(9);
   addNodeAtPos(4,5);
   cout<<"The doubly linked list is: ";
   display(); 
   return 0; 
} 
void addNodeAtPos(int data, int pos)
{
  struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
  struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;


  int tempPos = 0;   // Traverses through the list cursor

  curr = head;      // Initialize current to head;
  if(head != NULL)
  {
    while(curr->next != NULL && tempPos != pos)
    {
      cout << "INCHECK 1\n";
        prev = curr;
        curr = curr->next;
        tempPos++;
    }
    if(pos==0)
    {
       cout << "Adding at Head! " << endl;
       head_insert(data);
    }
    else if(curr->next == NULL && pos == tempPos+1)
    {
     
      cout << "Adding at Tail! " << endl;
      tail_insert(data);
    }
    else if(pos > tempPos+1)
      cout << " Position is out of bounds " << endl;
     //Position not valid

    else
    {
        prev->next = newNode;
        newNode->next = curr;
        cout << "Node added at position: " << pos << endl;
    }
 }
 else
 {
    head = newNode;
    newNode->next=NULL;
    cout << "Added at head as list is empty! " << endl;
 }
}