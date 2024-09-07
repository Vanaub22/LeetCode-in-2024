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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    ArrayList<ArrayList<Integer>> paths=new ArrayList<>();
    void findAllPaths(TreeNode root, ArrayList<Integer> path) {
        if(root==null) {
            paths.add(new ArrayList<Integer>(path));
            return;
        }
        path.add(root.val);
        findAllPaths(root.left,path);
        findAllPaths(root.right,path);
        path.removeLast();
    }
    boolean isSubarray(ArrayList<Integer> arr, ArrayList<Integer> subarr) {
        int m=subarr.size(),n=arr.size();
        if(m>n) return false;
        for(int i=0;i<=n-m;i++){
            boolean isSub=true;
            for(int j=0;j<m;j++)
            if(arr.get(i+j)!=subarr.get(j)){
                isSub=false;
                break;
            }
            if(isSub) return true;
        }
        return false;
    }
    boolean hasSubarray(ArrayList<Integer> arr) {
        for(ArrayList<Integer> path:paths) if(isSubarray(path,arr)) return true;
        return false;
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        ArrayList<Integer> arr=new ArrayList<>();
        ListNode temp=head;
        while(temp!=null) {
            arr.add(temp.val);
            temp=temp.next;
        }
        findAllPaths(root,new ArrayList<Integer>());
        return hasSubarray(arr);
    }
}