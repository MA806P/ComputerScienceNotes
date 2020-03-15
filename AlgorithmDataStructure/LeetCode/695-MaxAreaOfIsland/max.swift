
class Solution {
    
    //广度优先搜索
    //遍历网格，是1的进入队列，然后遍历队列，上下左右计算面积
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        var ans = 0, tempGrid = grid
        let dirX = [0,1,0,-1], dirY = [1,0,-1,0]
        
        for i in 0 ..< tempGrid.count {
            for j in 0 ..< tempGrid[i].count {
                if tempGrid[i][j] != 1 { continue }
                var count = 0
                var dirXY = [(Int,Int)]()
                dirXY.append((i, j))
                
                while dirXY.isEmpty == false {
                    let tempXY = dirXY.removeFirst()
                    let tempX = tempXY.0, tempY = tempXY.1
                    if tempX >= 0 && tempX < tempGrid.count && tempY >= 0 && tempY < tempGrid[i].count && tempGrid[tempX][tempY] == 1 {
                        count += 1
                        tempGrid[tempX][tempY] = 0
                    } else {
                        continue
                    }
                    
                    for index in 0 ..< 4 {
                        dirXY.append((tempX + dirX[index], tempY + dirY[index]))
                    }
                }
                ans = max(ans, count)
            }
            
        }
        
        return ans
    }
    
}

let s = Solution()
print(s.maxAreaOfIsland([[0,1,1],[0,1,0],[0,0,0]]))

