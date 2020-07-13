class Solution {
    func intersection0(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        let l1 = nums1.count, l2 = nums2.count
        if (l1 <= 0 || l2 <= 0) { return [] }
        if l1 > l2 {
            return self.intersection(nums2, nums1);
        }
        
        var ans = [Int]()
        var dictionary = [Int: Int]()
        for n in nums1 {
            dictionary[n] = 1;
        }
        
        
        for n in nums2 {
            if dictionary[n] != nil && !ans.contains(n) {
                dictionary[n]! -= 1
                ans.append(n)
            }
        }
        
        return ans
    }
    
    
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        let l1 = nums1.count, l2 = nums2.count
        if (l1 <= 0 || l2 <= 0) { return [] }
        
        let set1 = Set(nums1), set2 = Set(nums2)
        print(set1, set2)
        
        let ans = Array(set1.intersection(set2))
        return ans
    }
}
let s = Solution()
print(s.intersection([1,2,3,1,2,3],[1,3]))

