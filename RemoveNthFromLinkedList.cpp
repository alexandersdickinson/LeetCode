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
        std::cout << "crawler has been initialized to " << crawler -> val << std::endl;
        ListNode remove = ListNode(0);
        ListNode* removalHead = &remove;
        removalHead -> next = head;
        std::cout << "removalHead has been initialized to " << removalHead -> val << " while next is " << removalHead -> next -> val << std::endl;
        ListNode* removalNode = removalHead;
        //Go to nth node in the linked list
        for(int i = 0; i < n - 1 && crawler -> next != nullptr; ++i){
            crawler = crawler -> next; 
            std::cout << "Crawler is now " << crawler -> next << std::endl;
        }
        //Start crawling through linked list with both crawler and removalnode.
        while(crawler -> next != nullptr){
            crawler = crawler -> next;
            removalNode = removalNode -> next;
            std::cout << "Removal node is now " << removalNode -> val << std::endl;
        }       
        std::cout << "Removal -> next node is now " << removalNode -> next -> val << std::endl;
        if(removalHead -> next == head){
            return head -> next; 
        }
        removalNode -> next = removalNode -> next -> next;
        return head;
    }
};
