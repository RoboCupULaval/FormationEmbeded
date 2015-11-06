//The setup function is called once at startup of the sketch
int btnStart = 1;

#include

void setup()
{
	attachInterrupt(btnStart, start, LOW);

}

void loop()
{
	lectureLignes()
}
