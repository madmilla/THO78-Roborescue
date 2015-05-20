import os
import Tkinter
import tkFileDialog
import pyqrcode
import shutil

#Open a dialog and asks user for choosing a directory the QRCreation
path = tkFileDialog.askdirectory()
Tkinter.Tk().withdraw()

#checks if there is a directory called X or Y, if they do the directory(s) will be deleted
if os.path.isdir(path + "/X"):
    shutil.rmtree(path + "/X")
if os.path.isdir(path + "/Y"):
    shutil.rmtree(path + "/Y")

#makes new maps
os.mkdir(path + "/X")
os.mkdir(path + "/Y")

#asks user for input for the number of X QrCodes and Y QrCodes
x = input('Number for X:')
y = input('Number for Y:')

#runs a for loop from 0 to the given number 
for number in range(0, int(x)):
    code = '' 
	#adds zeros to fill the six numbers
    for i in range(0, 6-len(hex(number)[2:])):
        code += '0'
	#use PyQrCode for creating a QRCode with version 1 and Error High
    big_code = pyqrcode.create('X' + code + hex(number)[2:], error='H', version=1, mode='binary')
    big_code.png(path + '/X/X' + str(number) + '.png',
                 scale=10, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xff])
    print("Generated X", number)

#same as above
for number in range(0, int(y)):
    code = '' 
    for i in range(0, 6-len(hex(number)[2:])):
        code += '0'
    big_code = pyqrcode.create('Y' + code + hex(number)[2:], error='H', version=1, mode='binary')
    big_code.png(path + '/Y/Y' + str(number) + '.png',
                 scale=10, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xcc])
    print("Generated Y", number)