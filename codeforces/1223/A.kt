fun main() {
    val count = readLine()!!.toInt()
    val numbers = mutableListOf<Int>()
    val minimum = 4

    for (i in 0 until count) numbers.add(readLine()!!.toInt())
    for (n in numbers) {
        if (n == minimum) println(0)
        else if (n < minimum) println(minimum - n)
        else if (n % 2 == 0) println(0)
        else println(1)
    }
}