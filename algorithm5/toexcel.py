import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from openpyxl import load_workbook

def readData(data, path, program, sizes, thread):
    for i, size in enumerate(sizes):
        f = open(f"{path}{program}-size{size}-T{thread}.txt")
        for j, l in enumerate(f):
            data[j][i] = float(l)

def main():
    path = '/home/sebastian/workspace-cs/matrix-multiplication-benchmark/'
    algorithm = "algorithm5/"
    program = 'MM1f'
    # sizes = [ "800", "1000", "1400", "1800", "2000", "2400", "4000"] 
    sizes = [ "500", "1000", "1200", "2000"] 
    threads = ['1', '2', '4', '8']
    data = np.zeros([30, 4])
    book = load_workbook(path+"parcial2.xlsx")
    writer = pd.ExcelWriter(path+"parcial2.xlsx", engine = 'openpyxl')
    writer.book = book

    for thread in threads:
        readData(data, path+algorithm+"parcial2/", program, sizes, thread)
        data /= 1000000
        df = pd.DataFrame(data=data, columns=sizes)
        df.to_excel(writer, sheet_name=program+"-T"+thread)
    
    writer.save()
    writer.close()


if __name__ == '__main__':
    main()
