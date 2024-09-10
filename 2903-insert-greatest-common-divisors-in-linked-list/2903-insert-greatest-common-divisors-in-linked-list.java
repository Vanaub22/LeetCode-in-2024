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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode prev=head,temp=head.next;
        while(temp!=null) {
            ListNode gcdNode=new ListNode(gcd(prev.val,temp.val),temp);
            prev.next=gcdNode;
            prev=temp;
            temp=temp.next;
        }
        return head;
    }
    int gcd(int a, int b) {
        return a==b?a:a>b?gcd(a-b,b):gcd(a,b-a);
    }
}