

class Solution {
    
    func twoSumIndex(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        for (i, num) in nums.enumerated() {
            if let lastIndex = dict[target - num] {
                return [lastIndex, i]
            } else {
                dict[num] = i
            }
        }
        fatalError("no")
    }
    
    func twoSum(nums: [Int], _ target: Int) -> Bool {
        var set = Set<Int>()
        for num in nums {
            if set.contains(target - num) {
                return true
            }
            set.insert(num)
        }
        return false
    }

    
    //let array = [1,3,4,5,6,7,8,9]
    //twoSum(nums: array, 10) //true
    //twoSumIndex(nums: array, target: 10) // [2,4]

}
