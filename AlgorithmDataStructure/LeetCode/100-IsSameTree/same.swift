
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
    
    func check(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        return true
    }
    
    //迭代
    func isSameTree0(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        
        
        var arrayP = [TreeNode]()
        arrayP.append(p!)
        var arrayQ = [TreeNode]()
        arrayQ.append(q!)
        
        while arrayP.isEmpty == false {
            
            let tempP = arrayP.removeFirst()
            let tempQ = arrayQ.removeFirst()
            if check(tempP, tempQ) == false { return false }
            
            if tempP.left != nil && tempQ.left != nil {
                arrayP.append(tempP.left!)
                arrayQ.append(tempQ.left!)
            } else if !(tempP.left == nil && tempQ.left == nil) {
                return false
            }
            
            if tempP.right != nil && tempQ.right != nil {
                arrayP.append(tempP.right!)
                arrayQ.append(tempQ.right!)
            } else if !(tempP.right == nil && tempQ.right == nil) {
                return false
            }
            
        }
        return true
    }
    
    
    //递归
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil { return true }
        if p == nil || q == nil { return false }
        if p!.val != q!.val { return false }
        return isSameTree(p!.left, q!.left) && isSameTree(p!.right, q!.right)
    }
    
}

let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let n21 = TreeNode(1)
let n22 = TreeNode(2)
var n2 = TreeNode(3)
n2.left = n21
n2.right = n22


let s = Solution()
print(s.isSameTree(n1, n2))
