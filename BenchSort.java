import java.util.Arrays;
import java.lang.*;
import java.util.Random;

class BenchSort {
  public static void main(String[] args){
    int len = Integer.parseInt(args[0]);
    int iterations = Integer.parseInt(args[1]);
    for (int i = 0; i < iterations; i++) {
      sort(len, i);
    }
  }

  public static void sort(int len, long seed) {
    int[] iArr = new int[len];
    Random random = new Random(seed);

    for (int i = 0; i < len; i++) {
      iArr[i] = random.nextInt();
      if (i < 5) {
        System.out.print(iArr[i] + " ");
      } 
    }
    
    System.out.println("Sorting array with len: " + new Integer(len));

    long preExecTime = System.nanoTime();
    Arrays.sort(iArr);
    long postExecTime = System.nanoTime();
    System.out.println("Takes: " + new Double((postExecTime - preExecTime)/1000000.0) + "ms");
  }
}

