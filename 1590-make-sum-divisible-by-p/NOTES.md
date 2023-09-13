Suppose ​example 

if array is like [....] sum = 50 and p=6

Now I have to find the subarray whose sum is 2,8,14,20 which will give 48,42,36,30... that will be divisible by 6

Updated problem : Find smallest subarray such that subarray_sum%p==2

For that solution will be if sum=40 ----> 26 4 - 2
                                 41 ----> 27 5 - 3
                                 42 ----> 28 0 - 4
                                 43 ----> 29 1 - 5
                                 44 ----> 30 2 - 0
                                 45 ----> 31 3 - 1

So if I am find current modulo as 5 , so need to watch latest value of 3 in map and return the difference 
