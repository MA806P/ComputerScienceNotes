class Solution {

    /*
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
    } */
    
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let nums1Size = nums1.count, nums2Size = nums2.count
        if nums1Size > nums2Size {
            return findMedianSortedArrays(nums2, nums1);
        }
        let length = nums1Size + nums2Size
        
        var iMin = 0, iMax = nums1Size, i = 0, j = 0
        
        while iMin <= iMax {
            i = (iMin + iMax)/2
            j = (length + 1)/2 - i
            if i < iMax && nums1[i] < nums2[j - 1] {
                iMin = i + 1
            } else if i > iMin && nums2[j] < nums1[i - 1] {
                iMax = i - 1
            } else {
                var maxLeft = 0
                if i == 0 {
                    maxLeft = nums2[j - 1]
                } else if j == 0 {
                    maxLeft = nums1[i - 1]
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1])
                }
                
                if length%2 == 1 {
                    return Double(maxLeft)
                } else {
                    var minRight = 0
                    if i == nums1Size {
                        minRight = nums2[j]
                    } else if j == nums2Size {
                        minRight = nums1[i]
                    } else {
                        minRight = min(nums1[i], nums2[j])
                    }
                    return Double(maxLeft + minRight)/2.0
                }
                
            }
        }
        return 0.0
    }
    
}

let s = Solution()
print(s.findMedianSortedArrays([1,2], [3]))
