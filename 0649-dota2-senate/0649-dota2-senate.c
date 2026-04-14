/*
Queue simulation
Time: O(n)
*/

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    int radiant[10000], dire[10000];
    int rFront = 0, rRear = 0, dFront = 0, dRear = 0;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            radiant[rRear++] = i;
        else
            dire[dRear++] = i;
    }

    while (rFront < rRear && dFront < dRear) {
        int r = radiant[rFront++];
        int d = dire[dFront++];

        if (r < d)
            radiant[rRear++] = r + n;
        else
            dire[dRear++] = d + n;
    }

    return (rFront < rRear) ? "Radiant" : "Dire";
}