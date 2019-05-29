
import Foundation


fileprivate func merge<T>(_ a: inout T, from low: T.Index, throuh mid: T.Index, to high: T.Index) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    
    var i = low, j = a.index(mid, offsetBy: 1), tmp = Array<T.Element>()
    tmp.reserveCapacity(a.distance(from: low, to: high) + 1)
    
    while i <= mid && j <= high  {
        if a[i] < a[j] {
            tmp.append(a[i])
            a.formIndex(after: &i)
        } else {
            tmp.append(a[j])
            a.formIndex(after: &j)
        }
    }
    
    var start = i, end = mid
    if j <= high {
        start = j
        end = high
    }
    tmp.append(contentsOf: a[start...end])
    
    var current = low
    for element in tmp {
        a[current] = element
        a.formIndex(after: &current)
    }
}


fileprivate func mergeSort<T>(_ a: inout T, from low: T.Index, to high: T.Index) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    
    if low >= high {
        return
    }
    
    let dist = a.distance(from: low, to: high)
    let mid = a.index(low, offsetBy: dist/2)
    
    //print(low, high, "=", dist," --- ", mid);
    
    mergeSort(&a, from: low, to: mid)
    mergeSort(&a, from: a.index(mid, offsetBy: 1), to: high)
    merge(&a, from: low, throuh: mid, to: high)
}


public func mergeSort<T>(_ a: inout T) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    mergeSort(&a, from: a.startIndex, to: a.index(before: a.endIndex))
}


var testArray = [5,6,0,9,4,8,2,1,3,7]
mergeSort(&testArray)
print(testArray) //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

//print(testArray.startIndex, testArray.endIndex, testArray.index(before: testArray.endIndex)) //0 10 9



