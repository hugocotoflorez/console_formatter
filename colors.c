#define RESET      0
#define BOLD       1
#define DARK       2
#define UNDERLINE  4
#define BLINK      5
#define NEGATIVE   7
#define BLACK     30
#define RED       31
#define GREEN     32
#define YELLOW    33
#define BLUE      34
#define MAGENTA   35
#define CYAN      36
#define WHITE     37


void colorize(int color)
{
    printf("\033[%dm", color);
}

void format_text(char* format)
{
    printf("\033[%sm", format);
}


void reset()
{
    printf("\033[0m");
}


void bold()
{
    printf("\033[1m");
}


void dark()
{
    printf("\033[2m");
}


void underline()
{
    printf("\033[3m");
}


void blink()
{
    printf("\033[4m");
}


void negative()
{
    printf("\033[5m");
}




