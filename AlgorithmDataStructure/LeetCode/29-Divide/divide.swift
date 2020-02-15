class Solution {
    
    func divide(_ dividend: Int, _ divisor: Int) -> Int {
        if (dividend == 0 ) { return 0; }
        if (divisor == 1) { return dividend; }
        if (divisor == -1) {
            if (dividend > -2147483648) { return -dividend; }
            return 2147483647;
        }
        if (dividend == divisor) { return 1; }
        

        var sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }
        
        var a = abs(dividend)
        let b = abs(divisor)
        if a < b { return 0 }
        
        var res = 0
        for i in (0 ... 31).reversed() {
            if ((a >> i) >= b) {//找出足够大的数2^n*divisor
                res += 1 << i;//将结果加上2^n
                a -= b << i;//将被除数减去2^n*divisor
            }
        }
        return sign > 0 ? res : -res
    }
    
}

let s = Solution()
print(s.divide(-2147483648, 2))
