from random import random, randrange, randint
import sys
from time import sleep
array2 = sys.stdin.read()
array3 = array2.replace("0.", "")
array = array3.split(",")
array = list(map(int, array))
elementsQuantity = len(array)//2
for i in range(elementsQuantity):
    array[i*2+1] = array[i*2+1]/10
print(array)
expectedValue = 0
forDispersion = 0
dispersion = 0
sleep(5)
for i in range(elementsQuantity):
    expectedValue += array[i*2] * array[i*2+1]
for i in range(elementsQuantity):
    forDispersion += array[i*2] ** 2 * array[i*2+1]
dispersion = forDispersion - expectedValue ** 2
print('Expected value: {}'.format(round(expectedValue, 2)))
print('Dispersion: {}'.format(round(dispersion,2)))
#tostring = str(expectedValue).strip('[]')
#byt = tostring.encode('utf-8')

