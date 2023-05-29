//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ menuSelect ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function will allow the user to select a menu based on the joystick position, and return a
// variable which will be used to display the correct menu.  The returned variable is called
// menuCount.  This function allows you to control the total number of menus.

int menuSelect(float joystick, int totalMenus) {  // inputs are joystick position and # of menus
  if (joystick > 1000) {
    menuCount = menuCount + 1;  // upon moving the joystick increase the menu variable by 1
    keypadCharacterpadSelection = 0;  // clear the keypadCharacterpad Selection variable
    if (menuCount > totalMenus) {
      menuCount = totalMenus; // the menuCount can't go over the total number of menus
    }
  }

  else if (joystick < 50) {
    menuCount = menuCount - 1;  // decreases the value of menu count by 1
    keypadCharacterpadSelection = 0;
    if (menuCount < 0) {
      menuCount = 0;  // menu count can't go below 0
    }
  }

  else {
    menuCount = menuCount;  // if the joystick didn't move then keep the menu the same
  }

  return menuCount;  // return which menu you are working in.
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
