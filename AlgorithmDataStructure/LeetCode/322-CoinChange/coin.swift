
class Solution {
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        if amount < 1 { return 0 }
        let max = amount + 1
        var dp = Array(repeating: max, count: max)
        dp[0] = 0
        
        for i in 1 ... amount {
            for coin in coins {
                if coin <= i {
                    dp[i] = min(dp[i], dp[i - coin] + 1)
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]
    }
    
}

let s = Solution()
print(s.coinChange([1,2,5], 11))
