#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Game {
    string name;
    string type;
    int year;
    double price;
};

void displayMenu() {
    cout << "Choose from 1 - 4" << endl;
    cout << "1. Input Game" << endl;
    cout << "2. Edit Game" << endl;
    cout << "3. Show All Games" << endl;
    cout << "4. Exit" << "\n" << endl;
    cout << "\n";
}

void addGame(Game& game) {
    cout << "What's the name of game? ";
    cin.ignore();
    getline(cin, game.name);
    cout << "Type of Game (Action, Adventure, Sports etc.) "; cin >> game.type; cout << "Year of the game? "; cin >> game.year; cout << "Price of the game? "; cin >> game.price; while (game.price < 0) {
        cout << "Price can't be -. try again " << endl;
        cin >> game.price;
    }
}

void editGame(Game& game) {
    int choise;
    cout << "What part do you want to edit ?" << endl;
    cout << "1. Name of the game" << endl;
    cout << "2. Type of Game" << endl;
    cout << "3. Year of the game" << endl;
    cout << "4. Price of the game" << endl;
    cout << "Choose from 1 - 4" << "\n" << endl;
    cin >> choise;

    switch (choise) {
    case 1: cout << "What's the name of game? ";
        cin.ignore();
        getline(cin, game.name);
        break;
    case 2: cout << "Type of Game (Action, Adventure, Sports etc.) ";
        cin >> game.type;
        break;
    case 3: cout << "Year of the game? ";
        cin >> game.year;
        break;
    case 4: cout << "Price of the game? ";
        cin >> game.price;
        while (game.price < 0) {
            cout << "Price can't be -. try again " << "\n" << endl;
            cin >> game.price;
        }
        break;
    default: cout << "Not in the option. try again. " << "\n" << endl;
    }
}

void displayGame(Game& game) {
    cout << game.name << "is the name of the game." << endl;;
    cout << game.type << "is the type of the game." << endl;;
    cout << game.year << "is the year of the game." << endl;;
    cout << game.price << "is the price of the game." << "\n" << endl;;
}

int main()
{

    int count = 0;
    Game arr[3];
    int choise;
    int editChoise;

    displayMenu();
    cin >> choise;
    while (choise != 4) {
        switch (choise) {
        case 1:
            if (count < 3) {
                addGame(arr[count]);
                count++;
            }
            else {
                cout << "You cannot add more than 3 games!" << endl;
            }
            break;
        case 2: cout << "Which game do you want to edit?" << endl;
            cin >> editChoise;
            if (editChoise > 0 && editChoise <= count) {
                editGame(arr[editChoise - 1]);
            }
            else {
                cout << "Nothing to edit! try again." << "\n" << endl;
            }
            break;
        case 3: if (count > 0) {
            for (int i = 0; i < count; i++) {
                displayGame(arr[i]);
            }
        }
              else {
            cout << "Nothing to display! try again." << "\n" << endl;
        }
              break;
        case 4:
            break;
        default: cout << "not acceptable!!" << "\n" << endl;

        }
        displayMenu();
        cin >> choise;
    }

    return 0;

}

