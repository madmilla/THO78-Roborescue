import os
import Tkinter
import tkFileDialog
import pyqrcode
import shutil

path = tkFileDialog.askdirectory()
Tkinter.Tk().withdraw()

if os.path.isdir(path + "/X"):
    shutil.rmtree(path + "/X")
if os.path.isdir(path + "/Y"):
    shutil.rmtree(path + "/Y")

os.mkdir(path + "/X")
os.mkdir(path + "/Y")

x = input('Number for X:')
y = input('Number for Y:')
for number in range(0, int(x)):
    code = '' 
    for i in range(0, 6-len(hex(number)[2:])):
        code += '0'
    big_code = pyqrcode.create('X' + code + hex(number)[2:], error='H', version=1, mode='binary')
    big_code.png(path + '/X/X' + str(number) + '.png',
                 scale=10, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xcc])

for number in range(0, int(y)):
    code = '' 
    for i in range(0, 6-len(hex(number)[2:])):
        code += '0'
    big_code = pyqrcode.create('X' + code + hex(number)[2:], error='H', version=1, mode='binary')
    big_code.png(path + '/Y/Y' + str(number) + '.png',
                 scale=10, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xcc])