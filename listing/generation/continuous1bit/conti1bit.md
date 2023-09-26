# first setting
(n -k)bit of 0s and then k bit of 1s
# second setting
k bits of 1s and then k-1 bits of 1s seperated by 0
## 
ex: n = 7, k = 3: 1110110
# algorithm:
we iterate from right to left, if we meet 0 then change 0 to 1 and of course check if it's valid, else we change from 1 to 0. If we iterate through all but cannot find position , it means that is when we shift k bits of 1s to left 1 bit, and all bits after the k bits of 1s are all 0.
ex:
0111010 - > 0111011 . Or 0111011 -> 1110000
