import Foundation

//归并排序
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



//------------------------------------------


//快速排序
fileprivate func partition<T: RandomAccessCollection & MutableCollection>(_ a: inout T, from low: T.Index, to high: T.Index) -> T.Index where T.Element: Comparable {
    let pivot = a[high]
    var i = low, j = low
    while i < high {
        if a[i] < pivot {
            a.swapAt(i, j)
            a.formIndex(after: &j)
        }
        a.formIndex(after: &i)
    }
    a.swapAt(high, j)
    return j
    
    //    let pivot = a[low]
    //    var i = a.index(after: low), j = low
    //    while i <= high {
    //        if a[i] < pivot {
    //            a.formIndex(after: &j)
    //            a.swapAt(i, j)
    //        }
    //        a.formIndex(after: &i)
    //
    //        print(a, i, j)
    //    }
    //    a.swapAt(low, j)
    //    print(a)
    //    return j
}

fileprivate func quickSort<T: RandomAccessCollection & MutableCollection>(_ a: inout T, from low: T.Index, to high: T.Index) where T.Element: Comparable {
    if low >= high {
        return
    }
    let m = partition(&a, from: low, to: high)
    quickSort(&a, from: low, to: a.index(before: m))
    quickSort(&a, from: a.index(after: m), to: high)
}

fileprivate func quickSort<T: RandomAccessCollection & MutableCollection>(_ a: inout T) where T.Element: Comparable {
    quickSort(&a, from: a.startIndex, to: a.index(before: a.endIndex))
}




//print(testArray.startIndex, testArray.endIndex, testArray.index(before: testArray.endIndex), testArray.index(after: testArray.startIndex)) //0 10 9 1



//var a = [7,8,1,6]
//partition(&a, from: 0, to: 3)



var testArray = [5,6,0,9,4,8,2,1,3,7]
mergeSort(&testArray)
print(testArray) //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

quickSort(&testArray)
print(testArray) //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]



