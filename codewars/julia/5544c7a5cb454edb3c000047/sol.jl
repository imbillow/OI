module Bouncing
    export bouncing_ball

    function bouncing_ball(h, bounce, window)
      h > 0 && 0 < bounce < 1 && window < h ? log(bounce, window / h) |> ceil |> x -> muladd(x,2,-1) : -1
    end

end