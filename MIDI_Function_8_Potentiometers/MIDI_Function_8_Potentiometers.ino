int val1 = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal1 = 0;
int val2 = 0; 
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;
int val5 = 0;
int lastVal5 = 0;
int val6 = 0;
int lastVal6 = 0;
int val7 = 0;
int lastVal7 = 0;
int val8 = 0;
int lastVal8 = 0;

void setup()
{
   Serial.begin(9600);       // Set the speed of the midi port to the same as we will be using in the Hairless Midi software 
}

void loop()
{

   val1 = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val1 != lastVal1) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(176,12,val1);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase)
   lastVal1 = val1;
   
   val2 = analogRead(1)/8;   
   if (val2 != lastVal2) 
   {
   MIDImessage(176,13,val2);}         
   lastVal2 = val2;
   
   val3 = analogRead(2)/8;   
   if (val3 != lastVal3) 
   {
   MIDImessage(176,14,val3);}         
   lastVal3 = val3;
   
   val4 = analogRead(3)/8;   
   if (val4 != lastVal4) 
   {
   MIDImessage(176,15,val4);}         
   lastVal4 = val4;
   
   val5 = analogRead(4)/8;   
   if (val5 != lastVal5) 
   {
   MIDImessage(176,16,val5);}         
   lastVal5 = val5;
   
   val6 = analogRead(5)/8;   
   if (val6 != lastVal6) 
   {
   MIDImessage(176,17,val6);}         
   lastVal6 = val6;

   val7 = analogRead(6)/8;   
   if (val7 != lastVal7) 
   {
   MIDImessage(176,18,val7);}         
   lastVal7 = val7;

   val8 = analogRead(7)/8;
   if(val8 != lastVal8)
   {
   MIDImessage(176,19,val8);}
   lastVal8 = val8; 

   delay(10); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent pots from jumping up or down a value when slightly touched or knocked.
}

void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
