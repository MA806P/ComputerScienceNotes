
class Solution {
    
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let nums1Size = nums1.count, nums2Size = nums2.count
        let length = nums1Size + nums2Size
        var index1 = 0, index2 = 0, left = 0, right = 0
        
        for _ in 0 ... length/2 {
            left = right
            if (index1 < nums1Size && (index2 >= nums2Size || nums1[index1] < nums2[index2]) ) {
                right = nums1[index1]
                index1 += 1
            } else {
                right = nums2[index2]
                index2 += 1
            }
        }
        
        if length%2 == 1 {
            return Double(right)
        } else {
            return Double(right + left)/2.0
        }
    }
    
}

let s = Solution()
print(s.findMedianSortedArrays([1,2], [3,4]))

