
def multiplicaRecursiva(num, test, r, maior):
    if test > 0:
        r += maior
        return  multiplicaRecursiva(num, test-1, r, maior) 
    if num[0] < 0 and num[1] > 0 or num[0] > 0 and num[1] < 0:
        return r * (-1)  
    else:
        return r

num = [int(input("Digite o primeiro número: ")), int(input("Digite o segundo número: "))]
r = 0
if num[0] >= 0 and num[1] >= 0:
    if num[0] > num[1]:
        test = num[1]
        maior = num[0]
    elif num[0] < num[1]:
        test = num[0]
        maior = num[1]
    else:
        test = num[0]
        maior = num[0]
elif num[0] < 0 and num[1] >= 0: 
    test = num[1]
    maior = num[0] * (-1) 
elif num[1] < 0 and num[0] >= 0:
    test = num[0]
    maior = num[1] * (-1) 
else: 
    test = num[0] * (-1)
    maior = num[1] * (-1)               
print(num[0], "x", num[1], "=", multiplicaRecursiva(num, test, r, maior))