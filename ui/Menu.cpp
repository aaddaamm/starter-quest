#include "Menu.h"
#include <iostream>
#include <termios.h> // For terminal control
#include <unistd.h>  // For STDIN_FILENO
#include <cstdio>    // For getchar

namespace ui {

// Helper function to set terminal to raw mode
void set_raw_mode(struct termios& old_tio) {
    struct termios new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

// Helper function to restore original terminal settings
void restore_terminal_mode(const struct termios& old_tio) {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

// Helper function to display the menu
void displayMenu(const std::string& title, const std::vector<std::string>& options, int selected_index) {
    // ANSI escape code to clear the screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";

    std::cout << title << "\n\n";
    for (int i = 0; i < options.size(); ++i) {
        if (i == selected_index) {
            std::cout << " > " << options[i] << "\n";
        } else {
            std::cout << "   " << options[i] << "\n";
        }
    }
    std::cout << "\n(Use arrow keys or W/S to navigate, Enter to select)\n";
}

std::string selectFromList(const std::string& title, const std::vector<std::string>& options) {
    if (options.empty()) {
        return "";
    }

    struct termios old_tio;
    set_raw_mode(old_tio);

    int selected_index = 0;
    int key;

    while (true) {
        displayMenu(title, options, selected_index);
        key = getchar();

        if (key == '\n') { // Enter key
            break;
        } else if (key == 27) { // ANSI escape sequence for arrow keys
            // The next two characters define the arrow key
            getchar(); // Skip the '['
            switch (getchar()) {
                case 'A': // Up arrow
                    selected_index = (selected_index - 1 + options.size()) % options.size();
                    break;
                case 'B': // Down arrow
                    selected_index = (selected_index + 1) % options.size();
                    break;
            }
        } else if (key == 'w' || key == 'W') {
            selected_index = (selected_index - 1 + options.size()) % options.size();
        } else if (key == 's' || key == 'S') {
            selected_index = (selected_index + 1) % options.size();
        }
    }

    restore_terminal_mode(old_tio);
    
    // Clear the menu from the screen after selection
    std::cout << "\033[2J\033[1;1H";

    return options[selected_index];
}

} // namespace ui