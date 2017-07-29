/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //Create new head node
        ListNode real = ListNode(0);
        ListNode* realHead = &real;
        realHead -> next = head;
        ListNode* crawler = realHead;
        //while not at the last element
        while(crawler -> next != nullptr && crawler -> next -> next != nullptr){
            //crawler points to 2nd element, 2nd element points to 1st element, 1st element points to 3rd element.
            ListNode* temp = crawler -> next;
            ListNode* temp2 = crawler -> next -> next -> next;
            crawler -> next = crawler -> next -> next;
            crawler -> next -> next = temp;
            crawler -> next -> next -> next = temp2;
            crawler = crawler -> next -> next;
        }
        return realHead -> next;
    }
};
