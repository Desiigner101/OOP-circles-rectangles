import java.text.DecimalFormat;
import java.util.*;

public abstract class Shape {
    Scanner scan = new Scanner(System.in);
    DecimalFormat df = new DecimalFormat("0.00");

    protected double radius, length, width;
    boolean isEnabled = true;

    public abstract double getArea();
    public abstract double getPerimeter();

    public void calculateForCircle() {
        Circle calculateCircle = new Circle(0.0); 

        while (isEnabled) {
            try {
                System.out.print("Enter the radius of the circle: ");
                radius = scan.nextDouble();
                calculateCircle.setRadius(radius); 
                isEnabled = false;
            } catch (InputMismatchException e) {
                System.out.println("Invalid radius input... Please select a valid option.");
                scan.nextLine(); 
            }
        }

        double resultArea = calculateCircle.getArea();
        double resultPerimeter = calculateCircle.getPerimeter();
        System.out.println("Circle:");
        System.out.println("Area: " + df.format(resultArea));
        System.out.println("Perimeter: " + df.format(resultPerimeter));
    }

    public void calculateForRectangle(){
        Rectangle calculateRectangle = new Rectangle(0.0, 0.0);

        while(isEnabled){
            try{
            System.out.print("Enter the length of the rectangle: ");
            length = scan.nextDouble();
            calculateRectangle.setLength(length);
            isEnabled = false;
            }catch(Exception e){
                System.out.println("Invalid length input... Please enter a double input");
                scan.nextLine();
            }
        }

        while(!isEnabled){
            try{
            System.out.print("Enter the width of the rectangle: ");
            width = scan.nextDouble();
            calculateRectangle.setWidth(width);
            isEnabled = true;
            }catch(Exception e){
                System.out.println("Invalid width input... Please enter a double input");
                scan.nextLine();
            }
        }
            double rectArea = calculateRectangle.getArea();
            double rectPerimeter = calculateRectangle.getPerimeter();
            System.out.println("Rectangle:");
            System.out.println("Area: " + df.format(rectArea));
            System.out.println("Perimeter: " + df.format(rectPerimeter));
    }
}