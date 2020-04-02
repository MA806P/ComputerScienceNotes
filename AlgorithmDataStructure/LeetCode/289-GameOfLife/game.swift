

class Solution {
    func gameOfLife(_ board: inout [[Int]]) {
        let near = [0,1,-1];
        let row = board.count, col = board.first!.count
        var liveCount = 0
        
        let copyBoard = board
        for i in 0 ..< row {
            for j in 0 ..< col {
                
                liveCount = 0
                for x in 0 ..< 3 {
                    for y in 0 ..< 3 {
                        if !(near[x] == 0 && near[y] == 0) {
                            let r = i + near[x], c = j + near[y]
                            if r < row && r >= 0 && c < col && c >= 0 && copyBoard[r][c] == 1 {
                                liveCount += 1
                            }
                        }
                    }
                }
                
                if liveCount < 2 || liveCount > 3 {
                    board[i][j] = 0
                } else if liveCount == 3 && copyBoard[i][j] == 0 {
                    board[i][j] = 1
                }
                
            }
        }
        
        
    }
}
let s = Solution()
var a = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
print(a)
s.gameOfLife(&a)
print(a)
