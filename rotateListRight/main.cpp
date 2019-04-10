#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {

    }
};
int main() {
    Solution answer;

    answer.rotateRight()
    return 0;
}