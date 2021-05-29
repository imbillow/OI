function fib(n::Int)
    function fib_iter(a, b, p, q, count)
        if count == 0
            b
        elseif iseven(count)
          fib_iter(a, b, q^2 + p^2, q^2 + 2q * p, count ÷ 2)
        else
          fib_iter(b * q + a * q + a * p, b * p + a * q, p, q, count - 1)
        end
    end
    n >= 0 ? fib_iter(big(1), big(0), big(0), big(1), n) : isodd(n) ? fib(-n) : - fib(-n)
end