def modpower(a, b, m):
    print "a: %d b: %d" % (a, b)
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return modpower((a * a) % m, b >> 1, m)
    else:
        return (a * modpower((a * a) % m, b >> 1, m)) % m

print modpower(8, 11, 8589934593)

