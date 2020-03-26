

class Solution {
    
    func halfPow(_ x: Double, _ n: Int) -> Double {
        if n == 0 { return 1; }
        let half = halfPow(x, n/2)
        if n%2 == 1 {
            return half * half * x
        } else {
            return half * half
        }
    }
    
    func myPow(_ x: Double, _ n: Int) -> Double {
        var tn = n
        var tx = x
        if tn < 0 {
            tn = -tn
            tx = 1/x
        }
        return halfPow(tx, tn);
    }
    
}

let s = Solution()
print(s.myPow(2, 10))
