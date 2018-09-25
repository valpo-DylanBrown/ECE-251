This project taught students how to use arrays in C.
Question 1:
Please write a program that will:
  a. ask the user for an array size,
  b. create and fill that array with random numbers varying between 1 and 100, then
  c. calculate and display the
    i. mean
    ii. median, and
    iii. standard deviation
of the numbers in the array. The mean is the sum of all the values divided by the number of values. When the elements of the array have been sorted, the median is the middle value (if the array size is odd) or the average of the two middle values (if the array size is even). The standard deviation can be found from the following equation:
𝑛
𝑠=√ (1/(𝑛 − 1)∑(i=1,n)(𝑋𝑖−𝑋 ̅)^2) 
where s is the standard deviation, n is the number of data points, Xi are the individual datapoints, and 𝑋 is the mean of the data values.
Question 2: 
The electric field surrounding a single point charge can be calculated according to the following formula:
𝐸=𝑄/(4𝜋𝜀𝑅^2)
Where Q is the magnitude of the charge, R is the distance from the charge to the point being considered, and 𝜀 is a constant equal to 8.854x10-12 V-1C∙m-2.
Please write a program that will calculate the electric field at a series of points that lie on a square grid spaced 1cm apart. There is a 0.01nC charge at the very center of the grid, and the grid extends 4cm in each direction away from the charge.
You should use a two-dimensional array to solve this problem.
Please print the magnitude of the electric field at each point on the grid, each printed in
standard (non-scientific) notation with a minimum width of 5 digits and one digit to the right
of the decimal point. Since the electric field approaches infinity as the distance to the charge
approaches zero, you should print "-----" at the location corresponding to the location of the
charge.
