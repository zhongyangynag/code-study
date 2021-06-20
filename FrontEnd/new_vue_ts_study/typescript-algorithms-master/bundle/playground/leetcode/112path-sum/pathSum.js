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
function hasPathSum(root, sum) {
    if (!root) {
        return false;
    }
    return dfs(root, sum, 0);
}
exports.default = hasPathSum;
function dfs(node, sum, curSum) {
    if (!node.left && !node.right) {
        return curSum + node.val === sum ? true : false;
    }
    if (node.left && dfs(node.left, sum, curSum + node.val)) {
        return true;
    }
    if (node.right && dfs(node.right, sum, curSum + node.val)) {
        return true;
    }
    return false;
}
var test = new TreeNode(1);
test.left = new TreeNode(2);
var res = hasPathSum(test, 1);
console.log(res);
//# sourceMappingURL=pathSum.js.map