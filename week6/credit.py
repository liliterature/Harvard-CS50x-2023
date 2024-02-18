n = input('Number: ')

def check(n):
    lenth = len(n)
    odd = 0
    even = 0
    for i in range(lenth - 2, -1, -2):
          m = int(n[i]) * 2
          odd += m // 10 + m % 10
    for i in range(lenth - 1, -1, -2):
          even += int(n[i])
    sum = odd + even
    if sum % 10 == 0:
           # print('legal')
            checkcard()
    else:
        print("INVALID")

def checkcard():
    if n[0:2] in ('34', '37') :
            print("AMEX")
    elif (int(n[0:2]) >= 51 and int(n[0:2]) <= 55):
            print('MASTERCARD')
    elif n[0] == '4':
                print('VISA')
    else:
        print("INVALID")

if len(n) in (13, 15, 16):
     check(n)
else :
       print("INVALID")

