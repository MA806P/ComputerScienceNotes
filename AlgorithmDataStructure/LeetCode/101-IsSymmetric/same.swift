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
    
    func isSameLeftRight(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        return isSameLeftRight(p!.left, q!.right) && isSameLeftRight(p!.right, q!.left)
    }
    
    //递归
    func isSymmetric0(_ root: TreeNode?) -> Bool {
        if root == nil { return true }
        return isSameLeftRight(root!.left, root!.right)
    }
    
    //迭代
    func check(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        return true
    }
    func isSymmetric(_ root: TreeNode?) -> Bool {
        if root == nil { return true }
        var p = root!.left, q = root!.right
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        
        
        var arrayP = [TreeNode]()
        arrayP.append(p!)
        var arrayQ = [TreeNode]()
        arrayQ.append(q!)
        
        while arrayP.isEmpty == false {
            
            p = arrayP.removeFirst()
            q = arrayQ.removeFirst()
            if check(p, q) == false { return false }
            
            if p!.left != nil && q!.right != nil {
                arrayP.append(p!.left!)
                arrayQ.append(q!.right!)
            } else if !(p!.left == nil && q!.right == nil) {
                return false
            }
            
            if p!.right != nil && q!.left != nil {
                arrayP.append(p!.right!)
                arrayQ.append(q!.left!)
            } else if !(p!.right == nil && q!.left == nil) {
                return false
            }
        }
        return true
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
print(s.isSymmetric(n))
