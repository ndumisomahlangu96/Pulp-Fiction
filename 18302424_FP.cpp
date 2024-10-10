/*
18302424
PROGRAM: 18302424_FP.cpp
Written by Kutlwano Ndumiso Mahlangu

The program will read the captured data from the file and, using appropriate
methods and functions, analyse trends, calculate averages, identify peak
traffic times, and generate a report to assist road planners in making
informed decisions about the future road development. You may use any of the 
functions or methods we have studied throughout the year in this project,
but you must include comments in your code explaining each step and your
reasoning for choosing specific methods or functions.
*/
// header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <numeric> // For std::accumulate
using namespace std;

/*
Function to calculate the average speed of vehicles: Display the average speed
of vehicles passing over the specified period.
*/
double CalculateAverageSpeed(const vector<double> &speeds)
{
    if (speeds.empty())
    {
        cerr << "Error: The vector is empty." << endl;
        return 0.0; // Return 0 if the vector is empty.
    }

    double sum = 0.0;
    for (double num : speeds)
    {
        sum += num; // Sum all the doubles in the vector.
    }

    // Calculate the average by dividing the sum by the vector size.
    return (sum / speeds.size());    
}

/*
Function to calculate the speed ranges: Categorize vehicle speeds (e.g.,slow, medium,
fast) and report on how many falls into each category.
*/
void SpeedRange(const vector<double> &speeds, int &slow, int &medium, int &fast)
{
    if (speeds.empty())
    {
        cerr << "Error: The vector is empty." << endl;
    }

    // For loop to categorize vehicle speeds (e.g. slow, medium, fast) stored in speed vector.
    for (int i = 0; i < speeds.size(); i++)
    {
        if ((0.0 < speeds[i]) && (speeds[i] <= 30.0))
        {
            slow = slow + 1;
        }
        else if ((30.0 < speeds[i]) && (speeds[i] <= 60.0))
        {
            medium = medium + 1;
        }
        else if (60.0 < speeds[i])
        {
            fast = fast + 1;
        }
    }
}

/*
Function splitTimeStamps that takes the vec_timeStamps and
splits each element based on the delimiters '-' and ' '.
*/
void SplitTimeStamps(const vector<string> &vec_timeStamps,
                     vector<int> &vec_years,
                     vector<int> &vec_months,
                     vector<int> &vec_days,
                     vector<string> &vec_times)
{
    for (const auto& timeStamp : vec_timeStamps)
    {
        stringstream ss(timeStamp);
        string yearStr, monthStr, dayStr, timeStr;
        int yearInt, monthInt, dayInt;

        // Split by '-' for year, month, and day.
        getline(ss, yearStr,'-');
        yearInt = stoi(yearStr);
        getline(ss,monthStr,'-');
        monthInt = stoi(monthStr);
        getline(ss,dayStr,' ');
        dayInt = stoi(dayStr);  // Split by space to separate date from time.
        getline(ss,timeStr);    // Remainder is the time part.
        

        // Add parts to the respective vectors.
        vec_years.push_back(yearInt);
        vec_months.push_back(monthInt);
        vec_days.push_back(dayInt);
        vec_times.push_back(timeStr);
    }    
}

/*
Function VehicleType categorize each vehicle type(e.g., cars, buses, bikes)
*/
void VehicleType(const vector<string> &vec_vehicles, 
                vector<string> &vec_cars,
                vector<string> &vec_buses,
                vector<string> &vec_motorbikes,
                vector<string> &vec_trucks)
{
    string temp_vehicle;
    for (int i = 0; i < vec_vehicles.size(); i++)
    {
        temp_vehicle = vec_vehicles[i];
        if (temp_vehicle == "CAR")
        {
            vec_cars.push_back(temp_vehicle);
        }
        else if (temp_vehicle == "BUS")
        {
            vec_buses.push_back(temp_vehicle);
        }
        else if (temp_vehicle == "MOTORCYCLE")
        {
            vec_motorbikes.push_back(temp_vehicle);
        }
        else
        {
            vec_trucks.push_back(temp_vehicle);
        }              
    }    
}

/*
Function VehiclePercentage calculates the percentage of each vehicle type.
*/
double VehiclePercentage(int num_vehicle, int total_vehicle) 
{
    // Handle the case when total_vehicle is zero to avoid division by zero
    if (total_vehicle == 0) {
        std::cerr << "Error: total_vehicle cannot be zero." << std::endl;
        return 0.0;
    }
    
    // Calculate the percentage
    double percentage = (static_cast<double>(num_vehicle) / total_vehicle) * 100;
    return percentage;
}

/*
Definition of function DisplayVehicleMenu. This function displays the user's menu on the screen.
*/
void DisplayVehicleMenu()
{
    cout << "\nVehicle Type-Specific Report:";
    cout << "\n-----------------------------";
    cout << "\n\tVEHICLE MENU\n";
    cout << "-----------------------------\n";
    cout << "A) CARS\n";
    cout << "B) BUSES\n";
    cout << "C) MOTORBIKES\n";
    cout << "D) TRUCKS\n";
    cout << "E) Exit the program\n\n";
    cout << "Enter your choice(A,B,C,D,E): ";   
}

// Main driver program.
int main()
{
    // File input.
    ifstream file("trafficdata.txt");

    // Vectors to store the separated data.
    vector<string> vec_timeStamps;
    vector<string> vec_vehicles;
    vector<double> vec_speeds;

    // Variables to categorize vehicle speeds.
    int speed_slow = 0;
    int speed_medium = 0;
    int speed_fast = 0;

    // Vectors to store the separated parts of timeStamps.
    vector<int> vec_years, vec_months, vec_days;
    vector<string> vec_times;

    // Vectors to store the different vehicle types.
    vector<string> vec_cars, vec_buses, vec_motorbikes,vec_trucks;

    // Variables to store vehicle count.
    int num_cars = 0;
    int num_buses = 0;
    int num_motorbikes = 0;
    int num_trucks = 0;
    int num_total_vehicles = 0;
    
    // Variable to store vehicle menu selection.
    char choice;

    // Check if the file opened successfully.
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    // String to store each line from the file.
    string line;

    // Skip the first line with headers.
    getline(file, line);

    //Process the file line by line.
    while (getline(file, line))
    {
        stringstream ss(line);
        string timeStamp, vehicle, speedStr;

        // Use semicolon (;) as delimiter to split fields.
        getline(ss, timeStamp,';');
        getline(ss, vehicle,';');
        getline(ss,speedStr,';');

        // Convert speed string to integer.
        double speed = stod(speedStr);

        // Store in respective vectors.
        vec_timeStamps.push_back(timeStamp);
        vec_vehicles.push_back(vehicle);
        vec_speeds.push_back(speed);
    }
    // Close the file.
    file.close();

    cout << "\t\tWelcome to Highway traffic flow analyser" << endl;
    cout << setprecision(4);

    // Display output for Report 3. Speed Analysis Report.
    cout << "\nSpeed Analysis Report: " << endl;
    cout << "\n-----------------------" << endl;

    // Average speed of vehicles: Display the average speed of vehicles passing over the specified period.
    cout << "\nAverage speed: " << CalculateAverageSpeed(vec_speeds) << " km/h" << endl;

    // Speed ranges: Categorize vehicle speeds and report on how many falls into each category.
    SpeedRange(vec_speeds,speed_slow,speed_medium,speed_fast);
    cout << "\nSpeed distribution: " << endl;
    cout << "\n-Slow (0-30 km/h): " << speed_slow << " vehicles" << endl;
    cout << "\n-Medium (30-60 km/h): " << speed_medium << " vehicles" << endl;
    cout << "\n-Fast (60+ km/h): " << speed_fast << " vehicles" << endl;
    
    // Call the function to split the timestamps.
    SplitTimeStamps(vec_timeStamps, vec_years, vec_months, vec_days, vec_times);

    // Map to store the vehicle count of each day.
    map<int, int> vehicleCount;

    // Loop through vec_days and count the number of vehicles passing per day.
    for (int vehicle : vec_days)
    {
        vehicleCount[vehicle]++;
    }

    // Display output for Report 1. Traffic Summary Report.
    cout << "\nTraffic Summary Report: " << endl;
    cout << "\n------------------------" << endl;

    // Total vehicles: The total number of vehicles recorded over the specified period.
    cout << "\nTotal vehicles: " << vec_days.size() << endl;

    // Vehicle count per day: A breakdown of the number of vehicles passing per day.
    for (const auto& entry : vehicleCount)
    {
        cout << "Day " << entry.first << ": " << entry.second << endl;
    }

    // Call the function to count the number and percentage of each vehicle type.
    VehicleType(vec_vehicles,vec_cars,vec_buses,vec_motorbikes,vec_trucks);

    num_total_vehicles = vec_vehicles.size();
    num_cars = vec_cars.size();
    num_buses = vec_buses.size();
    num_motorbikes = vec_motorbikes.size();
    num_trucks = vec_trucks.size();

    cout << "\nVehicle distribution: "  << endl;
    cout << "\n-Cars: " << num_cars << " (" << VehiclePercentage(num_cars,num_total_vehicles)  << "%)" << endl;   
    cout << "\n-Buses: " << num_buses << " ("  << VehiclePercentage(num_buses,num_total_vehicles) << "%)" << endl;   
    cout << "\n-Motorbikes: " << num_motorbikes << " (" << VehiclePercentage(num_motorbikes,num_total_vehicles) << "%)" << endl;
    cout << "\n-Trucks: " << num_trucks << " (" << VehiclePercentage(num_trucks,num_total_vehicles) << "%)" << endl;  

    // Display output for Report 6. Vehicle Type-Specific Report.
    do
    {
        // Variable to store specific vehicle type.
        string temp_vehicle;

        // Variable to store specific vehicle speed.
        double temp_speed;

        // Variable to store the summation of speed for a specific vehicle.
        double sum_vehicle_speeds = 0;

        // Variable to store the average speed for a specific vehicle.
        double vehicle_average_speed = 0;

        // Variable to store the summation of vector vehicle speeds.
        double sum_speeds = 0;

        // Display the vehicle menu and get a valid selection.
        DisplayVehicleMenu();
        cin >> choice;
        while ((toupper(choice) < 'A') || (toupper(choice) > 'E'))
        {
            cout << "\nPlease make a choice in the range of A through E.";
            cout << "\nEnter your choice: " << endl;
            cin >> choice;
        }

        // Process the user's vehicle menu selection.
        switch (choice)
        {
        // Vehicle report for cars.
        case 'a':
        case 'A':
            cout << "\nTotal cars: " << num_cars << endl;

            // Loop through the vector vehicle to calculate summation of different values of speed for cars.
            for (int i = 0; i < num_cars; i++)
            {
                temp_vehicle = vec_vehicles[i];     // Store vehicle type

                // Check if the variable is a car
                if (temp_vehicle == "CAR")
                {
                    temp_speed = vec_speeds[i];     // Get the speed of the car
                    sum_vehicle_speeds += temp_speed;   // Add to total sum
                }
            }

            // Calculate the average speed for cars. 
            // Add speeds all together and divide by the amount of cars.
            vehicle_average_speed = sum_vehicle_speeds / num_cars;
            cout << "\nAverage speed: " << vehicle_average_speed << " km/h" <<  endl;
            
            break;
        
        // Vehicle report for buses.
        case 'b':
        case 'B':
            cout << "\nTotal buses: " << num_buses << endl;

            // Loop through the vector vehicle to calculate summation of different values of speed for buses.
            for (int i = 0; i < num_buses; i++)
            {
                temp_vehicle = vec_vehicles[i];     // Store vehicle type

                // Check if the vehicle is a bus.
                if (temp_vehicle == "BUS")
                {
                    temp_speed = vec_speeds[i];     // Get the speed of the car
                    sum_vehicle_speeds += temp_speed;   // Add to total sum
                }
                
            }

            // Calculate the average speed for buses. 
            // Add speeds all together and divide by the amount of buses.
            vehicle_average_speed = sum_vehicle_speeds / num_buses;
            cout << "\nAverage speed: " << vehicle_average_speed << " km/h" << endl;
            
            break;

        // Vehicle report for Motorbikes.
        case 'c':
        case 'C':
            cout << "\nTotal motorbikes: " << num_motorbikes << endl;

            // Loop through the vector vehicle to calculate summation of different values of speed for motorbikes.
            for (int i = 0; i < num_motorbikes; i++)
            {
                temp_vehicle = vec_vehicles[i];     // Store vehicle type

                // Check if the vehicle is a motorcycle.
                if (temp_vehicle == "MOTORCYCLE")
                {
                    temp_speed = vec_speeds[i];     // Get the speed of the car
                    sum_vehicle_speeds += temp_speed;   // Add to total sum
                }
                
            }

            // Calculate the average speed for motorbikes. 
            // Add speeds all together and divide by the amount of motorbikes.
            vehicle_average_speed = sum_vehicle_speeds / num_motorbikes;
            cout << "\nAverage speed: " << vehicle_average_speed << " km/h" << endl;

            break;

        // Vehicle report for Trucks.    
        case 'd':
        case 'D':
            cout << "\nTotal trucks: " << num_trucks << endl;

            // Loop through the vector vehicle to calculate summation of different values of speed for trucks.
            for (int i = 0; i < num_trucks; i++)
            {
                temp_vehicle = vec_vehicles[i];     // Store vehicle type

                // Check if the vehicle is a truck.
                if (temp_vehicle == "TRUCK")
                {
                    temp_speed = vec_speeds[i];     // Get the speed of the truck
                    sum_vehicle_speeds += temp_speed;   // Add to total sum
                }
                
            }

            // Calculate the average speed for trucks. 
            // Add speeds all together and divide by the amount of trucks.
            vehicle_average_speed = sum_vehicle_speeds / num_trucks;
            cout << "\nAverage speed: " << vehicle_average_speed << " km/h" << endl;

            break;
        }
        
    } while (toupper(choice) != 'E');
    cout << "\nClosing Highway traffic flow analyser" << endl;
    return 0;
}