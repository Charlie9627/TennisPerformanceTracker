// Charlie Vue
// Class: ITCS 2530 - C++ Programming Final Exam
// Project Detail: A C++ program that tracks tennis performance stats and offers personalized feedback.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_PLAYERS = 10;

// Struct to hold tennis performance data with initialized members
struct MatchStats {
    string playerName = "";
    int aces = 0;
    int doubleFaults = 0;
    int unforcedErrors = 0;
    int winners = 0;
    float performanceScore = 0.0f;
};

// Class to manage tennis data and logic
class TennisTracker {
private:
    MatchStats stats[MAX_PLAYERS];
    int count = 0;
    string inputFileName;
    string outputFileName;

public:
    // Constructor
    TennisTracker(string inputFile, string outputFile) {
        inputFileName = inputFile;
        outputFileName = outputFile;
    }

    // Read match data from input file
    bool readFromFile() {
        ifstream infile(inputFileName);
        if (!infile) {
            cerr << "Error opening input file.\n";
            return false;
        }

        while (count < MAX_PLAYERS && infile >> stats[count].playerName
            >> stats[count].aces
            >> stats[count].doubleFaults
            >> stats[count].unforcedErrors
            >> stats[count].winners) {
            count++;
        }

        infile.close();
        return true;
    }

    // Calculate performance scores based on stats
    void calculatePerformance() {
        for (int i = 0; i < count; ++i) {
            stats[i].performanceScore =
                (stats[i].winners * 1.5f + stats[i].aces * 1.2f)
                - (stats[i].unforcedErrors * 1.0f + stats[i].doubleFaults * 1.3f);
        }
    }

    // Give feedback based on performance
    string giveFeedback(const MatchStats& m) {
        if (m.unforcedErrors > 10)
            return "Work on reducing unforced errors.";
        else if (m.doubleFaults > 5)
            return "Improve your serve consistency.";
        else if (m.performanceScore >= 20)
            return "Excellent match!";
        else
            return "Good effort. Keep practicing!";
    }

    // Display all data to console
    void displayAll() {
        cout << left << setw(15) << "Player"
            << setw(6) << "Aces"
            << setw(10) << "DFaults"
            << setw(10) << "UErrors"
            << setw(9) << "Winners"
            << setw(10) << "Score"
            << "Feedback" << endl;
        cout << string(70, '-') << endl;

        for (int i = 0; i < count; ++i) {
            cout << left << setw(15) << stats[i].playerName
                << setw(6) << stats[i].aces
                << setw(10) << stats[i].doubleFaults
                << setw(10) << stats[i].unforcedErrors
                << setw(9) << stats[i].winners
                << fixed << setprecision(1) << setw(10) << stats[i].performanceScore
                << giveFeedback(stats[i]) << endl;
        }
    }

    // Save results to output file
    void writeToFile() {
        ofstream outfile(outputFileName);
        if (!outfile) {
            cerr << "Error opening output file.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            outfile << stats[i].playerName << " "
                << stats[i].aces << " "
                << stats[i].doubleFaults << " "
                << stats[i].unforcedErrors << " "
                << stats[i].winners << " "
                << fixed << setprecision(1) << stats[i].performanceScore << " "
                << giveFeedback(stats[i]) << endl;
        }

        outfile.close();
        cout << "\nResults saved to " << outputFileName << endl;
    }
};

// Menu function
void showMenu() {
    cout << "\n===== Tennis Performance Tracker =====\n";
    cout << "1. Read data from file\n";
    cout << "2. Calculate performance scores\n";
    cout << "3. Display all player stats\n";
    cout << "4. Save results to file\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "results.txt";
    TennisTracker tracker(inputFile, outputFile);

    int choice;
    bool dataLoaded = false;
    bool calculated = false;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            if (tracker.readFromFile()) {
                cout << "Data loaded successfully.\n";
                dataLoaded = true;
            }
            break;
        case 2:
            if (dataLoaded) {
                tracker.calculatePerformance();
                cout << "Performance scores calculated.\n";
                calculated = true;
            }
            else {
                cout << "Please load data first.\n";
            }
            break;
        case 3:
            if (calculated) {
                tracker.displayAll();
            }
            else {
                cout << "Please calculate scores first.\n";
            }
            break;
        case 4:
            if (calculated) {
                tracker.writeToFile();
            }
            else {
                cout << "Please calculate scores before saving.\n";
            }
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
