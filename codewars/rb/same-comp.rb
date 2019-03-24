def comp(a,b)
  a&&b?a.sort.map{|x| x*x}==b.sort:false
end
