fun solution(input: String, markers: CharArray): String =
    input.replace(Regex("\\s[${markers.joinToString("") { "\\$it" }}].*"), "")

fun main() {
    println("apples, plums % and bananas".replace(Regex("\\s[%!].*$"), ""))
}