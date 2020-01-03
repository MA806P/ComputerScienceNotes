
class Solution {
    func romanToInt(_ s: String) -> Int {
        let map = ["I":1, "V": 5, "X": 10, "L":50, "C":100, "D" :500, "M":1000]
        var sum = 0, preInt = 0, currentInt = 0;
        for i in s.enumerated() {
            currentInt = map["\(i.element)"] ?? 0
            if currentInt > preInt {
                sum += currentInt - preInt * 2
            } else {
                sum += currentInt
            }
            preInt = currentInt
        }
        return sum
    }
}

let s = Solution()
print(s.romanToInt("III"))
print(s.romanToInt("IV"))
print(s.romanToInt("IX"))
print(s.romanToInt("LVIII"))
print(s.romanToInt("MCMXCIV"))
// 3 4 9 58 1994
