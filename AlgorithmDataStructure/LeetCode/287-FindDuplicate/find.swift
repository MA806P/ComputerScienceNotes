

class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        
        var dict = [Int: Int]()
        for i in nums {
            if dict[i] == nil {
                dict[i] = 1
            } else {
                return i;
            }
        }
        return 0;
    }
}
let s = Solution()
print(s.findDuplicate([1,2,3,4,2]))

//题目要求只能使用额外的 O(1) 的空间  时间复杂度小于 O(n^2)
//数组中只有一个重复的数字，但它可能不止重复出现一次。
