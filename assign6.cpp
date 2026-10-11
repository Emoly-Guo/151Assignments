/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * Assignment 6 - Thermal Conduction Problem
 * assign6.cpp
 * 
 * Input: 
 * Output:
 * 
 * Author: Emily Guo - 301670039
******************************************************************/

void findK();
void findT2();
void findX();

#include <iostream>
using namespace std;

int main(){

    int select;

    while(select != 0){
        cout << "Please select one of the following options:\n";
        cout << "1) k\n2) T2\n3) X\n0) Exit\nSelection:";
        cin >> select;
        
        if(select == 1){
            findK();
        }
        if(select == 2){
            findT2();
        }
        if(select == 3){
            findX();
        }
        if(select == 0){
            cout << "\nProgram exiting." << endl;
            break;
        }
    }
    return 0;

}


void findK(){
    double H, k, A, T1, T2, X;
    cout << "\nEnter H (rate of heat transfer, W):";
    cin >> H;
    cout << "\nEnter A (cross-sectional area, m^2):";
    cin >> A;
    cout << "\nEnter T1 (temp. at side 1, K):";
    cin >> T1;
    cout << "\nEnter T2 (temp. at side 2, K):";
    cin >> T2;
    cout << "\nEnter X (thickness, m):";
    cin >> X;
    cout << "\n------------------------------------------------";

    k = (H*X)/(A*(T2-T1));

    cout << "\nH = " << H << " W";
    cout << "\nk = " << k << " W/m-K";
    cout << "\nA = " << A << " m^2";
    cout << "\nT1 = " << T1 << " K";
    cout << "\nT2 = " << T2 << " K";
    cout << "\nX = " << X << " m" << endl;
}

void findT2(){
    double H, k, A, T1, T2, X;

    cout << "\nEnter H (rate of heat transfer, W):";
    cin >> H;
    cout << "\nEnter k (coefficient of thermal conductivity, W/m-K):";
    cin >> k;
    cout << "\nEnter A (cross-sectional area, m^2):";
    cin >> A;
    cout << "\nEnter T1 (temp. at side 1, K):";
    cin >> T1;
    cout << "\nEnter X (thickness, m):";
    cin >> X;
    cout << "\n------------------------------------------------";

    T2 = ((H*X)/(k*A))+T1;

    cout << "\nH = " << H << " W";
    cout << "\nk = " << k << " W/m-K";
    cout << "\nA = " << A << " m^2";
    cout << "\nT1 = " << T1 << " K";
    cout << "\nT2 = " << T2 << " K";
    cout << "\nX = " << X << " m" << endl;

}

void findX(){
    double H, k, A, T1, T2, X;

    cout << "\nEnter H (rate of heat transfer, W):";
    cin >> H;
    cout << "\nEnter k (coefficient of thermal conductivity, W/m-K):";
    cin >> k;
    cout << "\nEnter A (cross-sectional area, m^2):";
    cin >> A;
    cout << "\nEnter T1 (temp. at side 1, K):";
    cin >> T1;
    cout << "\nEnter T2 (temp. at side 2, K):";
    cin >> T2;

    cout << "\n------------------------------------------------";

    X = ((k*A)*(T2-T1))/H;

    cout << "\nH = " << H << " W";
    cout << "\nk = " << k << " W/m-K";
    cout << "\nA = " << A << " m^2";
    cout << "\nT1 = " << T1 << " K";
    cout << "\nT2 = " << T2 << " K";
    cout << "\nX = " << X << " m" << endl;

}