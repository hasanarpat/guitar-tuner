#define LENGTH 512

byte rawData[LENGTH];
int count;
char noteName;

int len = sizeof(rawData);
int i, k;
long sum, sum_old;
int thresh = 0;
float freq_per = 0;

byte pd_state = 0;

char testput;
String out = “b— - [[]]—- #”;
int octave_counter;

float Note;
float C = 16.35;
float D = 18.35;
float E = 20.60;
float F = 21.83;
float G = 24.50;
float A = 27.50;
float B = 30.87;

void setup()
{
    Serial.begin(115200);

    analogReference(EXTERNAL); // Connect to 3.3V analogRead(A0);

    count = 0;
}
float freq;
void loop()
{
    if (count < LENGTH)
    {
        count++;
        rawData[count] = analogRead(A0) >> 2;
    }
    else
    {
        sum = 0;
        pd_state = 0;
        int period = 0;
        for (i = 0; i < len; i++)
        {

            // Peak Detect

            // Filter out frequencies that are too high
        }
        count = 0;
        Serial.println(freq);
        displayToLCD(freq);
        delay(400);
    }
}

void displayToLCD(float freq)
{
    if (freq == -1)
    {
        return;
    }

    if (freq >= 15.89)
    {

        if ((15.89 <= Ffreq) & (Ffreq <= 17.34))
        {
            Note = C;
            noteName = ‘C’;
        }
        else if ((17.35 <= Ffreq) & (Ffreq < 19.475))
        {
            Note = D;
            noteName = ‘D’;
        }
        else if ((19.475 <= Ffreq) & (Ffreq < 21.215))
        {
            Note = E;
            noteName = ‘E’;
        }
        else if ((21.215 <= Ffreq) & (Ffreq < 23.185))
        {
            Note = F;
            noteName = ‘F’;
        }
        else if ((23.185 <= Ffreq) & (Ffreq < 26.00))
        {
            Note = G;
            noteName = ‘G’;
        }
        else if ((26.00 <= Ffreq) & (Ffreq < 29.185))
        {
            Note = A;
            noteName = ‘A’;
        }
        else if ((29.185 <= Ffreq) & (Ffreq < 31.785))
        {
            Note = B;
            noteName = ‘B’;
        }

        float closeness0 = (Ffreq / Note);
        int cl1 = 0;
        cl1 = int((closeness0 - 1) * 100);

        lcd.setCursor(3, 0);
        lcd.print(freq);
        lcd.setCursor(11, 0);
        lcd.print(“Hz”);
        lcd.setCursor(0, 1);
        lcd.print(out);
        lcd.setCursor(7, 1);
        lcd.print(noteName);
        lcd.setCursor(8, 1);
        lcd.print(octave_counter);
    }

    float getFfreq(float freq)
    {
        octave_counter++;
        if (freq > B)
        {
            return getFfreq(freq / 2);
        }
        else
            return freq;
    }
}