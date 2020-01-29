
class Solution {
    
    func letterCombinations(_ digits: String) -> [String] {
        let letters = ["1":"", "2":"abc", "3":"def", "4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz","0":""]
        var resultArray = [String]()
        for num in digits {
            let str = letters[String(num)]!
            if resultArray.count <= 0 {
                for letter in str {
                    resultArray.append("\(letter)")
                }
            } else if str.count > 0 {
                var tmpArray = [String]()
                for letter in str {
                    for resultItem in resultArray {
                        tmpArray.append("\(resultItem)" + "\(letter)")
                    }
                }
                resultArray.removeAll()
                resultArray += tmpArray
            }
        }
        return resultArray
    }
    
}

let s = Solution()
print(s.letterCombinations("23"))

