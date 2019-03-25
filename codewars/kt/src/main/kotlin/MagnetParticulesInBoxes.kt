import kotlin.math.abs
import kotlin.math.pow

fun doubles(maxk: Int, maxn: Int): Double {
    var total = 0.0

    for (k in 1..maxk) {
        var u = 0.0
        for (n in 1..maxn) u += 1 / (k * (n + 1.0).pow(2 * k))
        total += u
        if (abs(total - 0.7) <= 1e-6)
            break
    }
    return total
}