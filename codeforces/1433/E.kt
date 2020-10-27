fun main() {
     val people = readLine()!!.toLong()
     println (fact(people - 1) / (people / 2))
}

fun fact(input: Long): Long {
     if(input == 1L) return 1
     else return fact(input-1L)*input
}
