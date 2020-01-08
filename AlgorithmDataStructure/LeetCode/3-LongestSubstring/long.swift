class Solution {
    
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var count = 0
        var subArray = [Character]()
        for c in s {
            if subArray.contains(c) {
                subArray.removeSubrange(0...subArray.firstIndex(of: c)!)
            }
            subArray.append(c)
            count = count > subArray.count ? count : subArray.count
        }
        return count
    }
    
}

let s = Solution()
print(s.lengthOfLongestSubstring("ab"))
