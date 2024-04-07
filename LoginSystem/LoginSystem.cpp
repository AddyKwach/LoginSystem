#include <iostream>
#include <string>
#include <fstream> //used in file handling
#include <vector>

using namespace std;


//our data structure
struct user {
	string username;
	string password;

};

//function prototypes 
//allows us to use the functions before they are declared in the code
void registerUser();
bool loginUser();

// a vector to store our registered users
vector<user> users;

int main() {
    int choice;
    bool loggedIn = false;

    do {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loggedIn = loginUser();
            if (loggedIn) {
                cout << "Login successful!\n";
                // Here you can do additional tasks after login
            }
            else {
                cout << "Login failed. Incorrect username or password.\n";
            }
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 3);

    return 0;

}

void registerUser() {
    // Function to register a new user
    user newUser;

    // Prompt the user to input a username and password
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;

    // Validate the input (e.g., check if the username is already taken)
    for (const user& user : users) {
        if (user.username == newUser.username) {
            cout << "Username already exists. Please choose a different one.\n";
            return; // Exit function if username is taken
        }
    }

    // If the input is valid, save the username and password to the 'users' vector
    users.push_back(newUser);
    cout << "Registration successful!\n";
}

bool loginUser() {
    // Function to login an existing user
    string username, password;

    // Prompt the user to input their username and password
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if the entered username exists and if the corresponding password matches
    for (const user& user : users) {
        if (user.username == username && user.password == password) {
            return true; // Login successful
        }
    }

    return false; // Login failed
}


