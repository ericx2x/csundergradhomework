/**
 * Factorial class:
 * This class is basically the answer to the OOSDUJ HW problem 4.1. <br>
 * It computes the Factorial of a command line argument. <br>
 * n! = n(n-1)!
 * @author Zori Babroudi
 */
public class Factorial {
  
  /**
   * The main function.
   * @param args an int to take the factorial of.
   */
  public static void main (String[] args) {
   
    int n = Integer.parseInt(args[0]);  
    int temp = n;
    
    for (int i = 1; i < n-1; i++)   
      temp = temp *(n-i);  
    
    System.out.println(n + "! = " + temp);
    
  }
  
}
      
      