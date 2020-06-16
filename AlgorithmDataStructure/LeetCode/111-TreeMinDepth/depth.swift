

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
    
    //广度优先迭代
    func minDepth(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        var stack = [(TreeNode, Int)]()
        stack.append((root!, 1))
        
        var depth = 0
        while !stack.isEmpty {
            let item = stack.removeFirst()
            let node = item.0
            depth = item.1
            if node.left == nil && node.right == nil { break }
            if node.left != nil {
                stack.append((node.left!, depth + 1))
            }
            if node.right != nil {
                stack.append((node.right!, depth + 1))
            }
        }
        return depth
    }
    
    //深度优先迭代
    func minDepth1(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        var stack = [(TreeNode, Int)]()
        stack.append((root!, 1))
        
        var depth = Int.max
        while !stack.isEmpty {
            let item = stack.removeLast()
            let node = item.0, currentDepth = item.1
            if node.left == nil && node.right == nil {
                depth = min(currentDepth, depth)
            }
            if node.left != nil {
                stack.append((node.left!, currentDepth + 1))
            }
            if node.right != nil {
                stack.append((node.right!, currentDepth + 1))
            }
        }
        return depth
    }
    
    
}


let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let s = Solution()
print(s.minDepth(n1))
