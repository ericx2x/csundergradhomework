/**
 * MyTurtle Class:
 * This class extends the parent class Turtle.
 * It basically answers MediaBook HW problems 3.11 - 3.14.
 * @author Zori Babroudi
 */
public class MyTurtle extends Turtle {
  
  /** xPos default center x. */
  private int xPos = 240;
  
  /** yPos default center y. */
  private int yPos = 320;
 
  /**
   * MyTurtle default constructor.
   * @param x xPos for parent class Turtle.
   * @param y yPos for parent class Turtle.
   * @param w ModelDisplay for parent class Turtle.
   */
  public MyTurtle (int x, int y, ModelDisplay w) {
    
    super (x, y, w);
    xPos = x;
    yPos = y;
    
  }
  
  /**
   * MyTurtle default constructor.
   * Places the turtle in the default position.
   * @param w ModelDisplay for parent class Turtle.
   */
  public MyTurtle (ModelDisplay w) {
    
    super (w);
    
  }
  
  /**
   * Rectangle drawing function. This function creates
   * a rectangle with the turtle.
   * @param width the width of the rectangle you wish to draw.
   * @param height the height of the rectangle you wish to draw.
   */
  public void drawRectangle (int width, int height) {
  
    for (int i = 0; i < 2; i++) {
          
    forward(height);
    turnRight();
    forward(width);
    turnRight();
    
    }
  
  }

  /**
   * Hexagon drawing function. This function creates
   * a hexagon with the turtle.
   * @param sideLength the length of the side of the hexagon.
   */
  public void drawHexagon (int sideLength) {
   
    for (int i =0; i < 6; i++) {
          
      forward(sideLength);
      turn(60);
    
    }
  
  }
  
  /**
   * Pentagon drawing function. This function creates
   * a pentagon with the turtle.
   * @param sideLength the length of the side of the pentagon.
   */
  public void drawPentagon (int sideLength) {
   
    
    for (int i=0; i < 5; i++) {
      
      turn(72);
      forward(sideLength);
    
    }
    
  }
  
  /**
   * Triangle drawing function. This function creates
   * an equilateral triangle with the turtle.
   * @param sideLength the length of the side of the triangle.
   */
  public void drawTriangle (int sideLength) {
      
      turn(30);
      forward(sideLength);
      turn(90 + 30);
      forward(sideLength);
      turn(90 + 30);
      forward(sideLength);
      turnRight();
    
  }
     
}//end class MyTurtle