#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <regex>


using namespace std;

// Structure to represent a booking
struct Booking {
    int rollNumber;
    string facilityType;
    string date;
    string timeslot;
};

// Class to manage sports facilities
class SportsFacilityManager {
private:
    vector<Booking> bookings;
    string fileName = "bookings.txt";

    void loadBookingsFromFile() {
        ifstream file(fileName);
        if (file.is_open()) {
            Booking booking;
            while (file >> booking.rollNumber >> booking.facilityType >> booking.date >> booking.timeslot) {
                bookings.push_back(booking);
            }
            file.close();
        }
    }

    void saveBookingsToFile() {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const Booking& booking : bookings) {
                file << booking.rollNumber << " " << booking.facilityType << " " << booking.date << " " << booking.timeslot << endl;
            }
            file.close();
        }
    }

public:
    SportsFacilityManager() {
        loadBookingsFromFile();
    }

    void addStudent(int rollNumber, string password) {
        ofstream file("credentials.txt", std::ios_base::app);
        file << rollNumber << " " << password << "\n";
    }

    bool authenticate(int rollNumber, string password) {
        ifstream file("credentials.txt");
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int storedRollNumber;
            string storedPassword;
            if (!(iss >> storedRollNumber >> storedPassword)) {
                break; // Error
            }
            if (storedRollNumber == rollNumber && storedPassword == password) {
                return true;
            }
        }
        return false;
    }

    void bookSlot(int rollNumber, string facilityType, string date, string timeslot) {
        Booking newBooking = {rollNumber, facilityType, date, timeslot};
        bookings.push_back(newBooking);
        saveBookingsToFile();
        cout << "Slot booked successfully!" << endl;
    }

    bool isSlotAvailable(string facilityType, string date, string newTimeslot) {
        int newStart, newEnd;
        sscanf(newTimeslot.c_str(), "%d-%d", &newStart, &newEnd);

        for (const Booking& booking : bookings) {
            if (booking.facilityType == facilityType && booking.date == date) {
                int existingStart, existingEnd;
                sscanf(booking.timeslot.c_str(), "%d-%d", &existingStart, &existingEnd);

                if ((newStart >= existingStart && newStart < existingEnd) ||
                    (newEnd > existingStart && newEnd <= existingEnd) ||
                    (newStart <= existingStart && newEnd >= existingEnd)) {
                    return false;
                }
            }
        }
        return true;
    }

    void viewBookingHistory(int rollNumber) {
        cout << setw(15) << left << "Facility Type" << setw(15) << left << "Date" << setw(15) << left << "Timeslot" << endl;
        cout << string(45, '-') << endl;
        for (const Booking& booking : bookings) {
            if (booking.rollNumber == rollNumber) {
                cout << setw(15) << left << booking.facilityType << setw(15) << left << booking.date << setw(15) << left << booking.timeslot << endl;
            }
        }
    }

    void deleteBooking(int rollNumber, string facilityType, string date, string timeslot) {
    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->rollNumber == rollNumber && it->facilityType == facilityType && it->date == date && it->timeslot == timeslot) {
            bookings.erase(it);
            saveBookingsToFile();
            cout << "Booking deleted successfully!" << endl;
            return;
        }
    }
    cout << "No matching booking found." << endl;
}
};

int getIntInput(string prompt="") {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

void addInitialStudents() {
    SportsFacilityManager manager;
    manager.addStudent(220000, "naruto");
    manager.addStudent(220001, "itachi");
    manager.addStudent(220002, "madara");

}


int main() {

    addInitialStudents();
    SportsFacilityManager manager;
    int choice, rollNumber;
    string password, date, timeslot, facilityType;
    int facility;

    regex datePattern("(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/([12][0-9]{3})");
    regex timePattern("([01][0-9]|2[0-3]):[0-5][0-9]-([01][0-9]|2[0-3]):[0-5][0-9]");

    do {
        cout << "\nSports Facility Management System\n";
        cout << "1. New Student\n";
        cout << "2. Existing Student\n";
        cout << "3. Exit\n";
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                rollNumber = getIntInput("Enter roll number: ");
                if (rollNumber < 100000 || rollNumber > 999999) {
                    cout << "Invalid roll number. It should be a 6-digit integer." << endl;
                    continue;
                }
                cout << "Enter password: ";
                cin >> password;
                manager.addStudent(rollNumber, password);
                cout << "Student added successfully!" << endl;
                break;
            case 2:
                rollNumber = getIntInput("Enter roll number: ");
                if (rollNumber < 100000 || rollNumber > 999999) {
                    cout << "Invalid roll number. It should be a 6-digit integer." << endl;
                    continue;
                }
                cout << "Enter password: ";
                cin >> password;
                if (!manager.authenticate(rollNumber, password)) {
                    cout << "Invalid roll number or password." << endl;
                    continue;
                }
                else{
                    do {


                        printf("\n\t\t\t\t\t\t\t Welcome  %d\n\n",rollNumber);
                        cout << "1. Book a slot\n";
                        cout << "2. Check slot availability\n";
                        cout << "3. View booking history\n";
                        cout << "4. Cancel booking\n";
                        cout << "5. Logout\n";
                        choice = getIntInput("Enter your choice: ");

                        switch (choice) {
                            case 1:
                                cout << "1. Gym\n";
                                cout << "2. Squash\n";
                                cout << "3. Badminton\n";
                                cout << "4. TableTennis\n";
                                cout << "5. Swimming\n";
                                cout << "6. Tennis\n";
                                cout << "7. Billiards\n";
                                facility=getIntInput("Enter facility type:");
                                switch(facility){
                                    case 1:
                                        facilityType="Gym";
                                        break;
                                    case 2:
                                        facilityType="Squash";
                                        break;
                                    case 3:
                                        facilityType="Badminton";
                                        break;
                                    case 4:
                                        facilityType="TableTennis";
                                        break;
                                    case 5:
                                        facilityType="Swimming";
                                        break;
                                    case 6:
                                        facilityType="Tennis";
                                        break;
                                    case 7:
                                        facilityType="Billiards";
                                        break;
                                    default:
                                        cout << "Invalid choice. Please try again." << endl;
                                        continue;
                                }
                                cout << "Enter date (dd/mm/yyyy): ";
                                cin >> date;
                                if (!std::regex_match(date, datePattern)) {
                                    cout << "Invalid date format. Please enter in dd/mm/yyyy format." << endl;
                                    continue;
                                }       
                                cout << "Enter timeslot (hh:mm-hh:mm): ";
                                cin >> timeslot;
                                if (!std::regex_match(timeslot, timePattern)) {
                                    cout << "Invalid timeslot format. Please enter in hh:mm-hh:mm format." << endl;
                                    continue;
                                }
                                if (manager.isSlotAvailable(facilityType, date, timeslot)) {
                                    manager.bookSlot(rollNumber, facilityType, date, timeslot);
                                } else {
                                    cout << "Slot is already booked. Please try another time." << endl;
                                }
                                break;
                            case 2:
                                cout << "Enter facility type (gym/squash/badminton): ";
                                cin >> facilityType;
                                cout << "Enter date (dd/mm/yyyy): ";
                                cin >> date;
                                cout << "Enter timeslot (hh:mm-hh:mm): ";
                                cin >> timeslot;
                                if (manager.isSlotAvailable(facilityType, date, timeslot)) {
                                    cout << "The slot is available." << endl;
                                } else {
                                    cout << "The slot is already booked." << endl;
                                }
                                break;
                            case 3:
                                manager.viewBookingHistory(rollNumber);
                                break;
                            case 4:
                                cout << "1. Gym\n";
                                cout << "2. Squash\n";
                                cout << "3. Badminton\n";
                                cout << "4. TableTennis\n";
                                cout << "5. Swimming\n";
                                cout << "6. Tennis\n";
                                cout << "7. Billiards\n";
                                facility=getIntInput("Enter facility type:");
                                switch(facility){
                                    case 1:
                                        facilityType="Gym";
                                        break;
                                    case 2:
                                        facilityType="Squash";
                                        break;
                                    case 3:
                                        facilityType="Badminton";
                                        break;
                                    case 4:
                                        facilityType="TableTennis";
                                        break;
                                    case 5:
                                        facilityType="Swimming";
                                        break;
                                    case 6:
                                        facilityType="Tennis";
                                        break;
                                    case 7:
                                        facilityType="Billiards";
                                        break;
                                    default:
                                        cout << "Invalid choice. Please try again." << endl;
                                        continue;
                                }
                                cout << "Enter date (dd/mm/yyyy): ";
                                cin >> date;
                                cout << "Enter timeslot (hh:mm-hh:mm): ";
                                cin >> timeslot;
                                manager.deleteBooking(rollNumber, facilityType, date, timeslot);
                                break;
                            case 5:
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    } while (choice != 5);
                }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}