
class CQueue {
    var s1:[Int]
    var s2:[Int]
    
    init() {
        s1 = [Int]()
        s2 = [Int]()
    }
    
    func appendTail(_ value: Int) {
        s1.append(value)
    }
    
    func deleteHead() -> Int {
        if s2.isEmpty {
            s2.append(contentsOf: s1.reversed())
            s1.removeAll()
        }
        return s2.isEmpty ? -1 : s2.removeLast();
    }
}
var q = CQueue()
q.appendTail(1)
q.appendTail(2)
print(q.deleteHead())
print(q.deleteHead())
print(q.deleteHead())
