// Tampugao, MOHAMMAD MURAYA - Dalion ,Adrian
//  Contribution: No specifications, help each other
//This program demonstrates how to model a simple car management system using OOP principles, allowing for flexible representation and manipulation of different types of vehicles.


import java.util.Scanner;

// Parent class Car
class Car {

    // These are Encapsulated fields preventing direct manipulation of such fields
    private String brand;
    private String model;
    private int year;
    private String color; 

    // Constructor, use for initialization of newly created objects. 
    public Car(String brand, String model, int year, String color) 
    {
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.color = color;
    }

    // Getter methods: allow controlled access to the private data. 
    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public int getYear() {
        return year;
    }

    public String getColor() { 
        return color;
    }

    // Method overloading for displayDetails to include or exclude color
    public void displayDetails(boolean includeColor) {
        System.out.println("Brand: " + brand);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
        if(includeColor) {
            System.out.println("Color: " + color); 
        }
    }

    // Original displayDetails method
    public void displayDetails() 
    {
        displayDetails(true); // Call the overloaded method with default parameter value
    }
}

// Child class SUV inheriting the fields of Car
class SUV extends Car {
    
    private boolean hasSunRoof;

    // Constructor
    public SUV(String brand, String model, int year, String color, boolean hasSunRoof) 
    {
        super(brand, model, year, color); // super is use to explicitly call the superclass 'Car'
        this.hasSunRoof = hasSunRoof;
    }

    // Method overriding has been utilized to modify the 'displayDetails()' and be able to add the hasSunRoof
    @Override
    public void displayDetails() 
    {
        super.displayDetails(); // super is use to explicitly cally the super calass
        System.out.println("Sun-roof: " + (hasSunRoof ? "Yes" : "No"));
    }
}

public class Dalion_Tampugao_PE06 {
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in); // for input

        // User input for car details

        System.out.println("Enter details for a car:");
        System.out.print("Brand: ");
        String brand = scanner.nextLine();
        System.out.print("Model: ");
        String model = scanner.nextLine();
        System.out.print("Year: ");
        int year = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Color: ");
        String color = scanner.nextLine(); 


        // Create a regular car object
        Car regularCar = new Car(brand, model, year, color);
        

        // User input of SUV details
        System.out.println("\nEnter details for an SUV:");
        System.out.print("Brand: ");
        brand = scanner.nextLine();
        System.out.print("Model: ");
        model = scanner.nextLine();
        System.out.print("Year: ");
        year = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Color: ");
        color = scanner.nextLine(); 
        System.out.print("Sun-roof (true/false): ");
        boolean hasSunRoof = scanner.nextBoolean();

        // This create an SUV object
        SUV suv = new SUV(brand, model, year, color, hasSunRoof);

        // This display  the details of both vehicles
        System.out.println("\nDetails of the car:");
        regularCar.displayDetails();

        System.out.println("\nDetails of the SUV:");
        suv.displayDetails();

        scanner.close();
    }
}
