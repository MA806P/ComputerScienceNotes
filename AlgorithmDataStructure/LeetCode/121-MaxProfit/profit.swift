
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count < 2 { return 0 }
        var res = 0, profit = 0
        for i in 0 ..< prices.count - 1 {
            profit = max(0, profit + prices[i+1] - prices[i])
            res = max(profit, res)
        }
        return res
    }
}

let s = Solution()
print(s.maxProfit([1,2,5]))
