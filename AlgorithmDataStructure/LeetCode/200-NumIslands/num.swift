
import Foundation



//并查集
/*
 并查集代替搜索。
 为了求出岛屿的数量，我们可以扫描整个二维网格。
 如果一个位置为 11，则将其与相邻四个方向上的 11 在并查集中进行合并。
最终岛屿的数量就是并查集中连通分量的数目。
*/
class UnionFind {
    var grid: [[Character]]
    var parent: [Int]
    var rank: [Int]
    var count: Int
    
    init(_ g: [[Character]]) {
        grid = g
        count = 0
        parent = [Int]()
        rank = [Int]()
        let m = grid.count, n = grid.first!.count
        for i in 0 ..< m {
            for j in 0 ..< n {
                if grid[i][j] == "1" {
                    parent.append(i * n + j)
                    count += 1
                } else {
                    parent.append(-1)
                }
                rank.append(0)
            }
        }
    }
    
    func find(_ i: Int) -> Int {
        if parent[i] != i {
            parent[i] = find(parent[i])
        }
        return parent[i]
    }
    
    func unite(_ x: Int, _ y: Int) {
        var rootx = find(x), rooty = find(y)
        if rootx != rooty {
            if rank[rootx] < rank[rooty] {
                swap(&rootx, &rooty)
            }
            parent[rooty] = rootx
            if rank[rootx] == rank[rooty] { rank[rootx] += 1 }
            count -= 1
        }
    }
    
}


class Solution {
    
    //广度优先搜索
    //遍历网格，是1的进入队列，然后遍历队列，上下左右查看
    //若是1，修改为0，同时入队。等待下一次遍历
    //直到周围都是0，这一片1，遍历完毕 +1
    func numIslands(_ grid: [[Character]]) -> Int {
        var ans = 0, tempGrid = grid
        let dirX = [0,1,0,-1], dirY = [1,0,-1,0]
        
        for i in 0 ..< tempGrid.count {
            for j in 0 ..< tempGrid[i].count {
                if tempGrid[i][j] != "1" { continue }
                ans += 1
                var dirXY = [(Int,Int)]()
                dirXY.append((i, j))
                
                while dirXY.isEmpty == false {
                    let tempXY = dirXY.removeFirst()
                    let tempX = tempXY.0, tempY = tempXY.1
                    if tempX >= 0 && tempX < tempGrid.count && tempY >= 0 && tempY < tempGrid[i].count && tempGrid[tempX][tempY] == "1" {
                        tempGrid[tempX][tempY] = "0"
                    } else {
                        continue
                    }
                    
                    for index in 0 ..< 4 {
                        dirXY.append((tempX + dirX[index], tempY + dirY[index]))
                    }
                }
            }
            
        }
        
        return ans
    }
    
    
    //并查集
    func numIslands1(_ grid: [[Character]]) -> Int {
        let nr = grid.count
        if nr <= 0 { return 0 }
        let nc = grid.first!.count
        
        let uf = UnionFind(grid)
        var tempGrid = grid
        for i in 0 ..< nr {
            for j in 0 ..< nc {
                if tempGrid[i][j] != "1" { continue }
                tempGrid[i][j] = "0"
                if i - 1 > 0 && tempGrid[i - 1][j] == "1" { uf.unite(i * nc + j, (i - 1) * nc + j) }
                if i + 1 < nr && tempGrid[i + 1][j] == "1" { uf.unite(i * nc + j, (i + 1) * nc + j) }
                if j - 1 > 0 && tempGrid[i][j - 1] == "1" { uf.unite(i * nc + j, i * nc + j - 1) }
                if j + 1 < nc && tempGrid[i][j + 1] == "1" { uf.unite(i * nc + j, i * nc + j + 1) }
            }
        }
        
        return uf.count
        
    }
    
}

let s = Solution()
print(s.numIslands1([["0","0","1"],["0","1","0"],["0","0","1"]]))
