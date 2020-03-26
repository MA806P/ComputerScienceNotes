
class Solution {
    
    func surfaceArea(_ grid: [[Int]]) -> Int {
        let n = grid.count
        if n < 1 { return 0; }
        
        var ans = 0
        for i in 0 ..< n {
            for j in 0 ..< n {
                let level = grid[i][j]
                if level > 0 {
                    ans += level * 4 + 2
                    //前面，上面有遮挡的减去
                    if i > 0 { ans -= min(level, grid[i-1][j]) * 2 }
                    if j > 0 { ans -= min(level, grid[i][j-1]) * 2 }
                }
            }
        }
        return ans
    }
    
}

let s = Solution()
print(s.surfaceArea([[1,1,1],[1,0,1],[1,1,1]]))
