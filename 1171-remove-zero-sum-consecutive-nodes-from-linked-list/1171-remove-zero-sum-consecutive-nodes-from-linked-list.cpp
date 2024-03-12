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
        map<int,ListNode*> pref;
        // Attaching one extra node so that the reference is not lost even if the head node is removed
        ListNode* extra=new ListNode(0,head),*temp=extra;
        int prefSum=0;
        while(temp) {
            prefSum+=temp->val;
            pref[prefSum]=temp; // Eventually gets the last node with that Prefix Sum
            temp=temp->next;
        }
        temp=extra,prefSum=0;
        while(temp) {
            prefSum+=temp->val;
            temp->next=pref[prefSum]->next;
            temp=temp->next;
        }
        return extra->next;
    }
};