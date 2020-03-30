
class Solution {
    
    func maxDistance(_ grid: [[Int]]) -> Int {
        
        let n = grid.count
        let dirX = [0,1,0,-1];
        let dirY = [1,0,-1,0];
        var tempGrid = grid
        
        var queue = [(Int, Int)]()
        for i in 0 ..< n {
            for j in 0 ..< n {
                if tempGrid[i][j] == 1 {
                    queue.append((i,j))
                }
            }
        }
        
        var point: (Int, Int)?
        var hasOcean = false
        while queue.isEmpty == false {
            point = queue.removeFirst()
            for i in 0 ..< 4 {
                let newI = point!.0 + dirX[i], newJ = point!.1 + dirY[i]
                if newI < 0 || newI >= n || newJ < 0 || newJ >= n || tempGrid[newI][newJ] != 0 {
                    continue
                }
                tempGrid[newI][newJ] = tempGrid[point!.0][point!.1] + 1
                hasOcean = true
                queue.append((newI, newJ))
            }
        }
        
        if point == nil || hasOcean == false {
            return -1;
        }
        return tempGrid[point!.0][point!.1] - 1
    }
}
let s = Solution()
let a = [[0,0,1,1,1],[0,1,1,0,0],[0,0,1,1,0],[1,0,0,0,0],[1,1,0,0,1]]

let res = s.maxDistance(a)
print(res)

