

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
    
    
    //递归
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        let l = maxDepth(root!.left)
        let r = maxDepth(root!.right)
        return max(l, r) + 1
    }
    
    //迭代
    func maxDepth0(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        var stack = [(TreeNode?,Int)]()
        stack.append((root, 1))
        
        var ans = 0
        while stack.isEmpty == false {
            let item = stack.removeLast()
            let node = item.0
            let count = item.1
            if node != nil {
                ans = max(ans, count)
                stack.append((node!.left, count + 1))
                stack.append((node!.right, count + 1))
            }
            
        }
        return ans
    }
    
}

let n11 = TreeNode(2)
let n12 = TreeNode(1)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let n21 = TreeNode(1)
let n22 = TreeNode(2)
var n2 = TreeNode(3)
n2.left = n21
n2.right = n22

var n = TreeNode(4)
n.left = n1
n.right = n2

let s = Solution()
print(s.maxDepth0(n))

