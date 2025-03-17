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
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int s = 0;
        ListNode* tmp = head;
        while(tmp){
            s += tmp->val;
            mp[s] = tmp;
            tmp = tmp->next;
        }   
        ListNode* ans = new ListNode(-1);
        ListNode* ansTmp = ans;
        s = 0;
        if(mp.count(s))tmp = mp[s]->next;
        else tmp = head;
        while(tmp){
            s += tmp->val;
            ansTmp->next = tmp;
            ansTmp = ansTmp->next;
            if(mp.count(s)){
                tmp = mp[s]->next;
            }else tmp = tmp->next;
        }
        ansTmp->next = 0;
        return ans->next;
    }
};