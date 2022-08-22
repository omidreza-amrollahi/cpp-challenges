
// Section 6
// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

int main() {
    
    int smallRooms, largeRooms, smallRoomCost, largeRoomCost, totalCost;
    double tax, totalEstimate;
    const int SMALL_ROOM_COST = 25;
    const int LARGE_ROOM_COST = 35;
    const double TAX_RATE = 0.06;

    cout << "Enter the number of small rooms: ";
    cin >> smallRooms;
    cout << "Enter the number of large rooms: ";
    cin >> largeRooms;
    smallRoomCost = SMALL_ROOM_COST * smallRooms;
    largeRoomCost = LARGE_ROOM_COST * largeRooms;
    totalCost = smallRoomCost + largeRoomCost;
    tax = totalCost * TAX_RATE;
    totalEstimate = totalCost + tax;
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << smallRooms << endl;
    cout << "Number of large rooms: " << largeRooms << endl;
    cout << "Price per small room: $" << SMALL_ROOM_COST << endl;
    cout << "Price per large room: $" << LARGE_ROOM_COST << endl;
    cout << "Cost : $" << totalCost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: $" << totalEstimate << endl;
    cout << "This estimate is valid for 30 days" << endl;

    cout << endl;
    return 0;
}

