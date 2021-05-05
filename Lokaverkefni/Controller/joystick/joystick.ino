const int joystick_x = A0;
const int joystick_y = A1;
const int joystick_button = 2;

int x_axis = 0;
int y_axis = 0;
int joystick_button_state = 0;

void setup() {
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(joystick_button, INPUT_PULLUP); 

  Serial.begin(9600); 
}

void loop() {
  x_axis = analogRead(joystick_x);
  y_axis = analogRead(joystick_y);
  joystick_button_state = digitalRead(joystick_button);
  
  Serial.print("X-axis: ");
  Serial.print(x_axis);
  Serial.print(" | Y-axis: ");
  Serial.print(y_axis);
  Serial.print(" | Button: ");
  Serial.println(joystick_button_state);

  delay(100);
}
