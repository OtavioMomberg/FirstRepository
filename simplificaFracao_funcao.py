import os
def simplificaFracao(n1,d1):
    a = d1
    b = n1
    cont = 2
    if a > 0 and b > 0:
        while True:
            if a % cont != 0 or b % cont != 0: 
                cont += 1
                if cont == a + 1 or a == 1 or b == 1:
                    print("Fração irredutivel")
                    break   
            elif a % cont == 0 and b % cont == 0:
                if a != b:
                    if a > b:
                        cont = b 
                    elif a < b:
                        cont = a
                    while True:
                        if a % cont != 0 or b % cont != 0:
                            cont -= 1
                        elif a % cont == 0 and b % cont == 0:
                            a //= cont
                            b //= cont
                            break         
                else:
                    a //= a
                    b //= b
                    d1 = d1 // n1
                break
            elif a % cont != 0 or b % cont != 0:
                print("Fração irredutivel")
                break 
    p = (b * 100) // a            
    if a != d1 and b != n1 and a > 1:
        print("Sua fração simplificada:", str(b) + "/" + str(a))
    elif a != d1 and b != n1 and a == 1:
        print("Sua fração simplificada:", b, "ou", str(b) + "/" + str(a))       
    elif a == b:
        print("Sua fração simplificada:", str(a) + "/" + str(b), "ou:", d1) 
while True:           
    n = int(input('Insira o numerador da fração: '))
    d = int(input('Insira o denominador da fração: '))
    os.system("cls")
    if n > 0 and d > 0:
        break
print('Sua fração:', str(n) + '/' + str(d))
simplificaFracao(n,d)