
class Solution {
    
    func partition(_ nums: inout [Int], _ p: Int, _ r: Int) -> Int {
        var i = p
        for j in p ..< r {
            if nums[j] < nums[r] {
                if i != j { nums.swapAt(i, j) }
                i += 1
            }
        }
        nums.swapAt(i, r)
        return i
    }
    func quickSort(_ nums: inout [Int], _ p: Int, _ r: Int) {
        if p >= r { return }
        let q = partition(&nums, p, r)
        quickSort(&nums, p, q - 1)
        quickSort(&nums, q + 1, r)
    }
    
    func sortArray(_ nums: [Int]) -> [Int] {
        var array = nums
        quickSort(&array, 0, nums.count - 1)
        return array
    }
}
let s = Solution()
let a = [1,1,0,0,1]

let res = s.sortArray(a)
print(res)
