#include <stdio.h>
#include <stdlib.h>

#define FWDTH   100
#define HMINS   60


int is_valid(unsigned time) {
    return time >= 0 && time <= 2400 && (time % 100) < 60;
}

unsigned time_diff(int from, int to) {
    if (!is_valid(from) || !is_valid(to)) {
        fprintf(stderr, "Invalid time. Use HHMM format\n");
        exit(1);
    }
    
    if (from > to) {
        unsigned temp = from;
        from = to;
        to = temp;
    }

    unsigned to_mins = to % FWDTH;
    unsigned to_hrs = to / FWDTH;

    unsigned from_mins = from % FWDTH;
    unsigned from_hrs = from / FWDTH;
    
    unsigned diff_hrs = 0;
    unsigned diff_mins = 0;

    if (to_mins < from_mins) {
        to_mins += HMINS;
        to_hrs--;
    }

    diff_hrs = to_hrs - from_hrs;
    diff_mins = to_mins - from_mins;

    unsigned diff = diff_hrs * FWDTH + diff_mins;

    return diff;
}

char * time_str(unsigned time) {
    char *str = (char *) malloc(6);
    sprintf(str, "%02u:%02u", time / FWDTH, time % FWDTH);
    return str; 
}

int main(int argc, char *argv[]) {
    unsigned from, to, result;
    
    if (argc >= 3) {
        from = (unsigned) atoi(argv[1]);
        to = (unsigned) atoi(argv[2]);
    } else {
        scanf("%u %u", &from, &to);
    }

    char *res = time_str(time_diff(from, to));

    printf("\nDifference %s\n", res);
    return 0;
}
