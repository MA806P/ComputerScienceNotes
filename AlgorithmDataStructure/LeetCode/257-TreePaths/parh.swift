
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
    func dfs(_ root: TreeNode?, _ paths: inout [String], _ path: String) {
        if (root == nil) { return }
        
        var tempPath =  path + "\(root!.val)"
        if root!.left == nil && root!.right == nil {
            paths.append(tempPath)
            return
        }
        tempPath += "->"
        dfs(root!.left, &paths, tempPath)
        dfs(root!.right, &paths, tempPath)
    }
    func binaryTreePaths0(_ root: TreeNode?) -> [String] {
        var paths = [String]()
        dfs(root, &paths, "")
        return paths
    }
    
    
    
    //迭代
    func binaryTreePaths(_ root: TreeNode?) -> [String] {
        var paths = [String]()
        if (root == nil) { return paths }
        
        var nodeStack = [TreeNode]()
        nodeStack.append(root!)
        
        var pathStack = [String]()
        pathStack.append("\(root!.val)")
        
        while !nodeStack.isEmpty {
            let node = nodeStack.removeLast()
            let path = pathStack.removeLast()
            if node.left == nil && node.right == nil {
                paths.append(path)
            }
            
            if node.left != nil {
                nodeStack.append(node.left!)
                pathStack.append(path + "->\(node.left!.val)")
            }
            if node.right != nil {
                nodeStack.append(node.right!)
                pathStack.append(path + "->\(node.right!.val)")
            }
        }
        
        return paths
    }
    
}


let n11 = TreeNode(1)
let n12 = TreeNode(2)
var n1 = TreeNode(3)
n1.left = n11
n1.right = n12

let s = Solution()
print(s.binaryTreePaths(n1))



