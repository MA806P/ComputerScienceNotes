class Solution {
    func orangesRotting(_ grid: [[Int]]) -> Int {
        var ans = 0, cnt = 0;
        let dirX = [0,1,0,-1], dirY = [1,0,-1,0]
        var dis = Array(repeating: Array(repeating: -1, count: 10), count: 10)
        var q = [(Int, Int)]()
        
        let m = grid.count, n = grid.first!.count
        for i in 0 ..< m {
            for j in 0 ..< n {
                if grid[i][j] == 2 {
                    q.append((i, j))
                    dis[i][j] = 0
                } else if grid[i][j] == 1 {
                    cnt += 1
                }
            }
        }
        
        while q.isEmpty == false {
            let item = q.removeFirst()
            for i in 0 ..< 4 {
                let tx = item.0 + dirX[i], ty = item.1 + dirY[i]
                if tx<0 || tx>=m || ty<0 || ty>=n || dis[tx][ty]>=0 || grid[tx][ty]==0 { continue }
                dis[tx][ty] = dis[item.0][item.1] + 1
                q.append((tx, ty))
                if grid[tx][ty] == 1 {
                    cnt -= 1
                    ans = dis[tx][ty]
                    if cnt == 0 {  break; }
                }
            }
        }
        
        return cnt == 0 ? ans : -1
    }
}

let s = Solution()
print(s.orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))

