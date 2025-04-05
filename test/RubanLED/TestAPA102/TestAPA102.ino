struct pix
{
    byte r;
    byte g;
    byte b;
    byte alpha; // code sur 5bit
};

const int datapin = 22;
const int clockpin = 23;

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

}

void writeFrame(struct pix)
{
    writeOct(pix.r);
    writeOct(pix.g);
    writeOct(pix.b);
    writeOct(pix.alpha|0b11100000);
}

void writeArray(struct pix[300], uint16_t length)
{
}