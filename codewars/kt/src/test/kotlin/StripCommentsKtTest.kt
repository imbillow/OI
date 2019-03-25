import org.junit.jupiter.api.Test
import kotlin.test.assertEquals

class StripCommentsKtTest {
    @Test
    fun testFixed() {
        val cur = solution("apples, plums % and bananas\npears\noranges !applesauce", charArrayOf('%', '!'))
        assertEquals(
            "apples, plums\npears\noranges",
            cur
        )
        assertEquals("Q\nu\ne", solution("Q @b\nu\ne -e f g", charArrayOf('@', '-')))
        arrayOf(
            Triple(
                """quince kiwi quince bananas
                   apples - bananas quince quince tangerine pears
                   bananas $ apple
                   quince quince apples bananas @ banana
                   apples""".trimIndent(),
                """quince kiwi quince bananas
                   apples
                   bananas
                   quince quince apples bananas
                   apples""".trimIndent(), charArrayOf('$', '@')
            )
        ).forEach { assertEquals(it.second, solution(it.first, it.third)) }
    }
}