
class Solution {
    
    func isValidSudoku(_ board: [[String]]) -> Bool {
        var row = Array(repeating: Array(repeating: false, count: 9), count: 9)
        var col = Array(repeating: Array(repeating: false, count: 9), count: 9)
        var block = Array(repeating: Array(repeating: false, count: 9), count: 9)
        
        for i in 0 ..< 9 {
            for j in 0 ..< 9 {
                if board[i][j] != "." {
                    let num = Int("\(board[i][j])")! - 1
                    let blockIndex = i / 3 * 3 + j / 3
                    
                    if row[i][num] || col[j][num] || block[blockIndex][num] {
                        return false
                    } else {
                        row[i][num] = true
                        col[j][num] = true
                        block[blockIndex][num]  = true
                    }
                }
            }
        }
        return true
    }
    
}

let s = Solution()
var a = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
print(s.isValidSudoku(a))
