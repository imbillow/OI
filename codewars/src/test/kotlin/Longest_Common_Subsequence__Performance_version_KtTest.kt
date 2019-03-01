import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

internal class Longest_Common_Subsequence__Performance_version_KtTest {
    @Test
    fun fixedTests() {
        assertEquals("", lcs("", ""))
        assertEquals("", lcs("abc", ""))
        assertEquals("", lcs("", "abc"))
        assertEquals("", lcs("a", "b"))
        assertEquals("a", lcs("a", "a"))
        assertEquals("ac", lcs("abc", "ac"))
        assertEquals("abc", lcs("abcdef", "abc"))
        assertEquals("acf", lcs("abcdef", "acf"))
        assertEquals("nottest", lcs("anothertest", "notatest"))
        assertEquals("12356", lcs("132535365", "123456789"))
        assertEquals("final", lcs("nothardlythefinaltest", "zzzfinallyzzz"))
        assertEquals("acdefghijklmnoq", lcs("abcdefghijklmnopq", "apcdefghijklmnobq"))
    }
}