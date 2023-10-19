# 541_Project_2
Receiver Working Idea:
A message frame consists of a 4 bit start flag, a integer number of bytes that represents a message, and a 1 byte end flag as shown below.
```
...0000    1010    10100100 00000000 0000...  
...idle|start flag| message|end flag|idle...
```
The start flag serves 2 purposes:
1) tells the receiver when the message is ready to send
2) allows the receiver to calculate the bitrate of the message.

In order to calculate the bitrate of the message, the start flag is a series of four bit flips: ...idle\(0\)->1->0->1->0...
The times taken between bit flips are measured by the receiver, the average time is taken, and the reciprocal of that value is the frequency at which
the receiver will assume the message is being received.

At the transmitter side, the arduino should be set up so that a message can be typed out on one line, then sent by pressing the enter button.
