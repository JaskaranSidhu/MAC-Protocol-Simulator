# MAC-Protocol-Simulator
developed and used a simple discrete-event simulation for the performance analysis of network protocols.



______________________________________________________________________________________________________________________________

to compile: 

gcc jumpingBozons.c -lm

to run: 

./jumpingBozons.out


To run my program you must first configure the M, S, Y value at the top. They are defined as global variables. Then you compile and run. The program will print out the appropriate results to the console.
I did all my testing on my MacBook Pro, and everything seems to be working correctly. You may change the seed which is also defined as a global variable at the top of the code. This will slightly change the values derived as the seed is used to derive the random amount of time the Bozons will be Yodelling for and sleeping for. To test I used the values M = 10, S = 50.000, and Y = 25.000, and compared it to the values that were given to us. All values were off by less then 0.5% and I believe this is due to the seed I was using. If the same seed is used I believe the same values will be achieved. 

_______________________________________________________________________________________________________________________________
RESULTS:

M: 5, S: 100.000000, and Y: 10.000000
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 62.544813
Total percentage of time one person Yodelling (melodious): 30.623692
Total percentage of time Screeching: 6.832130
Number of attempted yodels: 45346
Percentage of attempted yodels that were perfect: 58.230054



The optimal colony size M when S = 100.0 and Y = 10.0 is: 

M: 10, S: 100.000000, and Y: 10.000000
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 38.388037
Total percentage of time one person Yodelling (melodious): 38.733011
Total percentage of time Screeching: 22.880305
Number of attempted yodels: 91290
Percentage of attempted yodels that were perfect: 31.283820



Table of results when: 

S: 200.000000, and Y: 10.000000
Total time observing channel: 1000000.000000
 _____________________________________________________________________________________________________________________________
|  M  | Idle Percentage | Melodious Percentage | Screeching Percentage | Total Attempted Yodels | Percentage of Perfect Yodels|
|_____________________________________________________________________________________________________________________________|
|  1  |    95.248662    |       4.763785       |        0.000000       |          4855          |           99.979401         |
|_____________________________________________________________________________________________________________________________|
|  2  |    90.639330    |       9.114510       |        0.248817       |          9653          |           92.996997         |
|_____________________________________________________________________________________________________________________________|
|  4  |    82.265026    |       16.464439      |        1.284401       |          19185         |           80.317956         |
|_____________________________________________________________________________________________________________________________|
|  8  |    67.637223    |       27.270037      |        5.093398       |          38274         |           61.783457         |
|_____________________________________________________________________________________________________________________________|
|  16 |    45.792484    |       36.676983      |        17.530755      |          76485         |           36.965418         |
|_____________________________________________________________________________________________________________________________|
|  32 |    21.102568    |       33.529621      |        45.368045      |         152695         |           14.369822         |
|_____________________________________________________________________________________________________________________________|
|  64 |    4.360258     |       14.013190      |        81.626611      |         305855         |           2.534534          |
|_____________________________________________________________________________________________________________________________|
| 128 |    0.184949     |       1.229162       |        98.585928      |         610481         |           0.096809          |
|_____________________________________________________________________________________________________________________________|

The highest melodious percentage achieved was 36.676983%, and it was achievied when M = 16.




BONUS: 


M: 5 and S: 100.000000.
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 61.852509
Total percentage of time one person Yodelling (melodious): 31.125091
Total percentage of time Screeching: 7.023006
Number of attempted yodels: 45877
Percentage of attempted yodels that were perfect: 56.448764


In this case the total melodious time was slightly higher than when the time yodelling was derived from random exponentially distributed duration. However the total screeching time was also higher while the percentage of perfect yodels was lower. All the values are only slightly off from one another. I believe the difference is so small that is negligible. 


The optimal colony size M, when S = 100.0 is: 

M: 11 and S: 100.000000.
Total time observing channel: 1000000.000000
Total percentage of time everyone was sleeping: 35.048184
Total percentage of time one person Yodelling (melodious): 38.512222
Total percentage of time Screeching: 26.439750
Number of attempted yodels: 100105
Percentage of attempted yodels that were perfect: 26.282403

This is different from before as the optimal colony size is 11 instead of 10 and the melodious percentage has went up to 38.512222%, which is a very small difference from before. Again I feel that the difference between the values are very small. 


Table of results:


S: 200.000000.
Total time observing channel: 1000000.000000
 _____________________________________________________________________________________________________________________________
|  M  | Idle Percentage | Melodious Percentage | Screeching Percentage | Total Attempted Yodels | Percentage of Perfect Yodels|
|_____________________________________________________________________________________________________________________________|
|  1  |    95.206034    |       4.809000       |        0.000000       |          4810          |           99.979210         |
|_____________________________________________________________________________________________________________________________|
|  2  |    90.560268    |       9.185428       |        0.255286       |          9697          |           91.863465         |
|_____________________________________________________________________________________________________________________________|
|  4  |    82.111263    |       16.604218      |        1.284869       |          19211         |           80.365413         |
|_____________________________________________________________________________________________________________________________|
|  8  |    67.483633    |       27.277597      |        5.241360       |          38323         |           60.222322         |
|_____________________________________________________________________________________________________________________________|
|  16 |    45.490395    |       36.897428      |        17.613024      |          76646         |           35.340396         |
|_____________________________________________________________________________________________________________________________|
|  32 |    20.815773    |       33.508753      |        45.675499      |         152917         |           13.216974         |
|_____________________________________________________________________________________________________________________________|
|  64 |    4.428498     |       13.990661      |        81.580842      |         305603         |           2.405735          |
|_____________________________________________________________________________________________________________________________|
| 128 |    0.189426     |       1.208739       |        98.601841      |         610386         |           0.098626          |
|_____________________________________________________________________________________________________________________________|

In this case we see that if you standardize the yodelling time, everything seems to be similar to when we were deriving the yodelling time randomly. The idle, melodious, screeching, and perfect yodel percentage all seem to be very similar.
Overall I believe everything stays similar whether we are using a standardized yodel time of 10.0 units, and when we are deriving our yodel time from a random floating point number exponentially distributed with mean = 10.0.   

