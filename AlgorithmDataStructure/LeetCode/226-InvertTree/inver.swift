
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
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        if root == nil { return nil }
        
        var queue = [TreeNode]()
        queue.append(root!)
        while !queue.isEmpty {
            let current = queue.removeFirst()
            let temp = current.left
            current.left = current.right
            current.right = temp
            if current.left != nil { queue.append(current.left!) }
            if current.right != nil { queue.append(current.right!) }
        }
        return root
    }
}


let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12
print(n1.val, n1.left!.val, n1.right!.val)

let s = Solution()
let ans = s.invertTree(n1)
print(ans!.val, ans!.left!.val, ans!.right!.val)


