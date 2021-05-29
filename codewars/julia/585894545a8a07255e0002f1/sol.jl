function count_patterns_from(start::Char, len::Int)
  function next(x,xs)
    connections =
    [
      ['A','B'],
      ['A','F'],
      ['A','E'],
      ['A','H'],
      ['A','D'],
      ['B','C'],
      ['B','F'],
      ['B','I'],
      ['B','E'],
      ['B','G'],
      ['B','D'],
      ['C','F'],
      ['C','H'],
      ['C','E'],
      ['C','D'],
      ['D','E'],
      ['D','I'],
      ['D','H'],
      ['D','G'],
      ['E','F'],
      ['E','I'],
      ['E','H'],
      ['E','G'],
      ['F','I'],
      ['F','H'],
      ['F','G'],
      ['G','H'],
      ['H','I'],
    ]
    crossover = []
  end
  len > 9 ? 0 : 1
end