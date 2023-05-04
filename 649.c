#include <stdio.h>
#include <string.h>

char * predictPartyVictory(char * senate){
    char *p = senate;
    int table[2] = {0}; //0=='D', 1=='R'
    for(int i = 0;i < strlen(senate); i++)
        senate[i]=='D' ? table[0]++ : table[1]++;
    while(table[0] && table[1])
    {
        if(*p=='D')
        {
            char *q = strchr(p,'R'); //Find next senator who hasn't votes and is the other party.
            q = q ? q : strchr(senate,'R'); //If everyone has votes, find a senator from first.
            *q = '-'; //Ban that senator.
            table[1]--;
        }
        else if(*p=='R')
        {
            char *q = strchr(p,'D');//Find next senator who hasn't votes and is the other party.
            q = q ? q : strchr(senate,'D');//If everyone has votes, find a senator from first senator.
            *q = '-'; //Ban that senator.
            table[0]--;
        }
        if(*++p == '\0') //if everyone has voted,but not finish, go to first senator.
            p = senate;
    }
    return table[0] ? "Dire" : "Radiant";
}

int main()
{
    char senate[1001];
    scanf("%s", senate);
    char ans[10];
    strcpy(ans, predictPartyVictory(senate));
    printf("%s\n", ans);
    return 0;
}

/*
Best Solution 
char * predictPartyVictory(char * senate){
    
    // Number of Senators of each party
    int rCount = 0, dCount = 0;

    // Floating Ban Count
    int dFloatingBan = 0, rFloatingBan = 0;

    // Queue of Senators.
    int n = strlen(senate);
    int q[n];
    int front = 0, rear = 0;
    for (int i = 0; senate[i]; i++) {
        if (senate[i] == 'R') rCount++;
        else dCount++;
        q[rear] = senate[i];
        rear = (rear + 1) % n;
    }

    // While any party has eligible Senators
    while (rCount && dCount) {

        // Pop the senator with turn
        char curr = q[front];
        front = (front + 1) % n;

        // If eligible, float the ban on the other party, enqueue again.
        // If not, decrement the floating ban and count of the party.
        if (curr == 'D') {
            if (dFloatingBan) {
                dFloatingBan--;
                dCount--;
            } else {
                rFloatingBan++;
                q[rear] = 'D';
                rear = (rear + 1) % n;
            }
        } else {
            if (rFloatingBan) {
                rFloatingBan--;
                rCount--;
            } else {
                dFloatingBan++;
                q[rear] = 'R';
                rear = (rear + 1) % n;
            }
        }
    }

    // Return the party with eligible Senators
    return rCount ? "Radiant" : "Dire";
}
*/