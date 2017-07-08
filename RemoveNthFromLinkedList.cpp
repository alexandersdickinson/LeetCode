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
        ListNode* crawler = head;
        ListNode* removalNode = head;
        bool noWhile = true;
        //Go to nth node in the linked list
        for(int i = 0; i < n && crawler -> next != nullptr; ++i){
            crawler = crawler -> next; 
        }
        std::cout << "Crawler -> next is " << crawler -> next << std::endl;
        while(crawler -> next != nullptr){
            noWhile = false;
            crawler = crawler -> next;
            removalNode = removalNode -> next;
        }       
        if(noWhile){
            head = head -> next; 
        }
        else{
            ListNode* temp;
            std::cout << removalNode -> val << std::endl;
            if(removalNode -> next == nullptr){
                temp = nullptr; 
            }
            else{
                temp = removalNode -> next -> next;
            }
            removalNode -> next = temp;
        }
        return head;
    }
};
