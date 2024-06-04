#INPUT
import os
while True:
    inp = [int(input("insiras as horas: ")), int(input("Insira os minutos: ")), int(input("Insira os minutos que passaram: "))]
    os.system("cls")    
    if inp[0] <= 23 and inp[1] <= 59:
        break
#OUTPUT Inicial    
if inp [0] == 0 and inp[1] == 0:
    print("Horário atual: 0" + str(inp[0]) + ":" + str(inp[1]) + "0")    
elif inp[0] > 0 and inp[1] == 0:
    print("Horário atual:", str(inp[0]) + ":" + str(inp[1]) + "0") 
elif inp[0] == 0 and inp[1] > 0:
    print("Horário atual: 0" + str(inp[0]) + ":" + str(inp[1]))
else:
    print("Horário atual:", str(inp[0]) + ":" + str(inp[1]))                    
#LÓGICA
min = inp[1] + inp[2]
cont = 0
#Testa minuto
if min > 60:
    minutos = min % 60
elif min < 60:
    minutos = min
else:
    inp[0] += 1
    minutos = 0
    cont = 1
#Define horas
horas = (min // 60) + inp[0]  
#testa horas
if horas > 23 and inp[0] > 22:
    horas = 0
    horas +=  (min // 60) - 1
elif horas == 24:
    horas = 0
elif horas > 23 and inp[0] < 23: 
    horas -= 24
cont = cont
#OUTPUT Final
if min > 60 and minutos > 0:
    if horas > 10:
        print("Novo horário:", str(horas) + ":" + str(minutos))
    elif minutos < 10:
        print("Novo horário:", "0" + str(horas) + ":0" + str(minutos))
    else:
        print("Novo horário:", "0" + str(horas) + ":" + str(minutos))
elif min < 60:
    if horas > 10:
        print("Novo horário:", str(inp[0]) + ":" + str(min))
    elif horas < 10 and minutos > 0:
        print("Novo horário: 0" + str(horas) + ":" + str(minutos)) 
elif minutos == 0:
    if horas > 10 and cont != 1:
        print("Novo horário:", str(horas) + ":" + str(minutos) + "0") 
    elif horas > 10 and cont == 1:
        print("Novo horário:", str(inp[0]) + ":" + str(minutos) + "0")     
    elif inp[0] == 0 and minutos == 0:
        print("Novo horário:", "0" + str(horas) + ":" + str(minutos) + "0")           
    elif horas > 0 and horas < 10:
        print("Novo horário:", "0" + str(inp[0]) + ":" + str(minutos) + "0")                   