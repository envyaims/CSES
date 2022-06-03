# 1. weird algorithm
# num = int(input())
# nums = [str(num)]
# while True:
#     if num % 2 == 0:
#         num //= 2
#         nums.append(str(num))
#     else:
#         if num == 1:
#             nums.append(str(num))
#             break
#         else:
#             num = (num*3) + 1
#             nums.append(str(num))
# nums.pop()
# print(" ".join(nums))

#2. Missing Number
# input()
# num = input().split(' ')
# nums = sorted([int(i) for i in num])
# if nums.count(1) == 0:
#     print(1)
# elif nums.count(len(nums)+1) == 0:
#     print(len(nums)+1)
# for i in range(len(nums)-1):
#     if nums[i] + 1 != nums[i+1]:
#         print(nums[i] + 1)
#         break

num = int(input())
print((2 ** num) % 1000000007)


