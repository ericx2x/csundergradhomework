/** MyTurtle_Tester class.<br>
  * This tests MyTurtle class functions.
  * @author Zori Babroudi
  */
public class MyTurtle_Tester {
  
  /**
   * Main function. This tests all three functions I wrote to answer 
   * Media HW questions 3.11(drawRectangle), 3.12(drawHexagon), 3.13(drawPentagon), 3.14(drawTriangle).
   */
  public static void main (String[] args) {
    
    World myWorld = new World(); //create the world for the turtles.
    
    //Tests 3.11 (drawRectangle).
    MyTurtle mr = new MyTurtle (100, 200, myWorld);
    mr.drawRectangle (40 ,100);
    
    //Tests 3.12 (drawHexagon).
    MyTurtle mh = new MyTurtle (200, 200, myWorld);    
    mh.drawHexagon (40);
    
    //Tests 3.13 (drawPentagon).
    MyTurtle mp = new MyTurtle (300, 200, myWorld);
    mp.drawPentagon (40);
    
    //Tests 3.14 (drawTriangle).
    MyTurtle mt = new MyTurtle (400, 200, myWorld);
    mt.drawTriangle (40);
        
    }
  
}