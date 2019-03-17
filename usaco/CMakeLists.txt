cmake_minimum_required(VERSION 3.12.0)

include_directories("1.3 complete search")

add_executable(milk2 "1.3 complete search/milk2.cpp")
add_executable(transform "1.3 complete search/transform.cpp")
add_executable(namenum "1.3 complete search/namenum.cpp")
add_executable(palsquare "1.3 complete search/palsquare.cpp")
add_executable(dualpal "1.3 complete search/dualpal.cpp")


include_directories("1.4 greedy")

add_executable(milk "1.4 greedy/milk.cpp")
add_executable(barn1 "1.4 greedy/barn1.cpp")
add_executable(crypt1 "1.4 greedy/crypt1.cpp")
add_executable(combo "1.4 greedy/combo.cpp")
add_executable(wormhole "1.4 greedy/wormhole.cpp")
add_executable(skidesign "1.4 greedy/skidesign.cpp")

include_directories("1.5 more search techniques")

add_executable(ariprog "1.5 more search techniques/ariprog.cpp")
add_executable(milk3 "1.5 more search techniques/milk3.cpp")

include_directories("1.6 Binary Numbers")

add_executable(numtri "1.6 Binary Numbers/numtri.cpp")
add_executable(pprime "1.6 Binary Numbers/pprime.cpp")
add_executable(sprime "1.6 Binary Numbers/sprime.cpp")

include_directories("2.1 graph theory")

add_executable(castle "2.1 graph theory/castle.cpp")