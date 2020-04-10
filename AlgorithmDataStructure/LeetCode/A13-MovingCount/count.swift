

class Solution {
    
    func eachSum(_ a: Int) -> Int {
        if a <= 0 { return 0 }
        if a > 0 && a < 10 { return a }
        var temp = a, sum = 0
        while temp > 0 {
            sum += temp % 10
            temp = temp/10
        }
        return sum
    }
    
    
    //广度优先
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        if (k == 0) { return 1 }
        let dx = [0, 1], dy = [1, 0]
        
        var q = [(Int, Int)]()
        q.append((0, 0))
        
        var visited = Array(repeating: Array(repeating: 0, count: n), count: m)
        visited[0][0] = 1
        
        var ans = 1
        while q.isEmpty == false {
            let point = q.removeFirst()
            for i in 0 ..< 2 {
                let tx = dx[i] + point.0, ty = dy[i] + point.1
                if tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx][ty] == 1 || eachSum(tx) + eachSum(ty) > k {
                    continue
                }
                q.append((tx, ty))
                visited[tx][ty] = 1
                ans += 1
            }
        }
        return ans
    }
    
    
    
    
    
    //深度优先
    func movingCount1(_ m: Int, _ n: Int, _ k: Int) -> Int {
         var visited = Array(repeating: Array(repeating: 0, count: n), count: m)
        return dfs(0, 0, m, n, k, &visited);
        
    }
    func dfs(_ i: Int, _ j: Int, _ m: Int, _ n: Int, _ k: Int, _ visited: inout [[Int]]) -> Int {
        if i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || eachSum(i) + eachSum(j) > k {
            return 0
        }
        visited[i][j] = 1
        return dfs(i+1, j, m, n, k, &visited) + dfs(i, j+1, m, n, k, &visited) + 1
    }
    
    
    
}
let s = Solution()
print(s.movingCount1(38,15,9))
