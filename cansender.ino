
#include <mcp2515.h>

struct can_frame frame;
MCP2515 mcp2515_send(3);
MCP2515 mcp2515_recieve(2);


void setup() {
  Serial.begin(9600);
  mcp2515_send.reset();
  mcp2515_send.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515_send.setNormalMode();

  mcp2515_recieve.reset();
  mcp2515_recieve.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515_recieve.setNormalMode();

  Serial.print("hello arduino nano is starting\n");

  frame.can_id = 0x000;
  frame.can_dlc = 5;
  frame.data[0] = 'h';
  frame.data[1] = 'e';
  frame.data[2] = 'l';
  frame.data[3] = 'l';
  frame.data[4] = 'o';
  // put your setup code here, to run once:

}

void loop() {
  //mcp2515_send.sendMessage(&frame);
  delay(100);

  Serial.print("attemepting the read again\n");
  struct can_frame theMessage;
  MCP2515::ERROR theError;

  if ((theError = mcp2515_recieve.readMessage(&theMessage)) == MCP2515::ERROR_OK) {
    for (int i = 0; i < theMessage.can_dlc; i+=2) {
      Serial.print((float)word(theMessage.data[i], theMessage.data[i + 1]));
      Serial.print(" ");
    }
    Serial.print("\n");
  }
  Serial.print("the error was ");
  Serial.print(theError);
  Serial.print("\n");
  //put your main code here, to run repeatedly:

}
