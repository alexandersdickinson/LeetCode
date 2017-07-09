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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode last = ListNode(0);
        ListNode* lastNode = &last;
        lastNode -> next = head;
        ListNode* crawler = head;
        ListNode* removalNode = head;
        for(int i = 0; i < n - 1 && crawler -> next != nullptr; ++i){
            crawler = crawler -> next; 
        }
        while(crawler -> next != nullptr){
            crawler = crawler -> next;
            removalNode = removalNode -> next;
            lastNode = lastNode -> next;
        }
        if(removalNode == head){
            return removalNode -> next; 
        }
        else{
            lastNode -> next = removalNode -> next;
            return head;
        }
    }
};
