https://cs50.harvard.edu/x/2024/practice/atoi/

Learning Goals
Deepen an understanding of strings
Practice creating recursive functions

Background
Imagine that you travel back in time to the 1970’s, when the C programming language was first created. You are hired as a programmer to come up with a way to convert strings to ints. (You may have used a function just like this in Week 2, called atoi). You want to be thorough in your development process and plan to try several approaches before deciding on the most efficient.

In this problem, you will start with a simple implementation of atoi that handles positive ints using loops. You want to rework this into an implementation that uses recursion. Recusive functions can be memory intensive and are not always the best solution, but there are some problems in which using recursion can provide a simpler and more elegant solution.

(Scroll to the bottom of this page to see what an implementation of atoi might actually look like.)

Hints
Start by getting the index of the last char in the string (the char before the \0).
Convert this char into its numeric value. Can you subtract some char to do this?
Remove the last char from the string by moving the null terminator one position to the left.
Return this value plus 10 times the integer value of the new shortened string.
Remember you need a base case when creating a recursive function.
