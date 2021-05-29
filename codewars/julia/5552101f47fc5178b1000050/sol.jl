module Digits
    export dig_pow

    function dig_pow(n, p)
      let ds = digits(n) |> reverse,
            left = mapreduce(^, +, ds, p:(p + length(ds)))
          left % n == 0 ? 1 : 0
      end
    end

end