
// You are tasked with developing a
// program to manage the operations of a farm. The farm produces various types
// of crops, each with different characteristics. Your task is to create a
// program that models the farming process, tracks sales, and calculates
// relevant financial information.

// Task 1: Crop Class and
// Farm Operations

// a) Create a class named Crop with
// the following attributes:

// name (string): The name of the crop.
// area (float): The area of land (in acres)
// dedicated to growing this crop.
// yield_per_acre (float): The expected yield of
// the crop per acre (in kilograms).
// price_per_kg (float): The selling price of the
// crop per kilogram.

// Implement a method within the
// Crop class called calculate_revenue that calculates and returns the potential
// revenue generated from growing this crop based on the area and yield.

// b) Create a class named Farm with
// the following attributes:

// balance (float): The available funds for the
// farm.
// crops_grown (list of Crop objects): Crops that
// are currently grown on the farm.
// crops_sold (list of Crop objects): Crops that
// have been sold.

// Implement a method within the
// Farm class called grow_crop that takes a Crop object as an argument. This
// method should check if the farm has sufficient funds to grow the crop, update
// the balance, and add the crop to the list of crops grown.

// Task 2: Financial Analysis
// and Decisions

// a) Instantiate a Farm object with
// an initial balance of Rs 5000. Simulate growing 5 different crops with
// varying details (name, area, yield, price per kg). Assume that 2 out of these
// 5 crops have been sold.

// b) Implement a method within the
// Farm class called calculate_total_revenue that calculates and returns the
// total revenue generated from selling the crops.

// c) Implement a method within the
// Farm class called calculate_revenue_per_acre that calculates and returns the
// ratio of total revenue generated to the total area of land used for growing
// crops.

// d) Display the following
// information using appropriate methods and attributes of the Farm class:

// Total number of crops grown and sold.
// Area of land used for each crop.
// Total revenue generated from the sold crops.
// Ratio of revenue generated per total land area

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Crop {

public:
  string Name;
  float Area;
  float Price_Per_Kg;
  float Yield_Per_Acre;

  Crop(string name, float area, float price_per_kg, float yield_per_acre) {
    Name = name;
    Area = area;
    Price_Per_Kg = price_per_kg;
    Yield_Per_Acre = yield_per_acre;
  }

  float Calculate_Revenue() {
    float potential_revenue;
    potential_revenue = Area * Yield_Per_Acre * Price_Per_Kg;
    // cout << "Potential Revenue = " << potential_revenue << endl;
    return potential_revenue;
  }

  void display_crop() {
    cout << endl;
    cout << "Name = " << Name << endl;
    cout << "Area = " << Area << " acres" << endl;
    cout << "Yield Per Acre = " << Yield_Per_Acre << " Rupees" << endl;
    cout << "Price Per Kg = " << Price_Per_Kg << " Rupees" << endl;
    cout << endl;
  }
};

class Farm {
public:
  float Balance;
  vector<Crop> Crops_grown;
  vector<Crop> Crops_sold;

  Farm(float balance) { Balance = balance; }

  void show_balance() { cout << "Balance : " << Balance << endl; }

  void grow_crop(Crop new_crop) {
    if (Balance >= new_crop.Area * new_crop.Price_Per_Kg) {
      Crops_grown.push_back(new_crop);
      Balance = Balance - (new_crop.Area * new_crop.Price_Per_Kg);
      cout << "\nnew crop is grown " << endl;
      show_balance();
    }

    else {
      cout << "\ncrop cannot be grown !! " << endl;
      show_balance();
    }
  }

  float calculate_total_revenue() {
    float total_revenue = 0;
    for (int i = 0; i < Crops_sold.size(); i++) {
      total_revenue = total_revenue + Crops_sold[i].Calculate_Revenue();
    }
    // cout << "Total Revenue = " << total_revenue << endl;
    return total_revenue;
  }

  float calculate_revenue_per_acre() {
    float revenue_per_acre;
    float total_area = 0;

    for (int i = 0; i < Crops_grown.size(); i++) {
      total_area = total_area + Crops_grown[i].Area;
    }

    if (total_area > 0) {
      revenue_per_acre = calculate_total_revenue() / total_area;
      // cout << "Revenue per acre = " << revenue_per_acre << endl;
      return revenue_per_acre;
    }

    else {
      return 0;
    }
  }

  void display() {
    cout << endl;
    cout << "Total number of crops grown : " << Crops_grown.size() << endl;
    cout << "Total number of crops sold : " << Crops_sold.size() << endl;
    cout << "\n\ncrops grown list with area used : \n" << endl;
    for (int i = 0; i < Crops_grown.size(); i++) {
      cout << "Name = " << Crops_grown[i].Name
           << "  Area used : " << Crops_grown[i].Area << endl;
    }

    float total_revenue = calculate_total_revenue();
    std::cout << "\nTotal revenue generated from sold crops: " << total_revenue
              << std::endl;

    float revenue_per_acre = calculate_revenue_per_acre();
    std::cout << "Ratio of revenue generated per total land area: "
              << revenue_per_acre << std::endl;
    cout << endl;
  }
};

int main() {

  // Instantiate Crop objects and grow crops on the farm
  Crop crop1("Wheat", 10, 100, 2);
  // crop1.display_crop();
  Crop crop2("Corn", 8, 80, 1.5);
  Crop crop3("Rice", 15, 120, 3);
  Crop crop4("Barley", 5, 90, 2.2);
  Crop crop5("Soybean", 7, 70, 2.5);

  Farm farm(5000);
  farm.show_balance();
  farm.grow_crop(crop1);
  farm.grow_crop(crop2);
  farm.grow_crop(crop3);
  farm.grow_crop(crop4);
  farm.grow_crop(crop5);

  // Simulate selling 2 out of 5 crops
  farm.Crops_sold.push_back(crop1);
  farm.Crops_sold.push_back(crop3);

  // Display farm information
  farm.display();

  return 0;
}
