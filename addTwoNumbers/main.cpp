#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode{
     int val;
     ListNode *next;

     ListNode(int x) : val(x),next(NULL){}//constructor
 };
 class list{//list class to handle the linked list shit
 private:
     ListNode *head,*tail;
 public:
     list(){
         head = NULL;
         tail = NULL;
     }
     void createNode(int x){
         ListNode* tmp = new ListNode(x);
         tmp -> next = NULL;
         if(head =NULL){
             head = tmp;
             tail = tmp;
             tmp = NULL;
         }
         else{
             tail ->next = tmp;
             tail = tmp;
         }
     }
     void printList(){
         ListNode * tmp ;
         tmp = head;
         while(tmp != NULL){
             std::cout << tmp->val << " ";
             tmp = tmp->next;
         }
         std::cout << "\n";
     }
     void insert_start(int x){
         ListNode * tmp = new ListNode(x);

         tmp ->next = head;
         head = tmp;
     }
     void insert_back(int x){
         ListNode * tmp = new ListNode(x);

         tmp ->next = NULL;
         if(head == NULL){
             head = tmp;
             tail = tmp;
             tmp = NULL;
         }else{
             tail ->next = tmp;
             tail = tmp;
         }
     }
     ListNode * getList(){
         return head;
     }
 };

class Solution {

public:
    //function used to add the two reverse linked list numbers
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        printList(L1);
        printList(L2);
    }
    void printList(ListNode* x){
        while(x != NULL){
            std::cout << x->val << " ";
            x = x->next;
        }
        std::cout <<"\n";
    }





};
int main() {

    int firstN[3] = {2,4,3};
    int secondN[3] = {5,6,4};
    ListNode * answerList;
    //list objects
    list firstNum;//first num list objects
    list secondNum;//second num list object

    for (int i = 0; i < sizeof(firstN)/sizeof(firstN[0]); ++i) {
        firstNum.insert_back(firstN[i]);
    }
    for (int i = 0; i < sizeof(secondN)/sizeof(secondN[0]); ++i) {
        secondNum.insert_back(secondN[i]);
    }
    Solution answerOBJ;
    //firstNum.printList();
    //secondNum.printList();
    answerList = answerOBJ.addTwoNumbers(firstNum.getList(),secondNum.getList());

    return 0;
}