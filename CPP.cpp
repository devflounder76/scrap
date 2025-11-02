#include <iostream>
#include <string>
#include <iomanip> // for formatting output
using namespace std;

const int NUM_SEATS = 100;    // total number of seats
const int FIRST_SEAT = 200;   // first seat number
const int LAST_SEAT = FIRST_SEAT + NUM_SEATS - 1; // last seat number

// Function prototypes
void initializeSeats(string seats[]);
void reserveSeat(string seats[]);
void cancelSeat(string seats[]);
void printAllSeats(const string seats[]);
void countAvailableSeats(const string seats[]);
void checkSeatStatus(const string seats[]);
void listSoldSeats(const string seats[]);

int main() {
    string seats[NUM_SEATS];
    initializeSeats(seats);

    int choice;

    do {
        cout << "\n========== Downtown Pavilion Reservation System ==========\n";
        cout << "1. Reserve a seat\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Print all seat statuses\n";
        cout << "4. Show number of available seats\n";
        cout << "5. Check status of a specific seat\n";
        cout << "6. List all sold seats\n";
        cout << "0. Exit program\n";
        cout << "==========================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer for getline

        switch (choice) {
            case 1: reserveSeat(seats); break;
            case 2: cancelSeat(seats); break;
            case 3: printAllSeats(seats); break;
            case 4: countAvailableSeats(seats); break;
            case 5: checkSeatStatus(seats); break;
            case 6: listSoldSeats(seats); break;
            case 0: cout << "Exiting program... Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

//------------------------------------------------------------
// Function definitions
//------------------------------------------------------------

// Initialize all seats to "Available"
void initializeSeats(string seats[]) {
    for (int i = 0; i < NUM_SEATS; ++i) {
        seats[i] = "Available";
    }
}

// Reserve a particular seat
void reserveSeat(string seats[]) {
    int seatNum;
    cout << "Enter seat number to reserve (" << FIRST_SEAT << "-" << LAST_SEAT << "): ";
    cin >> seatNum;
    cin.ignore();

    if (seatNum < FIRST_SEAT || seatNum > LAST_SEAT) {
        cout << "Invalid seat number.\n";
        return;
    }

    int index = seatNum - FIRST_SEAT;

    if (seats[index] != "Available") {
        cout << "Sorry, that seat is already taken by " << seats[index] << ".\n";
    } else {
        string name;
        cout << "Enter buyer's name: ";
        getline(cin, name);
        seats[index] = name;
        cout << "Seat #" << seatNum << " reserved for " << name << ".\n";
    }
}

// Cancel a particular seat reservation
void cancelSeat(string seats[]) {
    int seatNum;
    string name;
    cout << "Enter seat number to cancel (" << FIRST_SEAT << "-" << LAST_SEAT << "): ";
    cin >> seatNum;
    cin.ignore();

    if (seatNum < FIRST_SEAT || seatNum > LAST_SEAT) {
        cout << "Invalid seat number.\n";
        return;
    }

    int index = seatNum - FIRST_SEAT;

    if (seats[index] == "Available") {
        cout << "That seat is already available.\n";
        return;
    }

    cout << "Enter buyer's name for verification: ";
    getline(cin, name);

    if (seats[index] == name) {
        seats[index] = "Available";
        cout << "Reservation for seat #" << seatNum << " has been cancelled.\n";
    } else {
        cout << "Error: That seat was not reserved by " << name << ".\n";
    }
}

// Print out the status (Available or buyer name) of all seats
void printAllSeats(const string seats[]) {
    cout << "\n================= All Seat Statuses =================\n";
    for (int i = 0; i < NUM_SEATS; ++i) {
        cout << "Seat #" << (FIRST_SEAT + i) << ": " << seats[i] << '\n';
    }
}

// Output the number of seats that are available
void countAvailableSeats(const string seats[]) {
    int availableCount = 0;
    for (int i = 0; i < NUM_SEATS; ++i) {
        if (seats[i] == "Available") {
            availableCount++;
        }
    }
    cout << "Number of available seats: " << availableCount << '\n';
}

// Accept a seat number and output the status
void checkSeatStatus(const string seats[]) {
    int seatNum;
    cout << "Enter seat number to check (" << FIRST_SEAT << "-" << LAST_SEAT << "): ";
    cin >> seatNum;

    if (seatNum < FIRST_SEAT || seatNum > LAST_SEAT) {
        cout << "Invalid seat number.\n";
        return;
    }

    int index = seatNum - FIRST_SEAT;
    cout << "Seat #" << seatNum << " is " << seats[index] << ".\n";
}

// Output a list of all sold seats and buyers
void listSoldSeats(const string seats[]) {
    cout << "\n================= Sold Seats =================\n";
    bool anySold = false;
    for (int i = 0; i < NUM_SEATS; ++i) {
        if (seats[i] != "Available") {
            cout << "Seat #" << (FIRST_SEAT + i) << ": " << seats[i] << '\n';
            anySold = true;
        }
    }
    if (!anySold) {
        cout << "No seats have been sold yet.\n";
    }
}
