/*
Track last occurrence of each digit
Time: O(n)
*/

int maximumSwap(int num) {
    char s[20];
    sprintf(s, "%d", num);

    int last[10];
    for (int i = 0; i < 10; i++) last[i] = -1;

    for (int i = 0; s[i]; i++)
        last[s[i] - '0'] = i;

    for (int i = 0; s[i]; i++) {
        for (int d = 9; d > s[i] - '0'; d--) {
            if (last[d] > i) {
                char temp = s[i];
                s[i] = s[last[d]];
                s[last[d]] = temp;
                return atoi(s);
            }
        }
    }

    return num;
}