/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*sentinel = new ListNode(-101);
        ListNode* sentinelTemp = sentinel;
        ListNode* temp = head;
        while(temp){
            if(temp->val !=sentinelTemp->val){
                sentinelTemp->next = temp;
                sentinelTemp = sentinelTemp->next;
            }
            temp = temp->next;
            sentinelTemp->next = 0;
        }
        return sentinel->next;
    }
};