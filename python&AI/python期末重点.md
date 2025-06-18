## 组合数据类型
 ```
 type(item) 返回数据类型
 变量名是一个名字，指向值（类型推导）
 不可变对象（1, 2, []）, 虽然[]可变， 但（）仍不变，即为顶层对象不可变
函数传参：
		 def func(**args)
		 **args为可传入的字典
		 def func(*args):
		 *args为元组
		 实现可变参数
		 默认参数：
			 def f(x, y = 2) y为默认参数，必须放在普               通参数后面
		
		输入函数值时，可以根据形参名称指定输入；
		考试时最好写

 字符串、元组、列表
	 元组生成后固定，不可变数据类型；
	 
	 args为元组， *args为解压元组操作
	 列表操作：
		 x in list
		 len(s)
		 s.count(ele) 计算元素个数
		 list[i:j] 右开，从0开始
	 
 集合
	 集合无序
	 集合生成时可自动去重
	 集合中不能有可变数据类型
	 集合可变
	 set.remove(x)
	 set.add(x)
 字典
	 可变数据类型
	 key ：value
	 key不能是可变数据类型
	 大可能考可变与不可变
	 
	字典对键的遍历，对值的遍历，get()方法:
	dict.keys()
	dict.values() 返回相应的序列
	dict.items()
	dict[key] = value
高级操作
	filter(function, iterable)
	过滤掉输入function输出为false值的值，并返回iterator
	可用list(iter)或tuple(iter)转换

	map(func, iterable)
	将func用于iterable中数据，返回迭代器

	reduce(func, iterable):
	from functools import reduce

	nums = [1, 2, 3, 4, 5]
	result = reduce(lambda x, y: x + y, nums)
	print(result)  # 输出: 15

	列表推导式，字典推导式，集合推导式
	sort排序改变原数据，只能用于列表
	sorted返回新对象
	sorted(DS, key, reverse):
	key为自定义排序函数，实际上是一个映射函数
	items = [('a', 3), ('b', 1), ('c', 2)]
	items.sort(key=lambda x: x[1])
			print(items)  # 输出: [('b', 1), ('c', 2), ('a', 3)]
	f = lambda x: x * x



 ```
## I/O
``` 
with expression，目录操作（查看绝对路径）
文件读写函数
```
## 类
```
类的继承和多态
类方法；对象方法定义时的不同；
多态：override和overload
不要用可变变量作为默认值

```
## numpy数组
## Tensor
```
tensor.view
```

## 人工智能模型
```

```