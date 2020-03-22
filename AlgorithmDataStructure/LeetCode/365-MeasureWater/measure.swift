
struct Status {
    var a: Int
    var b: Int
}
extension Status: Hashable {}


class Solution {
    
    func canMeasureWater(_ x: Int, _ y: Int, _ z: Int) -> Bool {
        if x + y < z { return  false }
        if z == 0 { return true }
        
        //广度优先遍历
        var queue = [Status]()
        var visited = Set<Status>()
        let initStatus = Status(a: 0, b: 0)
        queue.append(initStatus)
        visited.insert(initStatus)
        
        while queue.isEmpty == false {
            let head = queue.removeFirst()
            let curA = head.a, curB = head.b
            
            //判断是否满足
            if curA == z || curB == z || curA + curB == z { return true }
            
            //从当前状态获取下一步的所有状态
            let nextStatus = getNextStatuses(curA, curB, x, y)
            
            //将下一步的状态添加到队列中，供下一轮遍历
            for status in nextStatus {
                //已经遍历过的状态就不用添加了，否则会无限循环
                if visited.contains(status) == false {
                    queue.append(status)
                    visited.insert(status)
                }
            }
        }
        return false
    }
    
    
    func getNextStatuses(_ curA: Int, _ curB: Int, _ x: Int, _ y: Int) -> [Status] {
        var nextStatus = [Status]()
        
        //从当前状态，到下一步状态一共8种情况
        //装满A。A未满才加
        if curA < x { nextStatus.append(Status(a: x, b: curB)) }
        
        //装满B。B未满才加
        if curB < y { nextStatus.append(Status(a: curA, b: y)) }
        
        //清空A。A有水才清空
        if curA > 0 { nextStatus.append(Status(a: 0, b: curB)) }
        
        //清空B。B有水才清空
        if curB > 0 { nextStatus.append(Status(a: curA, b: 0)) }
        
        //从A到B，使B满，A还有剩余
        if curA - (y - curB) > 0 { nextStatus.append(Status(a: curA - (y - curB), b: y)) }
        
        //从A到B，A倒尽，B未满
        if curA + curB < y { nextStatus.append(Status(a: 0, b: curA + curB)) }
        
        //从B到A，使A满，B还有剩余
        if curB - (x - curA) > 0 { nextStatus.append(Status(a: x, b: curB - (x - curA))) }
        
        //从B到A，B倒尽，A未满
        if curA + curB < x { nextStatus.append(Status(a: curA + curB, b: 0)) }
        
        return nextStatus
    }
    
}

let s = Solution()
print(s.canMeasureWater(3, 5, 4))

