
This can also be done using deque
Just maintain 2 deque --> min_deque and max_deque​

Array [10,1,2,4,7,2] ,  limit=5

In actually, we will store index rather than values that will help to find difference 
Min_deque  - tells about the latest min value 
            back [10] front 
              1  [1]          
              2  [2,1]        
              4  [4,2,1]
              7  [7,4,2,1]
              2  [2,1]

              [0]
              [1]
              [2,1]
              [3,2,1]
              [4,3,2,1]
              [2,1]
              
Max_deque    back [10] front
              1   [1,10]
              2   [2,10]
              4   [4,10]
              7   [7,10]
              2   [2,7,10]

              [0]
              [1,0]
              [2,0]
              [3,0]
              [4,0]
              [5,4,0]

So now at index 0, ans = 1
          index 1, ans = 1 as (10-1)> 5 , so 10 from max_queue will pop out 
          index 2, ans = 2 
          index 3, ans = 3
          index 4, ans = 3 as (7-1)>5, so 1 from min_queue will pop out
          index 5, ans = 4
