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
        ListNode* ansNode = new ListNode();
        ListNode* runner = ansNode;
        ListNode* tmp = head;
        while(tmp){
            ListNode* nxt = tmp->next;
            while(nxt && nxt->val==tmp->val)nxt = nxt->next;
            if(nxt==tmp->next){
                runner->next = tmp;
                runner = runner->next;
                runner->next = 0;
            }
            tmp = nxt;
        }   
        return ansNode->next;
    }
};