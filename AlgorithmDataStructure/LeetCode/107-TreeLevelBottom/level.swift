

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
    
    //广度优先 BFS
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        if root == nil { return [] }
        
        var ans = [[Int]]()
        var q = [TreeNode]()
        q.append(root!)
        while q.isEmpty == false {
            let size = q.count
            var levelArray = [Int]()
            for _ in 0 ..< size {
                let node = q.removeFirst()
                levelArray.append(node.val)
                if node.left != nil { q.append(node.left!) }
                if node.right != nil { q.append(node.right!) }
            }
            ans.insert(levelArray, at: 0) //这里从上往下，每次都插入第一位
        }
        return ans
    }
    
    
}


let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let s = Solution()
print(s.levelOrderBottom(n1))
