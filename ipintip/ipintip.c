#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCT 8
#define NOCT 4
#define IP 1
#define NUM 2

int main(int argc, char *argv[]) {
	unsigned ip = 0;
	int addr[4];

    int convert;

	if(argc > 1) {
        char *octet;
        if (strchr(argv[1], '.') == NULL) {
		    ip = atoi(argv[1]);
            convert = NUM;
        } else {
            int i = 0;
            for (octet = strtok(argv[1], ".");
                    octet != NULL;
                    octet = strtok(NULL, "."))
                addr[i++] = atoi(octet);
            
            convert = IP;
        }
	} else {
		fprintf(stderr, "error: usage %s ip_address/int_number", argv[0]);
		exit(1);
	}

    int t = NOCT;
    if (convert == NUM) {
    	while(t--) {
    		addr[NOCT - 1 - t] = ( ip << ( OCT * ( NOCT - 1 - t ) ) ) >> (OCT * 3);
    		fprintf(stdout, "%d%c", addr[NOCT - 1 - t], (t)?'.':'\n');
    	}
    } else if (convert == IP) {
        while (t--) {
            ip |= addr[t] << (NOCT - t - 1) * OCT;
        }
        fprintf(stdout, "%u\n", ip);
    }

	return 0;
}

