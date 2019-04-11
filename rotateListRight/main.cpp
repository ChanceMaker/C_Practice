#include <iostream>
#include <vector>
/**
 * ListNode created to build a list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * The createList function is used to help create the list.
 * @param x
 * This parameter is a vector that is then used and converted into a ListNode
 * @return
 * The return value of this function is a listNode
 */
ListNode* createList(std::vector<int> & nums){
    ListNode* fullList = NULL;
    for(auto ritr = nums.rbegin(); ritr != nums.rend();ritr++)
    {
        ListNode* tmp = new ListNode(*ritr);
        tmp->next = fullList;
        fullList = tmp;
    }
    return fullList;
}
/**
 * Function used to print a vector of integers
 * @param x
 * A vector of integers that wil be printed
 */
void printVector(std::vector<int> &x){
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}
std::vector<int> createVect(std::string x){
    std::vector<int>  ans;
    for (int i = 0; i < x.size(); i++) {
        ans.push_back(x.at(i) - '0');

    }
    return ans;
}
/**
 * @brief printList is used to to print the Listnode list in order
 * from beginning to end.
 * @param head
 * The input of the pintList is a LinkedList that is then walked through and printed.
 */
void printList(ListNode* head){
    ListNode * current;
    current = head;
    while(current != NULL){
        std::cout << current->val <<" ";
        current = current->next;
    }
}
/**
 * Function returns the size of the list by walking through the
 * list and adding it.
 * @param head
 * The head of the linked list.
 * @return
 * Integer size of the linked list.
 */
int listSize(ListNode* head){
    ListNode * current;
    current = head;
    int x = 0;
    while(current != NULL){
        current = current->next;
        x++;
    }
    return x;
}
/**
 * Solution class for the rotateRight function.
 */
class Solution {
public:
    /**
     * Rotate the list to the right k number of times.
     * @param head
     * This is the head of the initial list
     * @param k
     * This is the number of times that you must rotate the list
     * @return
     * We will return a new list That is rotated the correct amount of times.
     */
    ListNode* rotateRight(ListNode* head, int k) ;
    ListNode* rotateHelp(ListNode* head);

};
/**
 * This particular function actually uses a rotate left to perform the equivalent of what the rotate right
 * number of time would be resulting in the same linkedlist. This is done because it is simply easier
 * to perform a rotate left
 * @param head
 * Head of the LinkedList used as a reference pointer to where our linked list starts
 * @param k
 * this parameter is simply the number of right rotations of the list that will be done.
 * @return
 * It returns a new Linked List that represents the resultant k right shifted list.
 */
ListNode* Solution::rotateRight(ListNode *head, int k) {
    if(!head)
        return NULL;
    ListNode * newHead;
    newHead = head;
    int size = listSize(newHead);
    int limit = 0;
    k %= size;
    if(k == 0) return head;
    for(int i = 0; i < size - k; i++){
        newHead = rotateHelp(newHead);
    }

    return newHead;
}
/**
 * This function is a helper function to the rotateRight function it actually just performs one shift left of the
 * Linked List.
 * @param head
 * A reference to the head of the list. That is used as a pointer to the front of the list
 * @param val
 * This val parameter is just
 * @return
 */
ListNode * Solution::rotateHelp(ListNode *head) {
    ListNode * newHead;
    ListNode * current;
    newHead = head;
    current = head;
    int val = head->val;
    while (current != NULL) {
        if(current->next != NULL)
            current->val = current ->next->val;
        else
            current->val = val;

        current = current->next;
    }
    return newHead;
}
int main() {
    Solution answer;
    ListNode * ListA;
    ListNode * ListB;
    std::vector<int> Vect1;
    Vect1 = createVect("12345");
    ListA = createList(Vect1);
    ListB = answer.rotateRight(ListA,2);
    printList(ListB);
    return 0;
}