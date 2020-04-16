

class Solution {
    func updateMatrix(_ matrix: [[Int]]) -> [[Int]] {
        let m = matrix.count
        if m <= 0 { return matrix }
        let n = matrix.first!.count
        if n <= 0 { return matrix }
        
        var res = matrix
        var s = [(Int, Int)]()
        var visited = Array(repeating: Array(repeating: 0, count: n), count: m)
        
        //把为0的如队列
        for i in 0 ..< m {
            for j in 0 ..< n {
                if matrix[i][j] == 0 {
                    s.append((i, j)); visited[i][j] = 1;
                }
            }
        }
        
        
        //然后以0为起点向四周扩散
        let dx = [0, 1, 0, -1], dy = [1, 0, -1, 0]
        while s.isEmpty == false {
            let point = s.removeFirst()
            for i in 0 ..< 4 {
                let nx = point.0 + dx[i], ny = point.1 + dy[i]
                if nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] == 1  { continue }
                visited[nx][ny] = 1
                res[nx][ny] = res[point.0][point.1] + 1
                //把修改过的点，入队列，修改后的值是离0最近的距离
                //后面再以这个修改后的点向四方扩散修改周围的。这个不用担心周围还有更近的，
                //为0的都入队了，从0开始扩散，近的先修改，远的周围没有0的后修改
                s.append((nx, ny))
            }
            
        }
        
        return res
    }
}
let s = Solution()
print(s.updateMatrix([[0,0,0],[0,1,0],[1,1,1]]))
