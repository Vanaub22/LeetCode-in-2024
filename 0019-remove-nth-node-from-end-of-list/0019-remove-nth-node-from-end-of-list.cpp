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

// Solving in one-pass using hashing (follow-up problem)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* tmp=head;
        while(tmp) {
            nodes.push_back(tmp);
            tmp=tmp->next;
        } 
        int L=nodes.size();
        if(L-n-1<0) return head->next;
        else if(L-n+1>=L) nodes[L-2]->next=nullptr;
        else nodes[L-n-1]->next=nodes[L-n+1];
        return head;
    }
};