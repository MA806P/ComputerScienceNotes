
class Solution {
    
    //方法一，用字典计数。哈希表映射
    func majorityElement0(_ nums: [Int]) -> Int {
        var map = [Int: Int]()
        var max = 0, res = nums[0]
        for num in nums {
            map[num] == nil ? (map[num] = 1) : (map[num]! += 1)
            if map[num]! > max {
                max = map[num]!
                res = num
            }
        }
        return res
    }
    
    //方法二, 排序之后下标为 n/2 的元素一定是众数。
    func majorityElement1(_ nums: [Int]) -> Int {
        let sortedNums = nums.sorted()
        return sortedNums[nums.count/2]
    }
    
    //方法三， Boyer-Moore 投票算法
    //把众数记为 +1，其他数记为 -1，全部加起来和 > 0
    func majorityElement(_ nums: [Int]) -> Int {
        var candidate = 0, count = 0
        for n in nums {
            if count == 0 { candidate = n }
            count += candidate == n ? 1 : -1
        }
        
        return candidate;
    }

}

let s = Solution()
print(s.majorityElement([1,3,2,3,3]))
