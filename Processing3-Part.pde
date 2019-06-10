import com.temboo.core.*;
import com.temboo.Library.Google.Gmail.*;
import processing.serial.*;

// Create a session using your Temboo account application details
TembooSession session = new TembooSession("chenjingle525", "myFirstApp", "s7BqzMhd1l5QKLTLJCUAFFnKc9HAVJHq");

// The name of your Temboo Google Profile 
String googleProfile = "test";

// Declare the strings for your email
String fromAddress = "Community Connect Team <chenjingle0525@gmail.com>";
String toAddress = "chenjingle0525@gmail.com";
String subject = "Result from your community connect tool kit";
String messageBody = "Hello, \n\nHere is your result (raw data): ";
String nxtLn = "\n";
String reaction1 = "Reaction1: https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Sad_Emoji_large.png?v=1542436016 \n";
String reaction2 = "Reaction2: https://cdn.shopify.com/s/files/1/1061/1924/products/Shy_Emoji_Icon_dcff66a2-08f2-45c6-a77c-cd86b54f02b4_large.png?v=1542436015 \n";
String reaction3 = "Reaction3: https://cdn.shopify.com/s/files/1/1061/1924/products/Crying_Emoji_Icon_2_large.png?v=1542436033 \n";
String reaction4 = "Reaction4: https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Smiling_large.png?v=1542446805 \n";
String reaction5 = "Reaction5: https://cdn.shopify.com/s/files/1/1061/1924/products/Thumbs_Down_Sign_Emoji_Icon_ios10_large.png?v=1542435999 \n";
String reaction6 = "Reaction6: https://cdn.shopify.com/s/files/1/1061/1924/products/Heart_Eyes_Emoji_2_large.png?v=1542446801 \n";

// Variables for visualization
int counter = 0;
boolean isEmailSend = false;
PImage emoji1, emoji2, emoji3, emoji4, emoji5, emoji6;
String url1 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Sad_Emoji_large.png?v=1542436016";
String url2 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Shy_Emoji_Icon_dcff66a2-08f2-45c6-a77c-cd86b54f02b4_large.png?v=1542436015";
String url3 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Crying_Emoji_Icon_2_large.png?v=1542436033";
String url4 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Emoji_Icon_-_Smiling_large.png?v=1542446805";
String url5 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Thumbs_Down_Sign_Emoji_Icon_ios10_large.png?v=1542435999";
String url6 = "https://cdn.shopify.com/s/files/1/1061/1924/products/Heart_Eyes_Emoji_2_large.png?v=1542446801";

// Variables for Arduino
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
  //emoji6 = loadImage(url6, "png");
  frameRate(5);
}
void draw() {
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

// Visalization
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
  } // visalization end 
  //counter = counter + 1;
  if (serialValue.contains("send") && isEmailSend == false) {
    messageBody = messageBody + "\n\nEach number means a specific reaction. \n\nThe one you chose are: ";
    messageBody = messageBody + nxtLn + nxtLn + reaction1 + nxtLn + reaction2 + nxtLn + reaction3 + nxtLn + reaction4 + nxtLn + reaction5 + nxtLn + reaction6 + nxtLn;
    // send email to my Gmail
    runSendEmailChoreo();
    isEmailSend = true;
  } // after number of "counter" frame send an eamil to myGamil
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
