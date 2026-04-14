/*
Greedy digit adjustment
Time: O(d), d = number of digits
*/

int monotoneIncreasingDigits(int n) {
    char s[20];
    sprintf(s, "%d", n);

    int len = strlen(s);
    int mark = len;

    for (int i = len - 1; i > 0; i--) {
        if (s[i] < s[i - 1]) {
            s[i - 1]--;
            mark = i;
        }
    }

    for (int i = mark; i < len; i++)
        s[i] = '9';

    return atoi(s);
}