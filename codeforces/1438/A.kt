// region Lib
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
// endregion
fun main() {
    repeat {
        val n = readInt()
        var s = ""
        for (i in 0 until n) s += "1 "
        s = s.substring(0, s.length - 1)
        output(s)
    }
}