/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode ans[]=new ListNode[k],tmp=head;
        int cnt=0,j=0;
        while(tmp!=null) {
            cnt++;
            tmp=tmp.next;
        }
        tmp=head;
        while(k>0) {
            if(tmp!=null) {
                int groupSize=(int)Math.ceil((double)cnt/k);
                ListNode phead=tmp,ptr=phead;
                for(int i=0;i<groupSize-1;i++) ptr=ptr.next;
                tmp=ptr.next;
                ptr.next=null;
                ans[j++]=phead;
                cnt-=groupSize;
            }
            k--;
        }
        return ans;
    }
}