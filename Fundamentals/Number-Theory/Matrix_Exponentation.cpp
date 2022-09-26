/*
We know Fibonacci sequence is given by:
f(n)= f(n-1)+f(n-2);
where f(1) = f(2) = 1; // base case
So by matrix multiplication properties we can write it as:
|f(n)|    =  |1 1| |f(n-1)|
                   |f(n-2)|
also we can write it as:
|f(n)|    =  |1 1| |f(n-1)|
|f(n-1)|     |1 0| |f(n-2)|
// here f(n-1) is utility added so caluclation become easy the overall equation remain balanced.Upper term gives f(n) and lower term gives f(n-1)

Let us take n=5
|f(5)|    =  |1 1| |f(4)|
|f(4)|       |1 0| |f(3)|

Let us take n=4
|f(4)| = |1 1| |f(3)|
|f(3)|   |1 0| |f(2)|

Let us take n=3
|f(3)| = |1 1| |f(2)|= |1 1| |1| // since f(2) = f(1) =1 base case
|f(2)|   |1 0| |f(1)|= |1 0| |1|


Substituting value of |f(3)| in |f(4)| We get: |f(4)| = |1 1| |1 1| |f(2)|
                      |f(2)|    |f(3)|         |f(3)| = |1 0| |1 0| |f(1)|
  
Substituting value of |f(4)| in |f(5)| We get: |f(5)|= |1 1| |1 1| |1 1| |f(2)|
                      |f(3)|    |f(4)|         |f(4)|= |1 0| |1 0| |1 0| |f(1)|
  
Taking t = |1 1|
           |1 0|
We can write it as :
|f(5)|= t^3 |f(2)|
|f(4)|      |f(1)|
  
So the general formula become:
|f(n)|  =   t^(n-2) |f(2)|
|f(n-1) =           |f(1)|
*/
