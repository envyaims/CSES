n = int(input())
print(0)
now = 0
add = 2
for i in range(2,n+1):
    print((i*i*(i*i-1)//2 - 4*now))
    now += add
    add += 2
