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
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        deque<ListNode*> dq;
        ListNode *temp=head;
        while(temp) {
            if(!dq.empty() && dq.back()->val<temp->val) {
                dq.pop_back();
                continue;
            }
            dq.push_back(temp);
            temp=temp->next;
        }
        head=dq.front();
        head->next=nullptr;
        dq.pop_front();
        temp=head;
        while(!dq.empty()) {
            temp->next=dq.front();
            dq.pop_front();
            temp=temp->next;
        }
        return head;
    }
};