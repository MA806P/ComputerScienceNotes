

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
    func levelOrder0(_ root: TreeNode?) -> [[Int]] {
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
            ans.append(levelArray)
        }
        return ans
    }
    
    
    //深度优先遍历 DFS. 递归
    var dfsAns = [[Int]]()
    func dfs(_ root: TreeNode?, _ depth: Int) {
        if root == nil { return; }
        if depth == dfsAns.count {
            dfsAns.append([])
        }
        dfsAns[depth].append(root!.val)
        
        dfs(root!.left, depth + 1) //注意左右顺序，从左到右
        dfs(root!.right, depth + 1)
    }
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
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
print(s.levelOrder(n1))
