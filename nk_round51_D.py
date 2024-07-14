def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
a=int(input())
b=int(input())
res=gcd(a,b)
print(res)
