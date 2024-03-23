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
    void reorderList(ListNode* head) {
        if(!head->next) return;
        deque<ListNode*> dq;
        ListNode *temp=head;
        while(temp) {
            dq.push_back(temp);
            temp=temp->next;
        }
        temp=dq.front();
        dq.pop_front();
        bool i=true;
        while(!dq.empty()) {
            if(i) {
                temp->next=dq.back();
                dq.pop_back();
                i=false;
            }
            else {
                temp->next=dq.front();
                dq.pop_front();
                i=true;
            }
            temp=temp->next;
            temp->next=nullptr;
        }
    }
};