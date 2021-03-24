// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char nafn[10] = {'S', 'v', 'e', 'i', 'n', 'n',' ', 'O', 'l', 'i'};


void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);

  // Clears the LCD screen
  lcd.clear();
}

void loop() 
{
  // Print a message to the LCD.
  lcd.setCursor(0, 1);
  lcd.print("Tolvubraut");

   lcd.setCursor(0, 0);
  for (int i=0; i<sizeof nafn/sizeof nafn[0]; i++) {
    lcd.print(nafn[i]);
    delay(500);
  }
  lcd.clear();
  

  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

}
