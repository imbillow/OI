fun lcs(a: String, b: String): String {
    val cache = mutableMapOf(Pair(-1, -1) to "")
    for (i in -1 until a.length)
        cache[Pair(i, -1)] = ""
    for (i in -1 until b.length)
        cache[Pair(-1, i)] = ""

    (0 until a.length).forEach { x ->
        (0 until b.length).forEach { y ->
            cache[Pair(x, y)] = if (a[x] == b[y]) {
                cache[Pair(x - 1, y - 1)] + a[x]
            } else {
                maxOf(cache[Pair(x, y - 1)]!!, cache[Pair(x - 1, y)]!!, Comparator { a, b -> a.length - b.length })
            }
        }
    }
    return cache.values.maxBy { it.length }!!
}


/**"anothertest", "notatest"
 *
 * a n o t h e r t e s t
 *
 * an ao at ah ae ar at ae as at
 *
 * ano ant anh ane anr ant ane ans ant
 *
 * anot anoh anoe anor anot anoe anos anot
 */

fun main() {
    lcs("skajdjkasd", "sajdiuased")
}