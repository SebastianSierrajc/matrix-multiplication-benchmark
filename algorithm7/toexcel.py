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
    algorithm = "algorithm7/"
    program = 'MM1fu'
    sizes = [ "800", "1000", "1400", "1800", "2000", "2400", "4000"] 
    threads = ['1', '2', '4', '8']
    data = np.zeros([30, 7])
    book = load_workbook(path+"outputs.xlsx")
    writer = pd.ExcelWriter(path+"outputs.xlsx", engine = 'openpyxl')
    writer.book = book

    for thread in threads:
        readData(data, path+algorithm+"outputs/", program, sizes, thread)
        data /= 1000000
        df = pd.DataFrame(data=data, columns=sizes)
        df.to_excel(writer, sheet_name=program+"-T"+thread)
    
    writer.save()
    writer.close()


if __name__ == '__main__':
    main()
