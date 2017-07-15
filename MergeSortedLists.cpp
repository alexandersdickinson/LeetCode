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
        ListNode* traverse1 = l1;
        ListNode* traverse2 = l2;
        //Assign starting value of merged list.
        if(l1 == nullptr && l2 == nullptr){
            return {}; 
        }
        else if(l1 == nullptr || l2 == nullptr){
            return (l1 == nullptr) ? l2 : l1; 
        }
        ListNode* mergeHead = (l1 -> val >= l2 -> val) ? l2 : l1;
        ListNode* mergeTraverse = mergeHead;
        (l1 -> val >= l2 -> val) ? traverse2 = traverse2 -> next : traverse1 = traverse1 -> next;
        while(traverse1 -> next != nullptr && traverse2 -> next != nullptr){
            if(traverse1 -> val >= traverse2 -> val && traverse2 -> next != nullptr){
                mergeTraverse -> next = traverse2;
                traverse2 = traverse2 -> next; 
            }
            else if(traverse1 -> next != nullptr){
                mergeTraverse -> next = traverse1;
                traverse1 = traverse1 -> next; 
            }
            mergeTraverse = mergeTraverse -> next;
        }       
        mergeTraverse = mergeTraverse -> next;
        std::cout << "Traverse1 has untraversed elements: " << (traverse1 -> next != nullptr) << std::endl;
        std::cout << "Traverse2 has untraversed elements: " << (traverse2 -> next != nullptr) << std::endl;
        mergeTraverse -> next = (traverse1 -> next != nullptr && traverse2 -> next == nullptr) ? traverse1: traverse2;
        return mergeHead;
    }
};
