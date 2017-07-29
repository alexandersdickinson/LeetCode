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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode one = ListNode(0);
        ListNode* traverse1 = &one;
        traverse1 -> next = l1;

        ListNode two = ListNode(0);
        ListNode* traverse2 = &two;
        traverse2 -> next = l2;

        ListNode merge = ListNode(0);
        ListNode* mergeHead = &merge;
        ListNode* mergeTraverse = mergeHead;

        ListNode* temp;
        while(traverse1 -> next != nullptr && traverse2 -> next != nullptr){
            if(traverse1 -> next -> val <= traverse2 -> next -> val){
                traverse1 = traverse1 -> next;
                temp = traverse1;
            } 
            else{
                traverse2 = traverse2 -> next; 
                temp = traverse2;
            }
            mergeTraverse -> next = temp;
            mergeTraverse = mergeTraverse -> next;
        }

        return mergeHead -> next;
    }
};
