class Solution {
    
    func intToRoman(_ num: Int) -> String {
        let items = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        let values = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        var result = String(), i = 0, tmpNum = num

        while tmpNum != 0 {
            while tmpNum >= values[i] {
                tmpNum -= values[i]
                result += items[i]
            }
            i += 1
        }
        return result
    }
    
}

let s = Solution()
print(s.intToRoman(1998))
