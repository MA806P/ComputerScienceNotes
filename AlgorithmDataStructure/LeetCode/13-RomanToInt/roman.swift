
class Solution {
    func romanCharToInt(_ char: String) -> Int {
        var r: Int
        switch char {
            case "I": r = 1
            case "V": r = 5
            case "X": r = 10
            case "L": r = 50
            case "C": r = 100
            case "D": r = 500
            case "M": r = 1000
            default: r = 0
        }
        return r;
    }
    
    func romanToInt(_ s: String) -> Int {
        var sum = 0, preInt = 0, currentInt = 0;
        for i in s.enumerated() {
            currentInt = romanCharToInt("\(i.element)")
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
