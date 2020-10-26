fun main() {
    val count = readLine()!!.toInt()
    var toPrint = ""
    for(i in 0 until count) {
        val first = readLine()!!
        val second = readLine()!!
        var yes = false

        for (j in first.indices) {
            if (second.contains(first[j])) {
                yes = first.length == second.length
                break
            }
        }

        toPrint += if (yes) "yes\n" else "no\n"
    }
    print(toPrint)
}