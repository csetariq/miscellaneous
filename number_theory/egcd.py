def egcd(a, b):
    if (b == 0):
        return (a, 1, 0)
    else:
        gcd, x, y = egcd(b, a % b)
        return (gcd, y, x - (a / b) * y)

def modinv(a, m):
    gcd, x, y = egcd(a, m)
    if gcd != 1:
        return None
    else:
        return x % m;

print egcd(888, 54)
print modinv(11, 26)

