The C program will be passed a series of numbers on the command line and will then create four separate child worker processes. One process will determine the average of the numbers, the second will determine the maximum value, the third will determine the minimum value, and the fourth will determine the median value.

● The program input
90 81 78 95 79 72 85
● The program will output
    The average value is 82
    The minimum value is 72
    The maximum value is 95
    The medium value is 81
● The variables representing the average, minimum, maximum, and medium values are stored globally. The child processes will compute and set these values, and the parent process will output the values once the child processes have exited.
● Same has been implemented in Java too, it’s a multi-threaded program using Java threads. One challenge is Java does not have the notion of a global variable due to its object-oriented design.

Steps to compile and run:

1. Download & Unzip the folder in your machine
2. Open command prompt & navigate to the unzipped folder
3. Compiling Java program
       Type below command to compile the program
           javac multi_thread.java
       A class file is generated in same path once program is compiled successfully
       Type below command to run the program
           java multi_thread
4. Compiling C program
       Type below command to compile the program
           gcc -o multi_process multi_process.c
   An executable file is generated in same path once program is compiled successfully
       Type below command to run the program
           ./multi_process
