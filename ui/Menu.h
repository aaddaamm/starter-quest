#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

namespace ui {

/**
 * @brief Displays a menu and allows the user to select an option using arrow keys.
 *
 * This function takes control of the terminal to provide an interactive menu.
 * It clears the screen, displays the options, and highlights the current selection.
 * The user can navigate with the Up and Down arrow keys and select with the Enter key.
 *
 * @param title The title of the menu, displayed at the top.
 * @param options A vector of strings containing the options to choose from.
 * @return The string of the selected option. Returns an empty string if options are empty.
 */
std::string selectFromList(const std::string& title, const std::vector<std::string>& options);

} // namespace ui

#endif // MENU_H