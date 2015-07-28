#include <stdio.h>
#include <string.h>

int is_lucky(char *str) {
    int len = strlen(str);
    for (int i = 2; i < len; ++i) {
        if (str[i] != str[i % 2])
            return 0;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char str[101];
        scanf("%s", str);
        if (is_lucky(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
