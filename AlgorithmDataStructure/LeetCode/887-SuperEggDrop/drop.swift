
class Solution {
    
    
    /**
    dp(K,N) 为在状态 (K, N) 下最少需要的步数。根据以上分析我们可以列出状态转移方程：
    dp(K, N) = 1 + min( max(dp(K-1, X-1), dp(K, N-X)))
     https://github.com/Shellbye/Shellbye.github.io/issues/42
    */
    
    
    var memo = [Int: Int]()
    func superEggDrop(_ K: Int, _ N: Int) -> Int {
        return dp(K, N)
    }

    
    func dp(_ K: Int, _ N: Int) -> Int {
        if memo[N * 100 + K] == nil {
            var ans = 0
            if N == 0 {
                ans = 0
            } else if K == 1 {
                ans = N
            } else {
                var l = 1, h = N
                while l + 1 < h {
                    let x = (l + h)/2
                    let t1 = dp(K - 1, x - 1), t2 = dp(K, N - x)
                    if t1 < t2 {
                        l = x
                    } else if t1 > t2 {
                        h = x
                    } else { h = x; l = x}
                }
                
                ans = 1 + min(
                    max(dp(K - 1, l - 1), dp(K, N - l)),
                    max(dp(K - 1, h - 1), dp(K, N - h))
                )
                
            }
            
            memo[N * 100 + K] = ans;
        }
        return memo[N * 100 + K]!
    }
    
}
let s = Solution()
print(s.superEggDrop(3,14))
