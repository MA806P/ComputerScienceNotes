
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    var res = 0
    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        deep(root)
        return res
    }
    
    func deep(_ node: TreeNode?) -> Int {
        if node == nil { return 0 }
        let l = deep(node!.left)
        let r = deep(node!.right)
        res = max(res, l + r)
        return max(l, r) + 1
    }
}


var l1 = TreeNode(9)
var left = TreeNode(7)
left.left = l1
var right = TreeNode(6)
var t = TreeNode(1)
t.left = left
t.right = right

let s = Solution()
print(s.diameterOfBinaryTree(t))

