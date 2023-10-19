# 541_Project_2
Transmission Working Idea:
When only zeros are sent, the transmission signal is considered idle.
A message frame consists of a 4 bit start flag, a integer number of bytes that represents a message, and a 1 byte end flag as shown below.

...0000    1010    10100100 00000000 0000...  
idle|start flag| message|end flag|idle

The start flag serves 2 purposes:
1) tells the receiver when the message is ready to send
2) allows the receiver to calculate the bitrate of the message.
