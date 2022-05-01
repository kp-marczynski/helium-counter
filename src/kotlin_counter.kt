fun countHelium(containerStructure: IntArray): Int {
    val begin = System.nanoTime()

    var count = 0
    var leftBound = 0
    var rightBound = containerStructure.size - 1
    var maxLeftBoundReached = false
    var maxRightBoundReached = false
    while (leftBound < rightBound) {
        if (!maxLeftBoundReached) {
            var indexShift = 1
            var tempCount = 0
            while (leftBound + indexShift < rightBound && containerStructure[leftBound + indexShift] < containerStructure[leftBound]) {
                tempCount += containerStructure[leftBound] - containerStructure[leftBound + indexShift]
                indexShift++
            }
            if (containerStructure[leftBound + indexShift] >= containerStructure[leftBound]) {
                count += tempCount
                leftBound += indexShift
            } else {
                maxLeftBoundReached = true
            }
        }
        if (!maxRightBoundReached) {
            var indexShift = 1
            var tempCount = 0
            while (rightBound - indexShift > leftBound && containerStructure[rightBound - indexShift] < containerStructure[rightBound]) {
                tempCount += containerStructure[rightBound] - containerStructure[rightBound - indexShift]
                indexShift++
            }
            if (containerStructure[rightBound - indexShift] >= containerStructure[rightBound]) {
                count += tempCount
                rightBound -= indexShift
            } else {
                maxRightBoundReached = true
            }
        }
    }
    val end = System.nanoTime()
    println("Elapsed time in nanoseconds: ${end - begin}")

    return count
}

fun main(args: Array<String>) {
    assert(6 == countHelium(intArrayOf(0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1)))
    assert(8 == countHelium(intArrayOf(0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2)))
    assert(9 == countHelium(intArrayOf(4, 2, 0, 3, 2, 5)))
    assert(83 == countHelium(intArrayOf(6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3)))
}
