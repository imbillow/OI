def max_sequence(arr)
  arr.empty? ? 0 : [0, (0...arr.length).flat_map {|i| (i...arr.length).map {|j| arr[i..j]}}.map(&:sum).max].max
end

puts max_sequence [1, 2, 3]
puts max_sequence [-2, 1, -3, 4, -1, 2, 1, -5, 4]
puts max_sequence [11]
puts max_sequence [-2, 1, -7, 4, -10, 2, 1, 5, 4]

