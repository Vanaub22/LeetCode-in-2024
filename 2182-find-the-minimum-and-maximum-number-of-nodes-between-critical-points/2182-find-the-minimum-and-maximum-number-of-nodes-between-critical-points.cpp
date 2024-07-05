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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* pred=head,*ptr=head->next,*succ=head->next->next;
        int fidx=-1,lidx=0,i=-1,min_dist=1e5;
        while(succ) {
            i++;
            if((ptr->val<pred->val && ptr->val<succ->val) || (ptr->val>pred->val && ptr->val>succ->val)) {
                if(fidx==-1) fidx=i;
                if(i!=fidx) min_dist=min(min_dist,i-lidx);
                lidx=i;
            }
            pred=ptr;
            ptr=ptr->next;
            succ=ptr->next;
        }
        return min_dist==1e5?vector<int>{-1,-1}:vector<int>{min_dist,lidx-fidx};
    }
};