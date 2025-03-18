/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,int> given;
        unordered_map<int,Node*> mp;
        Node* sentinel = new Node(-1);
        Node* sentinelTemp = sentinel;
        Node* temp = head;
        int idx = 0;
        while(temp){
            sentinelTemp->next = new Node(temp->val);
            sentinelTemp = sentinelTemp->next;
            mp[idx] = sentinelTemp;
            given[temp] = idx;
            temp = temp->next;
            idx++;
        }
        given[0] = -1;
        mp[-1] = 0;
        sentinelTemp = sentinel->next;
        temp = head;
        while(temp){
            sentinelTemp->random = mp[given[temp->random]];
            temp = temp->next;
            sentinelTemp = sentinelTemp->next;
        }
        return sentinel->next;    
    }
};