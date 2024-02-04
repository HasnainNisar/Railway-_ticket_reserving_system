#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream> // Added fstream library

using namespace std;

struct BookingDetails {
    string name;
    string from;
    string destination;
    string token;
};

class Train {
private:
    string name;
    int capacity;

public:
    Train(const string& trainName, int trainCapacity) : name(trainName), capacity(trainCapacity) {}

    string getName() const {
        return name;
    }

    int getCap() const {
        return capacity;
    }

    BookingDetails enterDetails() {
        BookingDetails book;
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, book.name);

        vector<string> cities = { "Karachi", "Lahore", "Islamabad", "Peshawar", "Quetta" };
        int cityCount = cities.size();

        cout << "Select the From station:\n";
        for (int i = 0; i < cityCount; i++) {
            cout << i + 1 << ". " << cities[i] << endl;
        }
        int fromIndex;
        cout << "Enter the number corresponding to the From station: ";
        cin >> fromIndex;
        cin.ignore();
        book.from = cities[fromIndex - 1];

        cout << "Select the Destination station:\n";
        for (int i = 0; i < cityCount; i++) {
            cout << i + 1 << ". " << cities[i] << endl;
        }
        int destIndex;
        cout << "Enter the number corresponding to the Destination station: ";
        cin >> destIndex;
        cin.ignore();
        book.destination = cities[destIndex - 1];

        // Generate unique token
        book.token = generateToken();

        return book;
    }

    string generateToken() {
        string token;
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(0, chars.size() - 1);

        for (int i = 0; i < 10; i++) {
            token += chars[distribution(generator)];
        }

        return token;
    }

    void displayPassengerDetails(const string& train, const BookingDetails& book, char type, int arr3[], int arr[]) {
        cout << "\n\n\t\tYour Train: " << train << endl;
        cout << "\t\tName: " << book.name << endl;
        cout << "\t\tFrom: " << book.from << endl;
        cout << "\t\tTo: " << book.destination << endl;
        cout << "\t\tToken: " << book.token << endl;

        if (type == 'F' || type == 'f') {
            cout << "\t\tType: First Class" << endl;
        }
        else if (type == 'B' || type == 'b') {
            cout << "\t\tType: Business Class" << endl;
        }
        else if (type == 'E' || type == 'e') {
            cout << "\t\tType: Economy Class" << endl;
        }

        cout << "\t\tRow No.: ";
        for (int i = 0; i < 5; i++) {
            cout << arr3[i] << " , ";
        }
        cout << endl;

        cout << "\t\tSeat No.: ";
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " , ";
        }
        cout << endl;

        cout << "\n\n\t\tThank you for reserving a seat! Your token is " << book.token << endl;
        cout << "\n\n\t\tPress any key to continue... ";
        cin.ignore();
        cin.get();
        system("CLS");
    }

    void displayMenu() {
        int ch;
        cout << "Welcome to the Railway Booking System" << endl;
        cout << "1. Select Train" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1) {
            system("CLS");
            selectTrain();
        }
    }

    void selectTrain() {
        int choice;
        cout << " 1. Pakistan Express\n";
        cout << " 2. Rehman Baba Express\n";
        cout << " 3. Awam Express\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("CLS");
            BookingDetails book = enterDetails();
            settingPlan(book, choice);
        }
        else if (choice == 2) {
            system("CLS");
            BookingDetails book = enterDetails();
            settingPlan(book, choice);
        }
        else if (choice == 3) {
            system("CLS");
            BookingDetails book = enterDetails();
            settingPlan(book, choice);
        }
        else {
            cout << "Error! Enter a valid train!\n";
        }
    }

    void settingPlan(const BookingDetails& book, int choice) {
        system("CLS");
        int arr[14][7];

        cout << "***************** Railway Seating Plan *******************\n";
        cout << "Row 1 and Row 2 are First Class\n";
        cout << "Row 3 to Row 7 are Business Class\n";
        cout << "Row 8 to Row 13 are Economy Class\n";
        cout << "The Seating Arrangement System\n\n\tA\tB\tC\tD\tE\tF\n";

        for (int i = 1; i < 14; i++) {
            cout << "Row " << i << "\t";
            for (int j = 1; j < 7; j++) {
                arr[i][j] = 0;
                cout << (arr[i][j] == 0 ? to_string(j) : "#") << "\t";
            }
            cout << endl;
        }

        bool flag2 = true;
        int arr2[5] = { 0 };
        int arr3[5] = { 0 };
        int h = 0;
        int d = 0;
        char type;

        cout << endl;
        cout << "Press F for First class\n";
        cout << "Press B for Business class\n";
        cout << "Press E for Economy class\n";
        cout << "Press X to exit the program\n";
        cin >> type;

        do {
            int row, seat;

            if (type == 'F' || type == 'f') {
                cout << "Which Row do you want to select: ";
                cin >> row;

                if (row < 1 || row > 2) {
                    cout << "Wrong input! Please enter a value between 1 and 2.\n";
                    system("CLS");
                    continue;
                }
            }
            else if (type == 'B' || type == 'b') {
                cout << "Which Row do you want to select: ";
                cin >> row;

                if (row < 3 || row > 7) {
                    cout << "Wrong input! Please enter a value between 3 and 7.\n";
                    system("CLS");
                    continue;
                }
            }
            else if (type == 'E' || type == 'e') {
                cout << "Which Row do you want to select: ";
                cin >> row;

                if (row < 8 || row > 13) {
                    cout << "Wrong input! Please enter a value between 8 and 13.\n";
                    system("CLS");
                    continue;
                }
            }
            else if (type == 'X' || type == 'x') {
                cout << "Exiting the program...\n";
                return;
            }
            else {
                cout << "Invalid input! Please enter a valid seat type.\n";
                system("CLS");
                continue;
            }

            cout << "Which seat do you want to take: ";
            cin >> seat;

            if (seat < 1 || seat > 6) {
                cout << "Invalidp seat number! Please enter a value between 1 and 6.\n";
                system("CLS");
                continue;
            }

            if (arr[row][seat] != 0) {
                cout << "Seat already occupied! Please select another seat.\n";
                system("CLS");
                continue;
            }

            arr[row][seat] = seat;

            cout << "\tA\tB\tC\tD\tE\tF\n";
            for (int i = 1; i < 14; i++) {
                cout << "Row " << i << "\t";
                for (int j = 1; j < 7; j++) {
                    cout << (arr[i][j] == 0 ? to_string(j) : "#") << "\t";
                }
                cout << endl;
            }
            cout << endl;

            int sel;
            cout << "Do you want to reserve another seat?\n";
            cout << "1. Yes\n";
            cout << "2. No\n";
            cout << "Enter your choice: ";
            cin >> sel;

            arr2[h] = seat;
            arr3[d] = row;
            h++;
            d++;

            if (sel == 1) {
                flag2 = true;
            }
            else {
                system("CLS");
                if (choice == 1) {
                    displayPassengerDetails("Pakistan Express", book, type, arr3, arr2);
                }
                else if (choice == 2) {
                    displayPassengerDetails("Rehman Baba Express", book, type, arr3, arr2);
                }
                else if (choice == 3) {
                    displayPassengerDetails("Awam Express", book, type, arr3, arr2);
                }
                cout << "Thanks for Using Our Services!\n";
                flag2 = false;
            }

            system("CLS");
            cout << "***************** Railway Seating Plan *******************\n";
            cout << "Row 1 and Row 2 are First Class\n";
            cout << "Row 3 to Row 7 are Business Class\n";
            cout << "Row 8 to Row 13 are Economy Class\n";
            cout << "\tA\tB\tC\tD\tE\tF\n";
            for (int i = 1; i < 14; i++) {
                cout << "Row " << i << "\t";
                for (int j = 1; j < 7; j++) {
                    cout << (arr[i][j] == 0 ? to_string(j) : "#") << "\t";
                }
                cout << endl;
            }
            cout << endl;

        } while (flag2);

        // Write program details to a text file
        ofstream outFile("passenger_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Train: ";
            if (choice == 1) {
                outFile << "Pakistan Express";
            }
            else if (choice == 2) {
                outFile << "Rehman Baba Express";
            }
            else if (choice == 3) {
                outFile << "Awam Express";
            }
            outFile << endl;
            outFile << "Name: " << book.name << endl;
            outFile << "From: " << book.from << endl;
            outFile << "To: " << book.destination << endl;
            outFile << "Token: " << book.token << endl;
            outFile << "Type: ";
            if (type == 'F' || type == 'f') {
                outFile << "First Class";
            }
            else if (type == 'B' || type == 'b') {
                outFile << "Business Class";
            }
            else if (type == 'E' || type == 'e') {
                outFile << "Economy Class";
            }
            outFile << endl;
            outFile << "Row No.: ";
            for (int i = 0; i < 5; i++) {
                outFile << arr3[i] << " , ";
            }
            outFile << endl;
            outFile << "Seat No.: ";
            for (int i = 0; i < 5; i++) {
                outFile << arr[i] << " , ";
            }
            outFile << endl;
            outFile.close();
        }
        else {
            cout << "Unable to open the file to write program details." << endl;
        }
    }
};

int main() {
    Train T("Pak", 100);
    T.displayMenu();
    return 0;
}
