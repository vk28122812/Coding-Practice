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
    ListNode* reverse(ListNode* head){
        ListNode* tmp = head;
        ListNode* prev = NULL;
        while(tmp){
            ListNode* next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next; 
        }
        return prev;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL)return head;
        ListNode* tmp = head;
        int total = 0;
        while(tmp){
            total += 1;
            tmp = tmp->next;
        }

        k = k % total;

        tmp = head;

        while(total != (k+1) ){
            cout << total <<" "<< k<<"\n";
            total -= 1;
            tmp = tmp->next;
        }

        ListNode* next = tmp->next;
        if(tmp)tmp->next = NULL;

        ListNode* newHead = reverse(head);
        ListNode* newNext = reverse(next);

        if(head)head->next = newNext;

        return reverse(newHead);

    }
};