import time
import pyperclip
from PIL import ImageGrab
from pix2tex.cli import LatexOCR

model = LatexOCR()
while True :
    img = ImageGrab.grabclipboard()
    if img != None :
        pyperclip.copy('\\begin{align}'+str(model(img))+'\end{align}')
    time.sleep(0.5)