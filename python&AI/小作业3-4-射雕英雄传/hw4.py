import jieba
import os
import csv
def read_new_word_dic(path): #读取新词典
    with open(path, 'rt') as file:
        fliterlist = []
        while True:
            text = file.readline()
            text = text.strip()
            fliterlist.append(text)
            if text == '':
                break
            jieba.add_word(text)
        return fliterlist
fliter_list = read_new_word_dic('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/射雕英雄传人物.txt')
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
with open('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/word_data.csv', 'w') as stata_table:
    headers = [word[0] for word in listdic if word[0] in fliter_list]
    stata_table_csv = csv.DictWriter(stata_table, headers)
    stata_table_csv.writeheader()
    for txt in txts:
        counts = {}
        with open('/home/mort/Desktop/code/AI-python/小作业3-4-射雕英雄传/book/' + txt, 'rt') as text:
            all_text = text.read()
            words = jieba.lcut(all_text)
            for word in words:
                if len(word) > 1 and word in fliter_list:
                    if word not in counts:
                        counts[word] = 1
                    else:
                        counts[word] += 1
            for key in headers:
                if key not in counts:
                    counts[key] = 0    
            stata_table_csv.writerow(counts)