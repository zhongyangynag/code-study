import TreeNode from "../../../utils/leetcode/TreeNode";

export default function buildTree(
    inorder: number[],
    postorder: number[]
): TreeNode | null {
    if (inorder.length === 0) return null;
    let divider = postorder[postorder.length - 1];
    let root = new TreeNode(divider, null, null);
    let i = 0;

    for (; i <= inorder.length; i++) {
        if (inorder[i] === divider) break;
    }

    root.left = buildTree(inorder.slice(0, i), postorder.slice(0, i));
    root.right = buildTree(
        inorder.slice(i + 1),
        postorder.slice(i, postorder.length - 1)
    );
    return root;
}
