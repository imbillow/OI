import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import kotlin.random.Random

internal class SmallestPossibleSumKtTest {

    @Test
    fun `Basic tests`() {
        assertEquals(9, solution(longArrayOf(6, 9, 21)))
        assertEquals(3, solution(longArrayOf(1, 21, 55)))
        assertEquals(5, solution(longArrayOf(3, 13, 23, 7, 83)))
        assertEquals(923, solution(longArrayOf(71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71)))
        assertEquals(22, solution(longArrayOf(11, 22)))
        assertEquals(2, solution(longArrayOf(5, 17)))
        assertEquals(12, solution(longArrayOf(4, 16, 24)))
        assertEquals(9, solution(longArrayOf(9)))
    }

    @Test
    fun `big tests`() {
    }

    private fun randomArray(): LongArray {
        val sz = Random.nextInt(30000, 100000)
        return MutableList(sz) { Random.nextLong(1, Long.MAX_VALUE) }.toLongArray()
    }
}