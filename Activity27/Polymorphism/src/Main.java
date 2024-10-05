import java.util.*;

public class Main {  
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        boolean isEnabled = true;
        int choice; 
        String newChoice;

        Shape getCircle = new Circle(0.0);
        Shape getRectangle = new Rectangle(0.0, 0.0);

        while (isEnabled) {
            try {
                System.out.println("Please select a shape, press:");
                System.out.println("1. Circle");
                System.out.println("2. Rectangle");
                System.out.print("\nEnter your choice: ");
                choice = scan.nextInt();
            } catch (Exception e) {
                System.out.println("Invalid choice! Please select a valid option.");
                scan.nextLine();  
                continue;  
            }

            switch (choice) {
                case 1 -> getCircle.calculateForCircle();

                case 2 -> getRectangle.calculateForRectangle();
                default -> {
                    System.out.println("Invalid choice. Please try again.");
                    continue; 
                }
            }
            scan.nextLine();
            System.out.print("\nWould you like to draw another shape? (YES/NO): ");
            newChoice = scan.nextLine();

            if (newChoice.equalsIgnoreCase("YES")){
                isEnabled = true;
            } else {
                System.out.println("Goodbye!");
                isEnabled = false;
            }
        }
        scan.close();  
    }
}