# **2048**

## Assignment for "Software Engineering" at Imperial College London department of Electrical and Electronic Engineering.

---

[//]: # (Images)

[image1]: ./images/Image1.png "Image 1"
[image2]: ./images/Image2.png "Image 2"
[image3]: ./images/Image3.png "Image 3"
[image4]: ./images/Image4.png "Image 4"
[image5]: ./images/Image5.png "Image 5"
[image6]: ./images/Image6.png "Image 6"
[image7]: ./images/Image7.png "Image 7"
[image8]: ./images/Image8.png "Image 8"


**2048**

The purpose of the assignment is to recreate the famous game 2048 in C++.

Report:

“2048” Assignment Overview/Basic Idea

For the assignment, I used one 4x4 array of integer elements (one 4 array with element pointers to 4 integer arrays). I am defining the size of my array making it applicable for other dimensions as well.

The basic idea behind my implementation for additions involves two steps:
1) To swift all elements and eliminate zeros in between.
2) To do possible additions starting from the start of the array.

Since these steps are common for every direction I wrote the functions based on one direction (left) and I rotated the array for the other directions to match this.

Variables and Structures Used
I used a data z structure zero_points to create points where a zero has been found. I used a data structure with member variables:

![image1]

a is our basic 4x4 array which is our game output, b is used as a buffer array to rotate elements and do possible changes. Zero_founded variable is used to determinate if we have zeros on our table, can_create in order to check if we can move on the table or the game is over, won in order to check if the user won and created if a new element was created. Finally, message is the final message to the user either “won” or “lost”. The check variable is used in order to avoid Move function do addition but just check for possible additions when no zeros are on the table.

![image2]

Member Functions

1) void Constructor()
This is function creates my 4x4 table which is either from 2048.txt text file and if it can not find it creates the default (All elements zero except the a[3][3] which is 2).

2) void Show()
This function displays the current state of my 4x4 table.

3) void Zero_founder()
This function checks if there is a zero element on my table.

4) void Prob_Creator()
This function creates a random 2 element on my table if a zero element has been found. It creates elements of zero_points structure and puts them into an array. After that randomly chooses one and makes it a zero.

5) bool Possible()
This function checks if a move can be done on my 4x4 table given my current state.

6) void Rotation()
This function makes the necessary rotation of the table as it is described in the next section.

7) void Gravity ()
This function swifts all elements and eliminates zeros in between.

8) bool Move()
This function does possible additions starting from the start of the array. It also checks for winner of the game.

Gravity / Rotation
The Gravity function is designed to swift all elements to the left and eliminates possible not needed zeros in between. It passes through the one-dimensional table three times. Every time, it checks every element with the next, starting from the start of the array. If the element is zero and the next element is not zero element then we swap the elements of the table. For instance,

![image3]

![image4]

The Rotation function rotates one line of my 4x4 table (row or column) as it was supposed to move on the left. Then the Gravity and Move functions do the swift and the additions. More specifically,

Right Direction b[k]=a[row][3-k];

![image5]


Up Direction b[k]=a[k][column];

![image6]

![image7]

![image8]

---


