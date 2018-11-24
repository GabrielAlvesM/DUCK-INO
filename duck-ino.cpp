#define KEY_LEFT_CTRL 0x01
#define KEY_LEFT_SHIFT 0x02
#define KEY_LEFT_ALT 0x04
#define KEY_LEFT_GUI 0x08
#define KEY_RIGHT_CTRL 0x10
#define KEY_RIGHT_SHIFT 0x20
#define KEY_RIGHT_ALT 0x40
#define KEY_RIGHT_GUI 0x80
#define KEY_RIGHT_ARROW 0x4F
#define KEY_LEFT_ARROW 0x50
#define KEY_DOWN_ARROW 0x51
#define KEY_UP_ARROW 0x52
#define KEY_ESC 0x29
#define KEY_F1 0x3A
#define KEY_F2 0x3B
#define KEY_F3 0x3C
#define KEY_F4 0x3D
#define KEY_F5 0x3E
#define KEY_F6 0x3F
#define KEY_F7 0x40
#define KEY_F8 0x41
#define KEY_F9 0x42
#define KEY_F10 0x43
#define KEY_F11 0x44
#define KEY_F12 0x45
#define KEY_PRTSCR 0x46
#define KEY_SCRLK 0x47
#define KEY_PAUSE 0x48
#define KEY_DEL 0x4C
#define KEY_INS 0x49
#define KEY_END 0x4D
#define KEY_HOME 0x4A
#define KEY_PGDN 0x4E
#define KEY_PGUP 0x4B
#define KEY_BACKSPC 0x2A
#define KEY_TAB 0x2B
#define KEY_ENTER 0x28
#define KEY_SPC 0x2C
#define KEY_MUTE 0x7F
#define KEY_VOL_UP 0x80
#define KEY_VOL_DOWN 0x81
#define KEY_NONE 0x37
#define LED 13

uint8_t buf[8] = {0}; /* Keyboard report buffer */

void setup();
void loop();
void STRING(char *);
void DELAY(unsigned t);
void CTRL_ALT(char *c);
void ENTER();
void WINDOWS(char *c);
void CTRL_ALT_DEL();
void ALT_F2();
void TAB();
void F11();
void CTRL_SHIFT_ENTER();
void LEFT();
void CTRL_ESC();

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    delay(300);
    digitalWrite(LED, LOW);
    delay(1000);
}

void loop()
{
    /*-----------------------PAYLOADS-------------------------*/

    //ALT+F4
    /*ALT_F4();
    delay(100);
    ENTER();*/

     //SHUTDOWN IN LINUX
    /*CTRL_ALT("t");
    delay(300);
    STRING("shutdown -P now");
    delay(100);
    ENTER();*/

    //FIND FILES
    /*WINDOWS("r");
    delay(300);
    STRING("cmd");
    delay(150);
    ENTER();
    delay(300);
    STRING("dir /s file *.*; file *.*");
    delay(150);
    ENTER();*/

     //OPEN WEB SITE
    /*WINDOWS("r");
    delay(100);
    STRING("www.thecuriosityworkshop.com/wp-content/uploads/2015/03/01-rubberduck-hongkong.jpg"); // rubberduck
    //STRING("www.youtube.com/watch?v=dQw4w9WgXcQ"); //Never Gonna Give You Up
    delay(350);
    ENTER();*/

    //UPDATE SCREEN
    /*WINDOWS("r");
    delay(150);
    STRING("iexplore -k http://fakeupdate.net/win10u/index.html");
    delay(300);
    ENTER();*/

    delay(1000);

    digitalWrite(LED, HIGH);
    /*-----------------DELAY TO END--------------------*/
    delay(90000);
    /*---------------------END-------------------------*/
}

void STRING(char *txt)
{
    while (*txt)
    {
        if (*txt >= 'a' && *txt <= 'z')
        {
            buf[2] = *txt - 'a' + 4;
        }
        else if (*txt >= 'A' && *txt <= 'Z')
        {
            buf[0] = KEY_LEFT_SHIFT;

            buf[2] = *txt - 'A' + 4;
        }
        else if (*txt >= '0' && *txt <= '9')
        {
            if (*txt == '0')
            {
                buf[2] = *txt - 9;
            }
            else
            {
                buf[2] = *txt - 19;
            }
        }
        else if (*txt == ' ')
        {
            buf[2] = KEY_SPC;
        }
        else if (*txt == '&')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x24;
        }
        else if (*txt == '>')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = KEY_NONE;
        }
        else if (*txt == '<')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x36;
        }
        else if (*txt == '|')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x64;
        }
        else if (*txt == '/')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x14;
        }
        else if (*txt == '?')
        {
          buf[0] = KEY_LEFT_SHIFT;
          buf[2] = 0x55;
        }
        else if (*txt == '\\')
        {
            buf[2] = 0x34;
        }
        else if (*txt == ';')
        {
            buf[2] = 0x38;
        }
        else if (*txt == '(')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x26;
        }
        else if (*txt == ')')
        {
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x27;
        }
        else if (*txt == '{')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x24;
        }
        else if (*txt == '}')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x27;
        }
        else if (*txt == '[')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x25;
        }
        else if (*txt == ']')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x26;
        }
        else if (*txt == '-')
        {
            buf[2] = 0x2D;
        }
        else if (*txt == '=')
        {
            buf[2] = 0x2E;
        }
        else if (*txt == ':')
        {
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x33;
        }
        else if (*txt == '.')
        {
            buf[2] = 0x37;
        }
        else if (*txt == ',')
        {
            buf[2] = 0x36;
        }
        else if (*txt == '*')
        {
            buf[2] = 0x55;
        }
        else
        {
            buf[2] = KEY_NONE;
        }

        Serial.write(buf, 8); // Send keypress
        buf[0] = 0;
        buf[2] = 0;
        Serial.write(buf, 8); // Release key
        txt++;
    }
}

void DELAY(unsigned t)
{
    delay(t);
}
void ALT_F4()
{
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_F4;

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void CTRL_ALT(char *c)
{
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = c[0] - 'a' + 4;

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}

void WINDOWS(char *c)
{
    buf[0] = KEY_LEFT_GUI;

    if (c[0] >= 'a' && c[0] <= 'z')
    {
        buf[2] = c[0] - 'a' + 4;
    }

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}

void ENTER()
{
    buf[2] = KEY_ENTER;

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}

void CTRL_ALT_DEL()
{
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = 0x63;

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}

void ALT_TAB()
{
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_TAB;

    Serial.write(buf, 8); // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void PRINT_SCREEN()
{
    buf[2] = KEY_PRTSCR;

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void F11() //press F11 key
{
    buf[2] = KEY_F11;

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void CTRL_ESC() //open start menu
{
    buf[0] = KEY_LEFT_CTRL;
    buf[2] = KEY_ESC;

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void CTRL_SHIFT_ENTER() //open programs with adm
{
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_SHIFT;
    buf[2] = 0x28;

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void ARROW_UP(){
    buf[0] = KEY_UP_ARROW; //press arrow for up

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void ARROW_DOWN(){
    buf[0] = KEY_DOWN_ARROW; //press arrow for down

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void ARROW_RIGHT(){
    buf[0] = KEY_RIGHT_ARROW; //press arrow for right

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
void ARROW_LEFT()
{
    buf[0] = KEY_LEFT_ARROW; //press arrow for left

    Serial.write(buf, 8);
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}
