from tkinter import *
import tkinter.filedialog
import tkinter.messagebox
from PPTtoPDF import *


class Gui:
    def __init__(self):
        # 初始化主窗口
        self.top = Tk()
        self.top.title("pdf转换器")
        self.top.geometry('350x120+450+300')
        # 路径
        self.fromPath = StringVar()
        self.toPath = StringVar()
        # 待转换文件路径
        self.lab1 = Label(self.top, text="文件路径：").grid(row=0, column=0, sticky=W, padx=5, pady=5)
        self.entry1 = Entry(self.top, width=25, textvariable=self.fromPath).grid(row=0, column=1, sticky=W, padx=5,
                                                                                 pady=5)
        self.btn1 = Button(self.top, text="路径选择", command=self.selectFromPath).grid(row=0, column=2, sticky=W, padx=5,
                                                                                    pady=5)
        # PDF存放的目标路径
        self.lab2 = Label(self.top, text="目标路径:").grid(row=1, column=0, sticky=W, padx=5, pady=5)
        self.entry2 = Entry(self.top, width=25, textvariable=self.toPath).grid(row=1, column=1, sticky=W, padx=5,
                                                                               pady=5)
        self.btn2 = Button(self.top, text="路径选择", command=self.selectToPath).grid(row=1, column=2, sticky=W, padx=5,
                                                                                  pady=5)

        self.btn3 = Button(self.top, text="转换", command=self.btn3_click).grid(row=2, column=2, sticky=W, padx=5, pady=5)

        self.top.mainloop()

    def selectFromPath(self):
        """
        获取文件路径
        :return:
        """
        path = tkinter.filedialog.askdirectory()
        if not path.isspace():
            self.fromPath.set(path)

    def selectToPath(self):
        """
        获取目标路径
        :return:
        """
        path = tkinter.filedialog.askdirectory()
        if not path.isspace():
            self.toPath.set(path)

    def btn3_click(self):
        """
        转换按钮点击事件
        :return:
        """
        inputfolder = self.fromPath.get().replace("/", "\\")
        outputfolder = self.toPath.get().replace("/", "\\")
        status = PPTtoPDF(inputfolder, outputfolder)
        if not status:
            tkinter.messagebox.showerror(title="错误", message="路径错误！")
        else:
            tkinter.messagebox.showinfo(title="提示", message="转换完毕")


if __name__ == '__main__':
    form = Gui()
