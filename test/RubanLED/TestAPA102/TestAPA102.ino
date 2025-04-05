struct pix
{
    byte r;
    byte g;
    byte b;
    byte alpha; // code sur 5bit
};

const int datapin = 22;
const int clockpin = 23;
pix pixels[300];

void setup()
{
    pinMode(datapin, OUTPUT);
    pinMode(clockpin, OUTPUT);
}

void loop()
{
}

void writeOct(byte octet)
{
    for (char i = 0; i < 8; i++)
    {
        digitalWrite(clockpin, LOW);
        digitalWrite(datapin, octet & 1);
        octet = octet >> 1;
        digitalWrite(clockpin, HIGH);
        delayMicroseconds(2);
    }
}

void writeFrame(struct pix)
{
    writeOct(pix.r);
    writeOct(pix.g);
    writeOct(pix.b);
    writeOct(pix.alpha | 0b11100000);
}

void writeArray(struct pix[300], uint16_t length)
{
    writeOct(0);
    writeOct(0);
    writeOct(0);
    writeOct(0);
    for(uint16_t i  = 0; i <= length; i++)
    {
        writeFrame(pix[i])
    }
    writeOct(0xFF);
    writeOct(0xFF);
    writeOct(0xFF);
    writeOct(0xFF);
}