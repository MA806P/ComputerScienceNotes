
class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        guard nums.count >= 3 else {
            return 0
        }
        let sortedNums = nums.sorted()
        var sum = 0, start = 0, end = 0
        var result = sortedNums[0] + sortedNums[1] + sortedNums[2]
        for i in 0 ..< sortedNums.count {
            start = i + 1
            end = sortedNums.count - 1
            while start < end {
                sum = sortedNums[i] + sortedNums[start] + sortedNums[end]
                if abs(target - sum) < abs(target - result) {
                    result = sum
                }
                if sum < target {
                    start += 1
                } else if sum > target {
                    end -= 1
                } else {
                    return sum
                }
            }
        }
        return result
    }
}
let s = Solution()
print(s.threeSumClosest([1,1,1,0], -100))
