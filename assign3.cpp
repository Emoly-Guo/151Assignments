/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign3.cpp
 * 
 * Input: initial speed (in km/h)
 *        speed after 1 minute (in km/h)
 * Output: rate of deceleration (in m/s^2)
 *         estimated coasting time (in minutes and seconds)
 *         distance travelled in that time (in meters)
 * 
 * Author: Emily Guo - 301670039
******************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// Forward Delclarations
double getInitialSpeed();
double speedAftOneMin();
double deceleration(double initialSpeed, double afterSpeed);
double totalSeconds(double initialSpeed, double afterSpeed);
double totalDistance(double initialSpeed, double deceleration);
void outResults(double finalDeceleration, double minutes, double sec, double finalDistance);

/******************************************************************
 * main -- prompts the user for the initial speed and speed after
 *         one minute, then calculates the deceleration, coasting 
 *         time, and distance travelled
 * 
 * Parameters: none
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: 0
******************************************************************/
int main(){
    double initialSpeed; // the initial speed 
    double afterSpeed; // the speed after 1 minute
    double finalDeceleration; // deceleration rate
    int sec; // seconds
    double finalDistance; // final distance
    int mins=0; // minutes

    cout << "This program estimates how far and how long a cyclist will travel \nwithout pedaling, assuming constant deceleration.";

    // Ask user to provide information
    initialSpeed = getInitialSpeed();
    afterSpeed = speedAftOneMin();

    // Call functions to calculate results
    finalDeceleration = deceleration(initialSpeed, afterSpeed);
    sec = round(totalSeconds(initialSpeed, afterSpeed));
    finalDistance = round(totalDistance(initialSpeed, finalDeceleration));
    
    // Changes the seconds to minutes (but keeps the remaining seconds if it doesn't add up to a minute)
    while (sec>60){ 
        mins +=1; // adds 1 to the value of minutes if there are more than 60 seconds
        sec -=60; // subtracts 60 seconds from the total seconds
    }

    // Displays the final results
    outResults(finalDeceleration, mins, sec, finalDistance);

    return 0;
}

/******************************************************************
 * getInitialSpeed -- prompts the user for the initial speed in 
 *                    km/h and converts it to m/s
 * 
 * Parameters: none
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: initial speed (in m/s)
******************************************************************/
double getInitialSpeed(){
    
    double initialSpeed; // the initial speed 
    
    cout << "\nEnter initial speed (km/h): ";
    cin >> initialSpeed;
    initialSpeed = initialSpeed/3.6; // converts km/h to m/s

    return initialSpeed;
}

/******************************************************************
 * speedAftOneMin -- prompts the user for the speed after one minute
 * 
 * Parameters: none
 * 
 * Modifies: nothing
 * 
 * Precondition: none 
 * 
 * Returns: speed after one minute (in m/s)
******************************************************************/
double speedAftOneMin(){

    double afterSpeed; // the speed after 1 minute

    cout << "\nEnter speed after 1 minute (km/h): ";
    cin >> afterSpeed;
    afterSpeed = afterSpeed/3.6; // converts km/h to m/s

    return afterSpeed;
}

/******************************************************************
 * deceleration -- computes the deceleration rate
 * 
 * Parameters: initialSpeed -- the initial speed in m/s
 *             afterSpeed -- the speed after 1 minute in m/s
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: deceleration value in m/s^2
******************************************************************/
double deceleration(double initialSpeed, double afterSpeed){

    double deceleration = (initialSpeed - afterSpeed) / 60;
    return deceleration; 
}

/******************************************************************
 * totalSeconds -- computes the total coasting time in seconds
 * 
 * Parameters: initialSpeed -- the initial speed in m/s
 *             afterSpeed -- the speed after 1 minute in m/s
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: total coasting time in seconds
******************************************************************/
double totalSeconds(double initialSpeed, double afterSpeed){

    double seconds = (60*initialSpeed)/(initialSpeed - afterSpeed);
    return seconds;
}

/******************************************************************
 * totalDistance -- computes the total distance the cyclist will 
 *                  have travelled 
 * 
 * Parameters: initialSpeed -- initial speed in m/s
 *             deceleration -- deceleration value in m/s^2
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: total distance travelled (in meters)
******************************************************************/
double totalDistance(double initialSpeed, double deceleration){

    double distance = (initialSpeed*initialSpeed)/(2*deceleration);
    return distance;
}

/******************************************************************
 * outResults -- outputs the final results
 * 
 * Parameters: finalDeceleration -- final deceleration rate
 *             minutes -- total coasting time in minutes
 *             sec -- total coasting time in seconds
 *             finalDistance -- total distance travelled in meters
 * 
 * Modifies: nothing
 * 
 * Precondition: none
 * 
 * Returns: none
******************************************************************/
void outResults(double finalDeceleration, double minutes, double sec, double finalDistance){

    cout << "\ndeceleration = " << finalDeceleration;
    cout << ", minutes = " << minutes << ", seconds = "<< sec << ", distance = " << finalDistance;

}