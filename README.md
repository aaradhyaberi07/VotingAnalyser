# VotingAnalyser
A Voting System that finds the optimum distribution using Graph Theory and 2-SAT while ensuring that the choices of the parties are considered

# Goal
Let us assume we have n families and m choices and we take 2 choices from each family to include or exclude any 2 options:
   - '+' Option1 '-' Option2 which means to include Option1 and to exclude Option2
   - '+' Option1 '+' Option2 which means to include Option1 and to include Option2
   - '-' Option1 '-' Option2 which means to exclude Option1 and to exclude Option2
   - '-' Option1 '+' Option2 which means to exsclude Option1 and to include Option2
   

The goal is to develop an algorithm which finds such a distribution of choices such that the number of families with not
even 1 choices reflected in the final distribution are minimized, or in other words the number of 'unhappy' families are minimized.
Thus the goal is to develop an algorithm which solved this problwm in Polynomial time.
The naive eay of doing this leads to a Time Complexity of O(n.2^m) which is exponential and hence useless for real life applications.
I have reduced the time complexity to O(n+m) which produces a result within 1s for n and m ranging up to 10^7
