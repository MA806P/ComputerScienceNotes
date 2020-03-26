class Solution {
    
    func numRookCaptures(_ board: [[Character]]) -> Int {
        let n = board.count
        if n < 1 { return 0; }
        
        var ans = -1, pi = 0, pj = 0
        
        for i in 0 ..< n {
            for j in 0 ..< n {
                if board[i][j] == "R" { pi = i; pj = j; ans = 0; break; }
            }
            if ans == 0 { break }
        }
        if ans == -1 { return 0; }
        
        let di = [0,1,0,-1]
        let dj = [1,0,-1,0]
        var step = 0
        for i in 0 ..< 4 {
            step = 0
            while true {
                let ti = pi + step * di[i];
                let tj = pj + step * dj[i];
                if ti < 0 || ti >= n || tj < 0 || tj >= n || board[ti][tj] == "B" { break }
                if board[ti][tj] == "p" { ans += 1; break}
                step += 1
            }
        }
        
        return ans
    }
    
}

let s = Solution()
print(s.numRookCaptures([[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]))
