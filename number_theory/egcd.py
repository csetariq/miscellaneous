def egcd(a, b):
    if (b == 0):
        return (a, 1, 0)
    else:
        print "for a:%d b:%d" % (a, b)
        gcd, x, y = egcd(b, a % b)
        print "got %d %d %d" % (gcd, x, y)
        return (gcd, y, x - (a / b) * y)

def modinv(a, m):
    gcd, x, y = egcd(a, m)
    print "mod inv got %d %d %d" % (gcd, x, y)
    if gcd != 1:
        return None
    else:
        return x % m;

print egcd(888, 54)
print modinv(11, 26)

