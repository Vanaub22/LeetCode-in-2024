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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* fhead=new ListNode(-1,head),*temp=head,*prev=fhead;
        set<int> s(nums.begin(),nums.end());
        while(temp) {
            if(s.find(temp->val)==s.end()) {
                prev->next=temp;
                prev=temp;
            }
            else if(!temp->next) prev->next=nullptr;
            temp=temp->next;
        }
        return fhead->next;
    }
};