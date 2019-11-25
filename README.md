# MAC-Protocol-Simulator
developed and used a simple discrete-event simulation for the performance analysis of network protocols.



______________________________________________________________________________________________________________________________

to compile: 

gcc jumpingBozons.c -lm

to run: 

./jumpingBozons.out


To run my program you must first configure the M, S, Y value at the top. They are defined as global variables. Then you compile and run. The program will print out the appropriate results to the console.
I did all my testing on my MacBook Pro, and everything seems to be working correctly. You may change the seed which is also defined as a global variable at the top of the code. This will slightly change the values derived as the seed is used to derive the random amount of time the Bozons will be Yodelling for and sleeping for. To test I used the values M = 10, S = 50.000, and Y = 25.000, and compared it to the values that were given to us. All values were off by less then 0.5% and I believe this is due to the seed I was using. If the same seed is used I believe the same values will be achieved. 

# Example input/output

#### Ex 1
M: 5, S: 100.000000, and Y: 10.000000
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 62.544813
Total percentage of time one person Yodelling (melodious): 30.623692
Total percentage of time Screeching: 6.832130
Number of attempted yodels: 45346
Percentage of attempted yodels that were perfect: 58.230054


#### Ex 2
The optimal colony size M when S = 100.0 and Y = 10.0 is: 

M: 10, S: 100.000000, and Y: 10.000000
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 38.388037
Total percentage of time one person Yodelling (melodious): 38.733011
Total percentage of time Screeching: 22.880305
Number of attempted yodels: 91290
Percentage of attempted yodels that were perfect: 31.283820



#### Ex 3
M: 5 and S: 100.000000.
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 61.852509
Total percentage of time one person Yodelling (melodious): 31.125091
Total percentage of time Screeching: 7.023006
Number of attempted yodels: 45877
Percentage of attempted yodels that were perfect: 56.448764


In this case the total melodious time was slightly higher than when the time yodelling was derived from random exponentially distributed duration. However the total screeching time was also higher while the percentage of perfect yodels was lower. All the values are only slightly off from one another. I believe the difference is so small that is negligible. 

#### Ex 4
The optimal colony size M, when S = 100.0 is: 

M: 11 and S: 100.000000.
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 35.048184
Total percentage of time one person Yodelling (melodious): 38.512222
Total percentage of time Screeching: 26.439750
Number of attempted yodels: 100105
Percentage of attempted yodels that were perfect: 26.282403

This is different from before as the optimal colony size is 11 instead of 10 and the melodious percentage has went up to 38.512222%, which is a very small difference from before. Again I feel that the difference between the values are very small. 


