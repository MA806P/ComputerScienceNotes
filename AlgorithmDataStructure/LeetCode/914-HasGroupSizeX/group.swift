
class Solution {
    
    func m_gcd(_ a: Int, _ b: Int) -> Int {
        return b == 0 ? a : m_gcd(b, a%b);
    }
    
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        if deck.count < 2 { return false }
        var count = Array(repeating: 0, count: 10000)
        for n in deck { count[n] += 1; }
        
        var g = -1
        for i in count {
            if i > 0 {
                g = g == -1 ? i : m_gcd(g, i)
            }
        }
        return g > 2
    }
}

let s = Solution()
print(s.hasGroupsSizeX([1,2,3,4,4,3,2,1]))
