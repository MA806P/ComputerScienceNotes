
class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        let l1 = nums1.count, l2 = nums2.count
        if (l1 <= 0 || l2 <= 0) { return [] }
        if l1 > l2 {
            return self.intersect(nums2, nums1);
        }
        
        var ans = [Int]()
        var dictionary = [Int: Int]()
        for n in nums1 {
            if dictionary[n] == nil {
                dictionary[n] = 1;
            } else {
                dictionary[n]! += 1;
            }
        }
        
        
        for n in nums2 {
            if dictionary[n] != nil && dictionary[n]! > 0 {
                dictionary[n]! -= 1
                ans.append(n)
            }
        }
        
        return ans
    }
}
let s = Solution()
print(s.intersect([1,2,3,1,2,3],[1,3]))

