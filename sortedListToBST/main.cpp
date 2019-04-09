#include <iostream>
#include <vector>
#include <assert.h>

/**
 * ListNode created to build a list
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Treenode Trunk created to build tree.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
 * Gets the value of at the node given a position.
 * @param head
 * The head of a Linked List
 * @param pos
 * The position in the linked list that you seek.
 * @return
 * The value of the node at the position.
 */
int getNode(ListNode* head, int pos){
    int count = 0;
    ListNode* current;
    current = head;
    while (current != NULL) {
        if (count == pos) {
            return current->val;
        }
        count++;
        current = current->next;
    }

    assert(0);
}
/**
 * Solution class that is used
 */
class Solution {
    
public:
    /**
     * This function is used to take a sorted Linked List and
     * and place it into a binary search tree.
     * @param head
     * The input is a sorted Linked List.
     * @return
     * A binary search tree for the sorted List.
     */
    TreeNode* sortedListToBST(ListNode* head) {
              
        return BTreeCreate(head,0,listSize(head) - 1 );
    }
    /**
     * The recursive function is used as a "Helper" function to sortedListToBST.
     * @param head
     * This is the head of the sorted linked list.
     * @param begin
     * The begining of the sorted linked list.
     * @param end
     * The end of the sorted linked list.
     * @return
     * This helper function actually returns the binary search
     * tree for the sorted list.
     */
    TreeNode* BTreeCreate(ListNode* head,int begin,int end){
        
        if(begin == end){
            TreeNode * treeTrunk =  new TreeNode(getNode(head,begin));
            return treeTrunk;
        }
        if(begin > end){
            return NULL;
        }
        int midPnt = (begin + end)/ 2;                                         
        TreeNode * root = new TreeNode(getNode(head,midPnt));
        root->left = BTreeCreate(head,begin,midPnt - 1);
        root->right = BTreeCreate(head,midPnt + 1 ,end);
        
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution answer;
    TreeNode* trunk;
    std::vector<int> Vect{-10,-3,0,5,9};
    printVector(Vect);
    ListNode* sortedList;
    int testVal = 0;
    sortedList = createList(Vect);
    testVal = getNode(sortedList,1);
    std::cout <<"position value : "<<testVal<<"\n";
    trunk = answer.sortedListToBST(sortedList);
    //printList(sortedList);
    return 0;
}