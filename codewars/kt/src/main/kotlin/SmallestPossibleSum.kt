import kotlin.math.max
import kotlin.math.min

fun gcd(a: Long, b: Long): Long = when {
    a == 0L -> b
    b == 0L -> a
    else -> {
        val mini = min(a, b)
        val maxi = max(a, b)
        gcd(mini, maxi % mini)
    }
}

fun solution(numbers: LongArray): Long =
    numbers.reduce(::gcd) * numbers.size
