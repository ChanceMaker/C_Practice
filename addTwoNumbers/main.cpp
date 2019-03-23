#include <iostream>
#include <string>


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
void printList(ListNode*);
class Solution {
private:
    ListNode *head,*tail;
public:
    Solution(){
        head = NULL;
        tail = NULL;
    }
    //function used to add the two reverse linked list numbers
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        int maxLen = 0;
        int size1 = 0;
        int size2 = 0;
        ListNode * L1_cpy = NULL;
        ListNode * L2_cpy = NULL;
        L1_cpy = L1;
        L2_cpy = L2;
        int flag ;
        ListNode* remainder = NULL;
        ListNode* answer = NULL;
        int LCompare = 0;//variable used to check list size
        int sizeDiff = 0;//if there is a difference in size of the two list pad the smaller list with zero's
        LCompare = findLargestList(L1,L2,size1,size2);
        if(LCompare == 0){//L1 is larger
            //pad L2 with zero's
            sizeDiff = size1 - size2;
            ListNode* tmp;
            tmp = L2;
            while (tmp != NULL){

                insert_back(tmp->val);
                tmp = tmp ->next;
            }
            //fill up the rest with zeros
            for (int i = 0; i <sizeDiff ; ++i) {
                insert_back(0);
            }
            L2_cpy = getList();
            L1_cpy = L1;


        }else if(LCompare == 1) {//L2 is larger
            //pad L1 with zero's
            sizeDiff = size2 - size1;
            ListNode* tmp;
            tmp = L1;
            while (tmp != NULL){

                insert_back(tmp->val);
                tmp = tmp ->next;
            }
            //fill up the rest with zeros
            for (int i = 0; i <sizeDiff ; ++i) {
                insert_back(0);
            }
            L1_cpy = getList();
            L2_cpy = L2;


        }
        //actually add the linked list now
        //this will require a "Remainder" linkedlist that is the size of both of these linked list
        ListNode * remainderList  = NULL;
        ListNode * remainHead = NULL;
        ListNode * remainTail = NULL;


        maxLen = getListLength(L1_cpy);//finding the remainder linked list size
        for (int i = 0; i <maxLen ; ++i) {//initializing zero remainder list
            ListNode* tmp = new ListNode(0);
            tmp ->val = 0;
            if(remainHead == NULL){
                remainHead = tmp;
                remainTail = tmp;

            }else{
                remainTail ->next = tmp;
                remainTail = tmp;
            }

        }
        remainderList = remainHead;
        ListNode * answerList  = NULL;
        ListNode * answerHead = NULL;
        ListNode * answerTail = NULL;
        for (int i = 0; i <maxLen ; ++i) {//initializing zero answer list
            ListNode* tmp = new ListNode(0);
            tmp ->val = 0;
            if(answerHead == NULL){
                answerHead = tmp;
                answerTail = tmp;

            }else{
                answerTail ->next = tmp;
                answerTail = tmp;
            }
            answerList = answerHead;

        }
        //Now do the actual adding
        int chkVal = 0;
        for (int i = 0; i < maxLen; ++i) {
            chkVal = L1_cpy->val + L2_cpy ->val + remainderList ->val;
            if(chkVal >= 10){
                if(i < maxLen - 1){//means we can carry the one up to the next remainder
                    remainderList->next->val = 1;
                    answerList->val = chkVal - 10;
                }else{//

                    answerList->val = chkVal - 10;
                    ListNode* tmp = new ListNode(1);
                    tmp -> next = NULL;
                    if(answerHead == NULL){
                        answerHead = tmp;
                        answerTail = tmp;

                    }
                    else{
                        answerTail ->next = tmp;
                        answerTail = tmp;
                    }
                }
            }else{
                answerList -> val = chkVal;//values are less than remainder treshold so they go directly in the answer list
            }
            L1_cpy = L1_cpy->next;
            L2_cpy = L2_cpy->next;
            remainderList = remainderList->next;
            answerList = answerList->next;

        }
        deleteList(&L1_cpy);
        deleteList(&L2_cpy);
        deleteList(&remainderList);

        return answerHead;
    }

    int findLargestList(ListNode* x1,ListNode *x2,int & size1,int & size2){

        ListNode * tmp;
        tmp = x1;
        while (tmp != NULL){
            size1++;
            tmp = tmp->next;

        }
        tmp = x2;
        while (tmp != NULL){
            size2++;
            tmp = tmp->next;
        }
        if(size1 > size2){
            return 0;
        }else if(size2 > size1){
            return 1;
        }else{
            return 2;
        }
    }
    int getListLength(ListNode * x){
        int size = 0;
        while(x != NULL){
            size++;
            x = x->next;
        }
        return size;
    }

    /* Function to delete the entire linked list */
    void deleteList(ListNode** head_ref)
    {
        /* deref head_ref to get the real head */
        ListNode* current = *head_ref;
        ListNode* next;

        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }

        /* deref head_ref to affect the real head back
           in the caller. */
        *head_ref = NULL;
    }


    void insert_back(int x){
        ListNode * tmp = new ListNode(x);

        tmp ->next = NULL;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail ->next = tmp;
            tail = tmp;
        }
    }

    ListNode * getList(){
        return head;
    }





};
int main() {

    int firstN[1] = {9};
    int secondN[10] = {1,9,9,9,9,9,9,9,9,9};
    ListNode * answerList;
    //list objects
    Solution firstNum;//first num list objects
    Solution secondNum;//second num list object

    for (int i = 0; i < sizeof(firstN)/sizeof(firstN[0]); ++i) {
        firstNum.insert_back(firstN[i]);
    }
    for (int i = 0; i < sizeof(secondN)/sizeof(secondN[0]); ++i) {
        secondNum.insert_back(secondN[i]);
    }
    Solution answerOBJ;
    answerList = answerOBJ.addTwoNumbers(firstNum.getList(),secondNum.getList());

    printList(answerList);
    return 0;
}
void printList(ListNode* x){
    while(x != NULL){
        std::cout << x->val << " ";
        x = x->next;
    }
    std::cout <<"\n";
}
