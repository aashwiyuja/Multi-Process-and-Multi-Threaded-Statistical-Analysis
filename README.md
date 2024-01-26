# Multi-Process and Multi-Threaded Statistical Analysis

This repository contains two Java and C codes that demonstrate the computation of various statistical measures concurrently using multi-process and multi-threading approaches. The programs aim to calculate the average, minimum, maximum, and median values of a given set of numbers.

## Multi-Process Statistical Analysis (C Code)

### Code Structure

- **Main Process:**
  - Accepts user input for the total number of input values and the values themselves.
  - Spawns four child processes, each responsible for a specific statistical measure: minimum, maximum, average, and median.
  - Uses inter-process communication through pipes to collect the results.
  - Prints the calculated statistical measures.

### Usage

1. Compile and execute the C code.
2. Enter the total number of input values.
3. Input the desired numbers.

## Multi-Threaded Statistical Analysis (Java Code)

### Code Structure

- **Thread Classes:**
  1. `AverageThread`: Calculates the average value of the array.
  2. `MinimumThread`: Finds the minimum value in the array.
  3. `MaximumThread`: Finds the maximum value in the array.
  4. `MediumThread`: Computes the median value of the array.

- **Main Class (`multi_thread`):**
  - Prompts the user to enter the total number of input values and the input values.
  - Creates instances of the four thread classes.
  - Starts all threads concurrently.
  - Uses the `join` method to ensure that the main thread waits for all threads to complete.
  - Prints the calculated average, minimum, maximum, and median values.

### Usage

1. Compile and execute the Java code.
2. Enter the total number of input values.
3. Input the desired numbers.

## Note

Feel free to explore and experiment with different input values to observe how multi-process and multi-threading enhance the efficiency of statistical calculations. These examples showcase the parallelization of computations to improve overall performance.
