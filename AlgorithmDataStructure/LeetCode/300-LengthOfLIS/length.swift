
class Solution {
    
    //方法一，动态规划
    //dp[i] = max(dp[0...i-1]) + 1
    //遍历前面的，是否比当前的小，小就 dp+1 记录下最大值
    func lengthOfLIS0(_ nums: [Int]) -> Int {
        let n = nums.count
        if n < 2 { return n }
        
        var dp = Array(repeating: 0, count: n)
        dp[0] = 1
        var maxans = 0, maxval = 0
        for i in 1 ..< n {
            maxval = 0
            for j in 0 ..< i {
                if nums[i] > nums[j] {
                    maxval = max(maxval, dp[j])
                }
            }
            dp[i] = maxval + 1
            maxans = max(maxans, dp[i])
        }
        return maxans
    }
    
    //方法二，贪心算法+二分查找插入
    //用一数组保存升序的数，每次插入的值都是递增幅度小的，贪心
    func lengthOfLIS(_ nums: [Int]) -> Int {
        let n = nums.count
        if n < 2 { return n }
        
        var len = 1
        var d = Array(repeating: 0, count: n + 1)
        d[len] = nums[0]
        
        for i in 1 ..< n {
            if nums[i] > d[len] {
                len += 1; d[len] = nums[i]
            } else {
                var left = 1, right = len, mid = 0, pos = 0
                while left <= right {
                    mid = left + (right - left)/2
                    if nums[i] > d[mid] {
                        pos = mid; left = mid + 1
                    } else {
                        right = mid - 1
                    }
                }
                d[pos + 1] = nums[i]
                print(d)
            }
        }
        return len
    }


}

let s = Solution()
print(s.lengthOfLIS([10,9,2,5,3,7,101,18]))

