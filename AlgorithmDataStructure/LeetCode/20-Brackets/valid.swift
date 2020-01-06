
class Solution {
    func isOK(_ a: Character, _ b: Character) -> Bool {
        return (a == "(" && b == ")") || (a == "[" && b == "]") || (a == "{" && b == "}")
    }
    func isValid(_ s: String) -> Bool {
        var stack = Stack()
        for item in s {
            if (stack.isEmpty) {
                stack.push(data: item)
            } else if (isOK(stack.peek!, item)) {
                stack.pop()
            } else {
                stack.push(data: item)
            }
        }
        return stack.isEmpty
    }
}

struct Stack {
    var stack = [Character]()
    var isEmpty: Bool { return stack.isEmpty }
    var peek: Character? { return stack.last }
    
    mutating func push(data: Character) {
        stack.append(data)
    }
    mutating func pop() -> Character? {
        return isEmpty ? nil : stack.removeLast()
    }
}


let s = Solution()
print(s.isValid("{[()]}"))
