import { BinaryTree, TreeNode } from './data'

// εεΊιε
const preorder = (treeNode: TreeNode) => {
    console.log(treeNode.value)
    if (treeNode.left) {preorder(treeNode.left)}
    if (treeNode.right) {preorder(treeNode.right)}
}

preorder(BinaryTree)
