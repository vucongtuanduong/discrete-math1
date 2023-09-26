# Algorithm
## 1: First setting
we can easily see that the first setting is when there is n bits of 0s consecutive and m bits of 1s consecutive right after the sequence of 0 bits
### 
ex: 3 * 4 (n * m): 0001111

## 2: Last setting
we can easily see that the last setting is the opposite state of the first setting

###
ex: 3 * 4 (n * m): 1111000

## 3: the generating algorithm
We can all see that in the string there must have n bits of 0 and m bits of 1 no matter how they order.And this is my algorithm:

### 
we go from right to left,count the number of 0s and 1s in the string. We find the first position when you meet the first 0. We change the value of that position to 1 and after that position, we iterate x times (x is the number of 0s ) and assign it to 0. And we continue to do the same with 1 after the 0s.
####
ex: the state we are currently at is 0110110 with 3 * 4 matrix (n= 3, m = 4)
##### 
the rightmost number is 0 (it doesn't matter the rightmost number) and the index when we first meet 0 is 4 and change the value to 1 at that index(remember to minus 1 the number of 1s because we change 0 to 1), we also have two 0s and one 1s (original is 2 but we change 0 to 1 before)
######
-> 0111xxx
###### add 0
-> 011100x
###### add 1
-> 0111001
