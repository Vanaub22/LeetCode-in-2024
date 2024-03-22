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
private:
    bool isPalindrome(string& x) {
        int n=x.size();
        for(int i=0;i<n/2;i++) if(x[i]!=x[n-i-1]) return false;
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        string x="";
        ListNode* tmp=head;
        while(tmp) {
            x+=to_string(tmp->val);
            tmp=tmp->next;
        }
        return isPalindrome(x);
    }
};