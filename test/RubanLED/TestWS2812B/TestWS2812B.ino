struct pix
{
    byte r;
    byte g;
    byte b;
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

void writePix(struct pix)
{
    writeOct(pix.r);
    writeOct(pix.g);
    writeOct(pix.b);
}

void writeArray(struct pix[300], uint16_t length)
{
}