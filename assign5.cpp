    /******************************************************************
     * Simon Fraser University
     * ENSC-151 Introduction to Software Development for Engineers
     * Assignment 5 - Surveyor's Assistant
     * assign5.cpp
     * 
     * Input: 
     * Output:
     * 
     * Author: Emily Guo - 301670039
    ******************************************************************/
    #include <iostream>
    #include <string>
    using namespace std;

    // [0,90] - NE , [90-180] - SE

    // Forward Delclarations
    void quadrants(double heading);

    int main(){

        double heading;
        int numOfTimes = 0;

        while(numOfTimes < 5){

            cout << "Please enter heading [0, 360):";
            cin >> heading;

            quadrants(heading);

            numOfTimes +=1;
        }


    }

    void quadrants(double heading){

        string dir1;
        string dir2;
        double ang;
        
        if(heading < 0 || heading >= 360){
            cout << "\n" << heading << " is an invalid input.\n";
        }

        if(heading == 90){
            ang = heading;
            dir1 = "North";
            dir2 = "East";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        if(heading == 180){
            ang = 0;
            dir1 = "South";
            dir2 = "East";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        if(heading == 270){
            ang = 90;
            dir1 = "North";
            dir2 = "West";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        else if(heading < 90){
            ang = heading;
            dir1 = "North";
            dir2 = "East";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        else if(heading > 90 && heading < 180){
            ang = 180-heading;
            dir1 = "South";
            dir2 = "East";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        else if (heading > 180 && heading < 270){
            ang = heading - 180;
            dir1 = "South";
            dir2 = "West";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        }

        else if (heading > 270 && heading < 360){
            ang = 360 - heading;
            dir1 = "North";
            dir2 = "West";

            cout << "\nHeading of : " << heading << " degrees is " << dir1 << " " << ang << " " << dir2 << endl;
        
        }

    }