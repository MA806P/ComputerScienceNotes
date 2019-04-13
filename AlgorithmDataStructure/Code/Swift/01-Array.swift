import Foundation

public struct MyArray<Element> {
    
    private var data: [Element]
    private var capacity = 0
    private var count = 0
    
    init(defaultElement: Element, capacity: Int) {
        data = [Element](repeating: defaultElement, count: capacity)
        self.capacity = capacity
    }
    
    func find(at index: Int) -> Element? {
        guard index >= 0, index < count else {
            return nil
        }
        return data[index]
    }
    
    mutating func delete(at index: Int) -> Bool {
        guard index >= 0, index < count else {
            return false
        }
        
        for i in index ..< count - 1 {
            data[i] = data[i + 1]
        }
        
        count -= 1
        return true
    }
    
    mutating func insert(value: Element, at index: Int) -> Bool {
        guard index >= 0, index < count else {
            return false
        }
        
        for i in (index ... count - 1).reversed() {
            data[i + 1] = data[i]
        }
        
        data[index] = value;
        count += 1
        return true
    }
    
    mutating func add(value: Element) -> Bool {
        guard count < capacity else {
            return false
        }
        
        data[count] = value
        count += 1
        return true
    }
    
    func printAll() {
        print(data)
    }
}


var myArray = MyArray<Int>(defaultElement: 0, capacity: 10)
print("add 11 result = \(myArray.add(value: 11))")
print("add 11 result = \(myArray.add(value: 21))")
print("add 11 result = \(myArray.add(value: 31))")
print("insert 12 at 2 result = \(myArray.insert(value: 12, at: 2))")
myArray.printAll() //[11, 21, 12, 31, 0, 0, 0, 0, 0, 0]

print("find index 3 result = \(myArray.find(at: 3))") //31




