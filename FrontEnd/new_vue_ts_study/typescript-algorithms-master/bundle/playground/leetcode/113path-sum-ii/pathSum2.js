"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var TreeNode = (function () {
    function TreeNode(val, left, right) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
    return TreeNode;
}());
function pathSum(root, sum) {
    var nodeSet = [];
    if (!root)
        return nodeSet;
    dfs(root, [], nodeSet, sum, 0);
    return nodeSet;
}
exports.default = pathSum;
function dfs(node, nodes, nodesSet, sum, curSum) {
    var slice = nodes.slice();
    slice.push(node.val);
    if (!node.left && !node.right && curSum + node.val === sum) {
        nodesSet.push(slice);
    }
    node.left && dfs(node.left, slice, nodesSet, sum, curSum + node.val);
    node.right && dfs(node.right, slice, nodesSet, sum, curSum + node.val);
}
//# sourceMappingURL=pathSum2.js.map