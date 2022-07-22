# Imports de Bibliotecas

import csv
import struct
#import pandas as pd
#import matplotlib.pyplot as plt

# Structs



# Estrutura Principal
if __name__ == '__main__':

    #separador = ','

    #    with open('Planilhas/CONFIRMADOS.csv', 'r') as txt_file:
    #        for line number

#============================================================================================
    confirmados = open('Planilhas/CONFIRMADOS.csv', 'r')
    confirmados_reader = csv.reader(confirmados, delimiter = ';')

    #print(f'{confirmados_reader}')

    for i in confirmados_reader:
        print(f'\n{i}')

        #municipio = i[0]
        #numcasos = i[1]
        #data = i[2]
        #codIBGE = i[3]
        #urs = i[4]
        #micro = i [5]
        #macro = i[6]

        #print(f'{a1}')

        #print(f'\n{municipio} {numcasos} {data} {codIBGE} {urs} {macro}')

        #stop = input('Entrada: ')

    #nome = 'Guilherme'
    #idade = 20
    #altura = 1.75

    #cod = struct.pack('s I f', nome.encode(), idade, altura)

    #print(f'{cod}')
    #print('Sucesso')


