// Declare the buttons’ pin.
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 3;
const int buttonPin4 = 5;
const int buttonPin5 = 7;
const int buttonPin6 = 6;
// Echo Pin for ultrasonic sensor
const int echo = 11;
// Trigger Pin for ultrasonic sensor
const int trig = 12;
// Duration used to calculate distance for ultrasonic sensor
long travel_time, distance;
boolean sendmail = true;
// variable for reading the pushbutton status
int buttonState1 = 0;        
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;       
int buttonState5 = 0;
int buttonState6 = 0;

void setup() {
  // Initialize the pin mode
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  // Check if the pushbutton is pressed. If it is, the buttonState is HIGH. Then print a string value accordingly, which will also be a trigger for the processing display output.
  if (buttonState1 == HIGH) {
    Serial.print("button1pressed");
    delay (500);
  }
  if (buttonState2  == HIGH) {
    Serial.print("button2pressed");
    delay (500);
  }
  if (buttonState3  == HIGH) {
    Serial.print("button3pressed");
    delay (500);
  }
  if (buttonState4  == HIGH) {
    Serial.print("button4pressed");
    delay (500);
  }
  if (buttonState5  == HIGH) {
    Serial.print("button5pressed");
    delay (500);
  }
  if (buttonState6  == HIGH) {
    Serial.print("button6pressed");
    delay (500);
  }
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sending a high pulse to trigger the Ultrasound Module
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  travel_time = pulseIn(echo, HIGH);
  // Calculating the distance by using the travel time of the sound
  distance = (travel_time * 0.034) / 2;
  // Sending the distance to the computer.
  Serial.println(distance);
 // If the distance is between 100 and 150 it will print send, which will also send an email in processing.
  if (distance < 150 && distance > 100 && sendmail) {
    Serial.print("send");
    sendmail = false;
  }
  // Delay for the next reading.
  delay(30);
}

Processing Code
*I used the in-code comment to explain my code. Ex: // Code Explanation


// Import all the external Processing 3 APIs. Temboo is for connecting with the internet, and processing.serial is for communicating with Arduino.
import com.temboo.core.*;
import com.temboo.Library.Google.Gmail.*;
import processing.serial.*;
// Create a session using my Temboo account application details
TembooSession session = new TembooSession("chenjingle525", "myFirstApp", "s7BqzMhd1l5QKLTLJCUAFFnKc9HAVJHq");
// The name of my Temboo Google Profile 
String googleProfile = "test";
// Declare the basic information for sending an email. 
String fromAddress = "Community Connect Team <chenjingle0525@gmail.com>";
String toAddress = "chenjingle0525@gmail.com";
String subject = "Result from your community connect tool kit";
// Declare the main content of the email.
String messageBody = "Hello, \n\nHere is your result (raw data): ";
String nxtLn = "\n";
String reaction1 = "Reaction1: https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Sad_Emoji_large.png?v=1542436016 \n";
String reaction2 = "Reaction2: https://cdn.shopify.com/s/files/1/1061/1924/products/Shy_Emoji_Icon_dcff66a2-08f2-45c6-a77c-cd86b54f02b4_large.png?v=1542436015 \n";
String reaction3 = "Reaction3: https://cdn.shopify.com/s/files/1/1061/1924/products/Crying_Emoji_Icon_2_large.png?v=1542436033 \n";
String reaction4 = "Reaction4: https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Smiling_large.png?v=1542446805 \n";
String reaction5 = "Reaction5: https://cdn.shopify.com/s/files/1/1061/1924/products/Thumbs_Down_Sign_Emoji_Icon_ios10_large.png?v=1542435999 \n";
String reaction6 = "Reaction6: https://cdn.shopify.com/s/files/1/1061/1924/products/Heart_Eyes_Emoji_2_large.png?v=1542446801 \n";
// Declare the variables for visualization
int counter = 0;
boolean isEmailSend = false;
// Declare emoji related variables
PImage emoji1, emoji2, emoji3, emoji4, emoji5, emoji6;
String url1 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Sad_Emoji_large.png?v=1542436016";
String url2 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Shy_Emoji_Icon_dcff66a2-08f2-45c6-a77c-cd86b54f02b4_large.png?v=1542436015";
String url3 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Crying_Emoji_Icon_2_large.png?v=1542436033";
String url4 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Smiling_large.png?v=1542446805";
String url5 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Thumbs_Down_Sign_Emoji_Icon_ios10_large.png?v=1542435999";
String url6 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Heart_Eyes_Emoji_2_large.png?v=1542446801";
// Variables for connecting with Arduino
Serial myPort;
String serialValue;

void setup() {
 // Set up Arduino
  myPort = new Serial(this, "COM3", 9600);
  // Set up the visalization
  size (1200,1200);
  strokeWeight(4);
  smooth();
  background(0);
  emoji1 = loadImage(url1, "png");
  emoji2 = loadImage(url2, "png");
  emoji3 = loadImage(url3, "png");
  emoji4 = loadImage(url4, "png");
  emoji5 = loadImage(url5, "png");
  frameRate(5);
}
void draw() {
 // If the button pressed, the display window will show an emoji accordingly.
  if (myPort.available() > 0) {
  serialValue = myPort.readString();
  if (serialValue.contains("button1pressed")) {
    image(emoji2, random(0,1150), random(0,1150), 50, 50);
    print("1");
    messageBody = messageBody + "1";
  }
  if (serialValue.contains("button2pressed")) {
    image(emoji1, random(0,1150),random(0,1150),50,50);
    print("2");
    messageBody = messageBody + "2";
  }
   if (serialValue.contains("button3pressed")) {
    image(emoji3, random(0,1150),random(0,1150),50,50);
    print("3");
    messageBody = messageBody + "3";
  } 
  if (serialValue.contains("button4pressed")) {
    image(emoji4, random(0,1150),random(0,1150),50,50);
    print("4");
    messageBody = messageBody + "4";
  }
  if (serialValue.contains("button5pressed")) {
    image(emoji5, random(0,1150),random(0,1150),50,50);
    print("5");
    messageBody = messageBody + "5";
  }
 }

// Visualization by pressing the keyboard
  if (keyPressed) {
    if (key == 'q' || key == 'Q') {
      image(emoji1, random(0,1150), random(0,1150), 50, 50);
      print("1");
      messageBody = messageBody + "1";
    }  // emoji1 end
    if (key == 'w' || key == 'W') {
      image(emoji2, random(0,1150),random(0,1150),50,50);
      print("2");
      messageBody = messageBody + "2";
    } // emoji2 end
    if (key == 'e' || key == 'E') {
      image(emoji3, random(0,1150),random(0,1150),50,50);
      print("3");
      messageBody = messageBody + "3";
    } // emoji3 end
    if (key == 'r' || key == 'R') {
      image(emoji4, random(0,1150),random(0,1150),50,50);
      print("4");
      messageBody = messageBody + "4";
    } // emoji4 end
    if (key == 't' || key == 'T') {
      image(emoji5, random(0,1150),random(0,1150),50,50);
      print("5");
      messageBody = messageBody + "5";
    } // emoji5 end
    if (key == 'y' || key == 'Y') {
      image(emoji6, random(0,1150),random(0,1150),50,50);
      print("6");
      messageBody = messageBody + "6";
    } // emoji6 end
  } // Visualization end 
 // If the data received from Arduino contains send, the program will send an email to the specific email account.
  if (serialValue.contains("send") && isEmailSend == false) {
    messageBody = messageBody + "\n\nEach number means a specific reaction. \n\nThe one you chose are: ";
 // Build the main content of the email.
    messageBody = messageBody + nxtLn + nxtLn + reaction1 + nxtLn + reaction2 + nxtLn + reaction3 + nxtLn + reaction4 + nxtLn + reaction5 + nxtLn + reaction6 + nxtLn;
    // Send an email
    runSendEmailChoreo();
  // If the email is send, set the boolean isEmailSend to true, so it won’t send another one.
    isEmailSend = true;
  }
} // draw end
void runSendEmailChoreo() {
  // Create the Choreo object using your Temboo session
  SendEmail sendEmailChoreo = new SendEmail(session);
  // Set Profile
  sendEmailChoreo.setCredential(googleProfile);
  // Set inputs
  sendEmailChoreo.setMessageBody(messageBody);
  sendEmailChoreo.setSubject(subject);
  sendEmailChoreo.setFromAddress(fromAddress);
  sendEmailChoreo.setToAddress(toAddress);
  // Run the Choreo and store the results
  SendEmailResultSet sendEmailResults = sendEmailChoreo.run();
  // Print results
  println(sendEmailResults.getSuccess());
}


