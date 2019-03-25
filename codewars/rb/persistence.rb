def persistence(n)
  n<10 ? 0 : 1+persistence(n.digits.reduce(:+))
end
