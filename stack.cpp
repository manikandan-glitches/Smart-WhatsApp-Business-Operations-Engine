#include <stdio.h>
#include <string.h>

#define MAX 10

char back[MAX][50], forward[MAX][50];
int topB = -1, topF = -1;
char current[50] = "Home";

void visit(char page[])
{
    strcpy(back[++topB], current);
    strcpy(current, page);
    topF = -1;
}

void backPage()
{
    if (topB == -1){
	
        printf("No back page\n"); }
    else
    {
        strcpy(forward[++topF], current);
        strcpy(current, back[topB--]);
    }
}

void forwardPage()
{
    if (topF == -1)
        printf("No forward page\n");
    else
    {
        strcpy(back[++topB], current);
        strcpy(current, forward[topF--]);
    }
}

int main()
{
    visit("Google");
    visit("YouTube");
    visit("Wikipedia");

    printf("Current: %s\n", current);

    backPage();
    printf("After Back: %s\n", current);

    backPage();
    printf("After Back: %s\n", current);

    forwardPage();
    printf("After Forward: %s\n", current);

    return 0;
}
