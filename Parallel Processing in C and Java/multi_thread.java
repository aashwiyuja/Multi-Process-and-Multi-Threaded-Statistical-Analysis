import java.util.Arrays;
import java.util.Scanner;

class AverageThread extends Thread {

  int[] arr;
  double average;

  AverageThread(int[] arr) {
    this.arr = arr;
  }

  public void run() {
    int total = 0;
    for (int i = 0; i < arr.length; i++) {
      total = total + arr[i];
    }

    average = total / arr.length;
  }
}

class MinimumThread extends Thread {

  int[] arr;
  int min;

  MinimumThread(int[] arr) {
    this.arr = arr;
  }

  public void run() {
    Arrays.sort(arr);
    min = arr[0];
  }
}

class MaximumThread extends Thread {

  int[] arr;
  int max;

  MaximumThread(int[] arr) {
    this.arr = arr;
  }

  public void run() {
    Arrays.sort(arr);
    max = arr[arr.length - 1];
  }
}

class MediumThread extends Thread {

  int[] arr;
  double median;

  MediumThread(int[] arr) {
    this.arr = arr;
  }

  public void run() {
    Arrays.sort(arr);

    if (arr.length % 2 == 0)
      median = ((double) arr[arr.length / 2] + (double) arr[arr.length / 2 - 1]) / 2;
    else median = (double) arr[arr.length / 2];
  }
}

class multi_thread {

  public static void main(String args[]) {

    Scanner s = new Scanner(System.in);
    System.out.println("Enter the total numbers of input values: ");
    int count = s.nextInt();
    System.out.println("Start entering your input numbers");

    int arr[] = new int[count];
    for (int i = 0; i < count; i++) {
      arr[i] = s.nextInt();
    }

    AverageThread averageThread = new AverageThread(arr);
    MinimumThread minimumThread = new MinimumThread(arr);
    MaximumThread maximumThread = new MaximumThread(arr);
    MediumThread mediumThread = new MediumThread(arr);

    averageThread.start();
    minimumThread.start();
    maximumThread.start();
    mediumThread.start();

    try {
      averageThread.join();
      minimumThread.join();
      maximumThread.join();
      mediumThread.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("The average value is " + averageThread.average);
    System.out.println("The minimum value is " + minimumThread.min);
    System.out.println("The maximum value is " + maximumThread.max);
    System.out.println("The medium value is " + mediumThread.median);
  }
}
