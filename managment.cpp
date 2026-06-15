#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Hotel {
private:
    int roomNo;
    string customerName;
    string phone;
    int days;
    float pricePerDay;

public:
    void bookRoom() {
        ofstream file("hotel.txt", ios::app);

        cout << "\nEnter Room Number: ";
        cin >> roomNo;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Number of Days: ";
        cin >> days;

        cout << "Enter Price Per Day: ";
        cin >> pricePerDay;

        file << roomNo << endl;
        file << customerName << endl;
        file << phone << endl;
        file << days << endl;
        file << pricePerDay << endl;

        file.close();

        cout << "\nRoom booked successfully!\n";
    }

    void viewCustomers() {
        ifstream file("hotel.txt");

        if (!file) {
            cout << "\nNo customer records found.\n";
            return;
        }

        cout << "\n----- CUSTOMER DETAILS -----\n";

        while (file >> roomNo) {
            file.ignore();

            getline(file, customerName);
            getline(file, phone);
            file >> days;
            file >> pricePerDay;

            cout << "\nRoom Number : " << roomNo;
            cout << "\nCustomer Name : " << customerName;
            cout << "\nPhone Number : " << phone;
            cout << "\nDays Stayed : " << days;
            cout << "\nPrice Per Day : Rs. " << pricePerDay;

            cout << "\nTotal Bill : Rs. "
                 << days * pricePerDay << endl;

            cout << "-----------------------------\n";
        }

        file.close();
    }
};

int main() {
    Hotel h;
    int choice;

    do {
        cout << "\n================================";
        cout << "\n   HOTEL MANAGEMENT SYSTEM";
        cout << "\n================================";
        cout << "\n1. Book Room";
        cout << "\n2. View Customer Details";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.bookRoom();
                break;

            case 2:
                h.viewCustomers();
                break;

            case 3:
                cout << "\nThank you for using the system!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 3);

    return 0;
}