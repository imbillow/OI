import Test:Test
using Test

include("sol.jl")

@testset "Basic tests" begin
    @test fib(0) == 0
    @test fib(1) == 1
    @test fib(2) == 1
    @test fib(-2) == -1
    @test fib(-3) == 2
    @test fib(10) == 55
    @test fib(-10) == -55
end