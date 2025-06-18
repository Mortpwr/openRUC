import jieba
import os
import csv
def read_new_word_dic(path): #读取新词典
    with open(path, 'rt') as file:
        while True:
            text = file.readline()
            if text == '':
                break
            jieba.add_word(text)
read_new_word_dic('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/射雕英雄传人物.txt')
read_new_word_dic('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/小作业3-4-射雕英雄传词典.txt')
counts = {}
count = 0
txts = [txt for txt in os.listdir('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/book') if os.path.splitext(txt)[1] == '.txt']
for txt in txts:
    with open('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/book/' + txt, 'rt') as text:
        all_text = text.read()
        words = jieba.lcut(all_text)
        for word in words:
            if len(word) > 1:
                if word not in counts:
                    counts[word] = 1
                else:
                    counts[word] += 1
listdic = list(counts.items()) #通过字典进行排序
listdic.sort(key = lambda x : x[1], reverse= True)
print(listdic[0]) #输出最高词频

