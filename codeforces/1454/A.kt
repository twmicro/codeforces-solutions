fun main() {
    repeat {
        val n = readInt()
        val list = mutableListOf<Int>()
        for (i in 1..n) list.add(i)
        list.sort()
        list.reverse()
        if (n % 2 != 0) {
            val tmp = list[n / 2]
            list[n / 2] = list.first()
            list[0] = tmp
        }
        outputCollection(list)
    }
}

var toPrint = ""
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun output(s: Any) { toPrint += s.toString() + "\n" }
fun outputCollection(s: Collection<Any>) {
    s.forEach { toPrint += "$it " }
    toPrint = toPrint.substring(0, toPrint.length - 1)
    toPrint += "\n"
}
fun repeat(action: (Int) -> Unit) {
    val times = readInt()
    for (t in 0 until times) action.invoke(t)
    println(toPrint)
}