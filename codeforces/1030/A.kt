/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val n = readInt()
    val arr = readInts()
    if (arr.contains(1)) println("hard")
    else println("easy")
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