#include <iostream>
using namespace std;

// Functions to print ASCII Art of RPS Hand Signs
void print_rock();
void print_paper();
void print_scissors();

// Define constants for random numbers cpu generates for RPS choice
constexpr int rock = 1;
constexpr int paper = 2;
constexpr int scissors = 3;

int main() try {
    srand(time(NULL));
    while(true) {
        cout << "---Rock Paper Scissors!!!---\n"
             << "Best Two out of Three\n\n";

        int human_win_count = 0;
        int cpu_win_count = 0;
        int round = 1;

        // Play Best 2 out of 3 RPS, ends when either player wins 2 rounds
        while(human_win_count < 2 && cpu_win_count < 2) {
            cout << "----------------------------\n"
                 << "Enter your move:\n"
                 << "'1' - rock\n"
                 << "'2' - paper\n"
                 << "'3' - scissors\n"
                 << "----------------------------\n\n";
    
            cout << "You: ";
            int human = ' ';
            cin >> human;

            // Print ASCII Art for Rock, Paper, or Scissors based on choice
            switch (human) {
                case rock:
                    print_rock();
                    break;
                case paper:
                    print_paper();
                    break;
                case scissors:
                    print_scissors();
                    break;
                default:
                    throw runtime_error("Invalid Input");
                    break;
            }

            // Cpu generates random number in range [1,3] as RPS choice 
            int cpu = (rand() % 3) + 1;

            cout << "Computer: ";

            // Print Rock, Paper, or Scissors based on cpuChoice
            switch (cpu) {
                case rock:
                    cout << "1\n";
                    print_rock();
                    break;
                case paper:
                    cout << "2\n";
                    print_paper();
                    break;
                case scissors:
                    cout << "3\n";
                    print_scissors();
                    break;
                default:
                    throw runtime_error("Computer RNG Fail");
            }

            // Compare all possible RPS games between the human and computer
            switch (human) {
                case rock:
                    switch(cpu) {
                        case rock:
                            cout << "Tie in round " << round << "!";
                            break;
                        case paper:
                            cout << "Computer wins round " << round << "!";
                            ++cpu_win_count;
                            ++round;
                            break;
                        case scissors:
                            cout << "You win round " << round << "!";
                            ++human_win_count;
                            ++round;
                            break;
                    }
                    break;
                case paper:
                    switch(cpu) {
                        case rock:
                            cout << "You win round " << round << "!";
                            ++human_win_count;
                            ++round;
                            break;
                        case paper:
                            cout << "Tie in round " << round << "!";
                            break;
                        case scissors:
                            cout << "Computer wins round " << round << "!";
                            ++cpu_win_count;
                            ++round;
                            break;
                    }
                    break;
                case scissors:
                    switch(cpu) {
                        case rock:
                            cout << "Computer wins round " << round << "!";
                            ++cpu_win_count;
                            ++round;
                            break;
                        case paper:
                            cout << "You win round " << round << "!";
                            ++human_win_count;
                            ++round;
                            break;
                        case scissors:
                            cout << "Tie in round " << round << "!";
                            break;
                    }
                    break;
                default:
                    throw runtime_error("Invalid Input");
                    break;
            }

            cout << "\n\n"
                 << "You\n"
                 << human_win_count << "\n"
                 << "Computer\n"
                 << cpu_win_count << "\n\n";
        }

        // Output Statements based on who won the best 2 out of 3 RPS
        if(human_win_count == 2) {
            cout << "You won the game!!!\nCongratulations\n";
        }
        
        if(cpu_win_count == 2) {
            cout << "Computer won the game\n";
        }

        cout << "\nPlay Again? (y/n): ";
        char answer = 0;
        cin >> answer;

        if(answer != 'y') {
            break;
        }
        else {
            cout << "\n\n";
        }
    }
    return 0;
}
catch(exception& e) {
    cerr << "\nRuntime Error: " << e.what() << "\n";
    return 1;
}

void print_rock() {
    cout << "    _______\n"
         << "---'   ____)\n"
         << "      (_____)\n"
         << "      (_____)\n"
         << "      (____)\n"
         << "---.__(___)\n\n";
}

void print_paper() {
    cout << "    _______\n"
         << "---'   ____)____\n"
         << "          ______)\n"
         << "          _______)\n"
         << "         _______)\n"
         << "---.__________)\n\n";
}

void print_scissors() {
    cout << "    _______\n"
         << "---'   ____)____\n"
         << "          ______)\n"
         << "       __________)\n"
         << "      (____)\n"
         << "---.__(___)\n\n";
}