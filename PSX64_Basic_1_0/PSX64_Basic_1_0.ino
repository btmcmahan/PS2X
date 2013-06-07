#include <PSX64_lib.h>
PSX64 psx64;
 
byte vibrate = 0;

void setup(){
  Serial.begin(57600);
  psx64.config_gamepad(24,22,25,23, true, true);   //(7_clock=51)(2_command=47)(6_attention=45)(1_data=49)(9_ack=53), Pressures?, Rumble?) check for error
}

void loop(){
  psx64.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    
  if(psx64.Button(PSB_START))                   //will be TRUE as long as button is pressed
    Serial.println("Start is being held");
  if(psx64.Button(PSB_SELECT))
    Serial.println("Select is being held");
  if(psx64.Button(PSB_PAD_UP)){         //will be TRUE as long as button is pressed
    Serial.print("Pad Up");}
  if(psx64.Button(PSB_PAD_RIGHT)){
    Serial.print("Pad Right");}
  if(psx64.Button(PSB_PAD_LEFT)){
    Serial.print("Pad Left");}
  if(psx64.Button(PSB_PAD_DOWN)){
    Serial.print("Pad Down");}   
 if(psx64.Button(PSB_L3))
    Serial.println("L3 pressed");
  if(psx64.Button(PSB_R3))
    Serial.println("R3 pressed");
  if(psx64.Button(PSB_L2))
    Serial.println("L2 pressed");
  if(psx64.Button(PSB_R2))
    Serial.println("R2 pressed");
  if(psx64.Button(PSB_TRIANGLE))
    Serial.println("Triangle pressed");   
  if(psx64.ButtonPressed(PSB_CIRCLE))             //will be TRUE if button was JUST pressed
    Serial.println("Circle just pressed");
  if(psx64.ButtonReleased(PSB_SQUARE))             //will be TRUE if button was JUST released
    Serial.println("Square just released");     
  if(psx64.NewButtonState(PSB_CROSS))            //will be TRUE if button was JUST pressed OR released
    Serial.println("X just changed");    
    
  if(psx64.Button(PSB_L1) || psx64.Button(PSB_R1)){
    Serial.print("Stick Values:");
    Serial.print(psx64.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
    Serial.print(",");
    Serial.print(psx64.Analog(PSS_LX), DEC); 
    Serial.print(",");
    Serial.print(psx64.Analog(PSS_RY), DEC); 
    Serial.print(",");
    Serial.println(psx64.Analog(PSS_RX), DEC);}
 
  vibrate = psx64.Analog(PSAB_CROSS);        //large motor vibrate speed=(X)button analog
  delay(50);
}
