class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxArea = 0, area = 0, i = 0, j = height.count - 1
        while i < j {
            if height[i] < height[j] {
                area = (j - i) * height[i]
                i += 1
            } else {
                area = (j - i) * height[j]
                j -= 1
            }
            maxArea = maxArea < area ? area : maxArea
        }
        return maxArea
    }
}

let s = Solution()
print(s.maxArea([1,8,6,2,5,4,8,3,7]))
