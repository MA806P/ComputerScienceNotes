
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
    
    //广度优先遍历 BFS
    func rightSideView0(_ root: TreeNode?) -> [Int] {
        if root == nil { return [] }
        
        var ans = [Int]()
        var q = [TreeNode]()
        q.append(root!)
        while q.isEmpty == false {
            let size = q.count
            for i in 0 ..< size {
                let node = q.removeFirst()
                if node.left != nil { q.append(node.left!) }
                if node.right != nil { q.append(node.right!) }
                if i == size - 1 { ans.append(node.val) }
            }
        }
        return ans
    }
    
    
    //深度优先遍历 DFS
    var dfsAns = [Int]()
    func dfs(_ root: TreeNode?, _ depth: Int) {
        if root == nil { return; }
        if depth == dfsAns.count { dfsAns.append(root!.val) }
        dfs(root!.right, depth + 1)
        dfs(root!.left, depth + 1)
    }
    func rightSideView(_ root: TreeNode?) -> [Int] {
        if root == nil { return [] }
        dfs(root, 0)
        return dfsAns
    }
    
    
}

let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12


let s = Solution()
print(s.rightSideView(n1))
