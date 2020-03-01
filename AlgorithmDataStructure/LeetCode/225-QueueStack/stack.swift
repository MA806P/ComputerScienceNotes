

class QueueNode {
    var data: Int
    var next: QueueNode?
    
    init(_ data: Int) {
        self.data = data
        self.next = nil
    }
}

class MyQueue {
    var size = 0
    var head: QueueNode?
    var tail: QueueNode?
    
    func enqueue(_ data: Int) {
        let node = QueueNode(data)
        if head == nil {
            head = node
        } else {
            tail!.next = node
        }
        tail = node;
        size += 1
    }
    
    func dequeue() -> Int {
        if head == nil { return -1 }
        let data = head!.data
        head = head!.next
        size -= 1
        return data
    }
    
    func isEmpty() -> Bool {
        return size == 0
    }
}


class MyStack {
    var a = MyQueue()
    var b = MyQueue()
    
    /** Initialize your data structure here. */
    init() {
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        a.enqueue(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        while a.size > 1 {
            b.enqueue(a.dequeue())
        }
        let data = a.dequeue()
        let q = b
        b = a
        a = q
        return data
    }
    
    /** Get the top element. */
    func top() -> Int {
        return a.tail?.data ?? -1
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return a.size == 0
    }
}

let obj = MyStack()
obj.push(1)
obj.push(2)
let ret_2: Int = obj.pop()
let ret_3: Int = obj.top()
let ret_4: Bool = obj.empty()
print(ret_2, ret_3, ret_4)
