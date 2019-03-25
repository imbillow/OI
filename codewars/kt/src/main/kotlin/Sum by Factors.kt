import kotlin.math.sqrt

fun isPrime(n: Int): Boolean =
    (2..sqrt(n.toDouble()).toInt()).all { n % it != 0 }

fun sumOfDivided(l: IntArray): String = when {
    l.isEmpty() -> ""
    else -> (2..l.max()!!).filter { i -> isPrime(i) && l.any { j -> j % i == 0 } }
        .joinToString("") { "($it ${l.filter { i -> i % it == 0 }.sum()})" }
}

fun main() {
    println(sumOfDivided(intArrayOf(12, 15)))
}