**Why we going to the segment where the ele is greater than mid?**
I will try to explain it more simply. What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). How does that guarantee the result? Think about it, there are 2 possibilities.a) rising slope has to keep rising till end of the array b) rising slope will encounter a lesser element and go down.
In both scenarios, we will have an answer. In a) the answer is the end element because we take the boundary as -INFINITY b) the answer is the largest element before the slope falls.
​
**what if both the surrounding elements are greater than the mid element?
What if the part of the array you rejected, had a peak element and the part you selected on the basis of "promising nature" did not have a peak element?**
the definition of "peak value" in classical explanation of this approach is    a<=b>=c. Please refer to this ->  https://www.youtube.com/watch?v=HtSuA80QTyo . So, With this definition
1. you can go in either of directions if they are both greater. Both the directions are bound to find 'a' peak.
2. You will always find 'a' peak in the direction you chose ( if the definition of peak is  a<=b>=c)
​
**why checking for nums[0] and nums[n-1] in adv?**
The array could be strictly increasing or strictly decreasing and as we have to return any of the possible peaks, so we could add a condition to check whether the 1st element/last element could be the peak ). This point is also supported by the fact that, we are looking for mid-1/ mid+1 ( and these indices are compremised for 0th index / n-1 th index respectively.
​
​