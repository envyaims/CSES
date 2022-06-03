num = int(input())
nums = [str(num)]
while True:
    if num % 2 == 0:
        num //= 2
        nums.append(str(num))
    else:
        if num == 1:
            nums.append(str(num))
            break
        else:
            num = (num*3) + 1
            nums.append(str(num))
nums.pop()
print(" ".join(nums))

