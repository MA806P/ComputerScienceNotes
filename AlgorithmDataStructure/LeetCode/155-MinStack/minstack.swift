
class MinStack {
    
    var data:[Int]
    var helper:[Int]
    
    /** initialize your data structure here. */
    init() {
        data = [Int]()
        helper = [Int]()
    }
    
    func push(_ x: Int) {
        data.append(x)
        if helper.isEmpty || helper.last! >= x {
            helper.append(x)
        } else {
            helper.append(helper.last!)
        }
    }
    
    func pop() {
        if !data.isEmpty {
            data.removeLast()
            helper.removeLast()
        }
    }
    
    func top() -> Int {
        return data.last ?? -1
    }
    
    func getMin() -> Int {
        return helper.last ?? -1
    }
    
    func dump() {
        print("data = \(data), helper = \(helper), top = \(top()), min = \(getMin())")
    }
}

var stack = MinStack()
stack.push(6)
stack.push(3)
stack.push(7)
stack.dump()
stack.pop()
stack.dump()
stack.pop()
stack.dump()


