
class Solution {
    //使用栈
    /*
     当前值比栈顶小，入栈，当前条形快被栈中前一个块界定
     当前值比栈顶大，出栈，栈顶条形块被当前的界定，计算值 累加
     */
    func trap(_ height: [Int]) -> Int {
        let n = height.count
        if n < 3 { return 0 }
        
        var stack = [Int]()
        var ans = 0, current = 0
        while current < n {
            while stack.isEmpty == false && height[current] > height[stack.last!] {
                let top = stack.removeLast();
                if stack.isEmpty { break; }
                let distance = current - stack.last! - 1
                let h = min(height[current], height[stack.last!]) - height[top]
                ans += distance * h
            }
            stack.append(current)
            current += 1
        }
        
        return ans
    }
}
let s = Solution()
print(s.trap([2,0,2]))
