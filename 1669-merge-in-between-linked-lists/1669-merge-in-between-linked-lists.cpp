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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=1;
        ListNode* temp=list2,*le,*s1;
        while(temp) {
            le=temp;
            temp=temp->next;
        }
        temp=list1;
        for(;;i++) {
            if(i==a) {
                s1=temp;
                temp=temp->next;
                i++;
                s1->next=list2;
            }
            if(i==b+1) {
                le->next=temp->next;
                break;
            }
            temp=temp->next;
        }
        return list1;
    }
};