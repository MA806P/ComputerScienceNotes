import Foundation

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
    
    //深度优先迭代
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        if root == nil { return false }
        
        var stack = [TreeNode]()
        stack.append(root!)
        
        var sumStack = [Int]()
        sumStack.append(sum - root!.val)
        
        while !stack.isEmpty {
            let node = stack.removeLast(), res = sumStack.removeLast()
            if node.left == nil && node.right == nil && res == 0 {
                return true
            }
            if node.left != nil {
                stack.append(node.left!)
                sumStack.append(res - node.left!.val)
            }
            if node.right != nil {
                stack.append(node.right!)
                sumStack.append(res - node.right!.val)
            }
        }
        return false
    }
}


let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let s = Solution()
print(s.hasPathSum(n1,3))
