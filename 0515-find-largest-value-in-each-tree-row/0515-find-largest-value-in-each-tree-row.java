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
    public List<Integer> largestValues(TreeNode root) {
        if(root==null) return new ArrayList<>();
        List<Integer> ans=new ArrayList<>();
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            int n=q.size(),maxNodeInRow=Integer.MIN_VALUE;
            for(int i=0;i<n;i++) {
                TreeNode node=q.peek();
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
                maxNodeInRow=Math.max(maxNodeInRow,node.val);
                q.poll();
            }
            ans.add(maxNodeInRow);
        }
        return ans;
    }
}