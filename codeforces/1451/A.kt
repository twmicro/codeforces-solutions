/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    repeat {
        val n = readInt()
        var res = 0
        if (n == 2) res = 1
        else if (n % 2 == 0 || n == 3) res = 2
        else if (n != 1) res = 3
        output(res)
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