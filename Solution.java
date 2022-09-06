class Solution {
    public TreeNode pruneTree(TreeNode root) {
        if(existOne(root))
            return getResult(root);
        return null;
    }

    private TreeNode getResult(TreeNode node) {
        if (existOne(node.left))
            node.left = getResult(node.left);
        else
            node.left = null;
        if (existOne(node.right))
            node.right = getResult(node.right);
        else
            node.right = null;
        return node;
    }

    private boolean existOne(TreeNode node) {
        if (node == null)
            return false;
        if(node.val == 1)
            return true;
        else
            return existOne(node.left) || existOne(node.right);
    }
}