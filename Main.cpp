/*
David Jones
04/16/2023
Week 7 Project 3 Assignment
CS 210 Programming Languages
SNHU
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class ItemTracker {

private:
    map<string, int> item_freq;                                         // Map that will store the item and its frequency 


public:
    ItemTracker() {                                                     //Constructor reads in file and updates map
        fstream inFS;
        inFS.open("CS210_Project_Three_Input_File", ios::in);           // Opens the file
        ifstream input_file("CS210_Project_Three_Input_File.txt");      // input file
        string item;                
        while (input_file >> item) {                                    // Loops through each item in the file
            ++item_freq[item];
        }
    }

    int getFrequency(string item) {                                     // Returns frequency of given items
        return item_freq[item];
    }
        
    void backupData () {                                                // Stores the frequency in the backup file
        fstream output_file("frequency.dat");                           // Outputs to backup file
        for (auto i : item_freq) {
            output_file << i.first << ' ' << i.second << endl;
        }
    }

    void printList() {                                                  // Prints the list showing the frequency of each item
        cout << endl;
        cout << "Item Frequency" << endl;
        cout << "--------------------------------------" << endl;
        for (auto i : item_freq) {                                      // Loop that finds and prints the frequency of the items
            cout << i.first << ' ' << i.second << endl;
        }
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "Select a new option to continue" << endl;
        cout << endl;
    }

    void printHistogram() {                                             // Prints the histogram of the items in the file
        cout << endl;
        cout << "Item Histogram" << endl;
        cout << endl;
        cout << "--------------------------------------" << endl;

        for (auto i : item_freq) {                                      //Loop that counts frequency and prints the histogram
            cout << i.first << " ";
            for (int j = 0; j < i.second; ++j) {
                cout << "*";
            }
            cout << endl;
            cout << "--------------------------------------" << endl;
            cout << endl;
        }
    }
};

int main() {
    ItemTracker tracker;                                                                                    // Creating ItemTracker object
    
    int option;
    do {                                                                                                    // Displays the menu to the user and starts the do-while loop until program is exited
        cout << " ******************************** User Menu **********************************" << endl;
        cout << endl;
        cout << "    Option 1. Find frequency of an item" << endl;
        cout << "    Option 2. Print frequency of all items" << endl;
        cout << "    Option 3. Print histogram of all items" << endl;
        cout << "    Option 4. Exit" << endl;
        cout << endl;
        cout << "*****************************************************************************" << endl;
        cout << endl;
        cout << "Enter the number for the desired option:  ";
        cin >> option;

        switch (option) { 
        case 1: {                                                                                                               // Option 1: Finds the frequency of the requsted item
            string item_to_find;
            cout << endl;
            cout << "Enter the item to find frequency of: ";
            cin >> item_to_find;
            cout << endl;
            cout << "-- " << item_to_find << " appeared " << tracker.getFrequency(item_to_find) << " times in the file." << endl; // Outputs the frequency of the item
            cout << endl;
            cout << "Select a new option to continue" << endl;
            cout << endl;
            break;
        }
        case 2: {                                                              // Option 2: Prints the frequency of all the items in the file
            tracker.printList();                                               //Print list
            tracker.backupData();                                              // Write data to file
            break;
        }
        case 3: {                                                              // Option 3: Prints a historgram of all of the items in the file and thier frequency
            tracker.printHistogram();                                          //print histogram
            tracker.backupData();                                              //Write data to file
            cout << "Select a new option to continue" << endl;
            cout << endl;
            break;
        }
        case 4: {                                                              // Option 4: Closes the program
            cout << endl;
            cout << " The program is now closed. Have a great day" << endl;
            break;
        }
        default: {                                                             // If incorret menu option this will display and cyle through the do-while loop again
            cout << endl;
            cout << "Invalid option. please choose option 1, 2, 3, or 4 to proceed. Try again." << endl;
            cout << endl;

            break;
        }
        }
    } while (option != 4);

    return 0;
}

