
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
    
    
    //中序遍历
    func isValidBST(_ root: TreeNode?) -> Bool {
        var stack = [TreeNode]()
        var inorder = Int.min
        
        var tempRoot = root
        
        while stack.isEmpty == false || tempRoot != nil {
            while tempRoot != nil {
                stack.append(tempRoot!)
                tempRoot = tempRoot!.left
            }
            
            tempRoot = stack.removeLast()
            if tempRoot!.val <= inorder { return false }
            inorder = tempRoot!.val
            tempRoot = tempRoot!.right
        }
        return true
    }
    
    
}

let n11 = TreeNode(1)
let n12 = TreeNode(3)
var n1 = TreeNode(2)
n1.left = n11
n1.right = n12


let s = Solution()
print(s.isValidBST(n1))
