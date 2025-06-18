import torch as t
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt
import os
os.environ["KMP_DUPLICATE_LIB_OK"] = "TRUE"


class LogisticsRegression(nn.Module):
    def __init__(self, in_dim):
        """
        *********请在此处输入你的代码*********
        
        定义模型参数w，以及非线性sigmoid函数
        """
        super().__init__()  # 等价于nn.Module.__init__()
        self.w0 = nn.Parameter(t.randn(in_dim + 1, 1))


    def forward(self, x):
        """
        *********请在此处输入你的代码*********
        定义模型函数：f = sigmoid(<w, x>)
        输入：x矩阵，每一行对应一个数据样本
        输出（返回值）：每一个数据样本的输出（预测）
        """
        bias = t.ones(x.shape[0], 1)
        new_x = t.cat((x, bias), dim = 1)
        return t.matmul(new_x, self.w0)


class Logistics_Model():
    """
    模型训练与测试类
    """
    def __init__(self, in_dim):
        """
        *********请在此处输入你的代码*********
        输入：输入数据的维度 in_dim
        定义类的属性：包括训练步长、轮数、逻辑斯蒂回归模型、优化器、损失函数
        输出：无返回变量
        """
        self.max_iter = 100
        self.loss_fn = nn.BCEWithLogitsLoss()
        self.model = LogisticsRegression(in_dim)
        self.optimizer = t.optim.SGD(self.model.parameters(), lr=0.5)
        
    def train(self, x, y):
        """
        训练模型
        输入:
            x: 训练数据矩阵
            y: +1/-1列表，分类标签

        定义迭代优化过程：一共优化指定的轮数

        返回: 
            losses: 训练中每一轮的损失值（画图用）
        """
        new_y = (y + 1) // 2
        losses = []
        for i in range(self.max_iter):
            self.optimizer.zero_grad()
            loss = self.loss_fn(self.model.forward(x), new_y)
            loss.backward()
            self.optimizer.step()
            losses.append(loss.item())
        return losses

    def test(self, x, y):
        """
        用训练好的模型做测试
        输入:
            x: 测试数据
            y: 测试数据的真实标签
        过程：使用训练好的模型，预测x的标签，并且与y进行对比，计算预测精度
        返回:
            prediction: 每一个测试数据的预测值
            accuracy: 数值，模型的精度# P, R, F
        """
        new_y = (y + 1) // 2
        y_pred = self.model(x)            # 得到预测概率
        prediction = (t.sigmoid(y_pred) >= 0.5).float()  # 概率 >= 0.5 判为正类 1
        correct = (prediction == new_y).float().sum()
        accuracy = correct / new_y.shape[0]
        return prediction, accuracy.item()


def create_linear_data(data_size, in_dim):
    """
    为线性模型生成数据
    输入:
        data_size: 样本数量
    返回:
        x_train: 训练数据
        y_train: 训练数据回归真值
        x_test: 测试数据
        y_test: 测试数据回归真值
    """
    np.random.seed(426)
    t.manual_seed(426)
    t.cuda.manual_seed(426)
    # *********修改的代码：数据生成，跟之前的那次代码一样，复制修改来的*********
    # 正负样本个数
    m_pos = data_size // 2;
    m_neg = data_size - m_pos;
    X = np.zeros((in_dim, data_size))
    Y = np.zeros((1, data_size))

    x1 = np.random.normal(loc=-1,scale=3,size=(1,m_pos))
    X[0:1,0:m_pos] = x1;
    # 整体线性分布
    X[1:2,0:m_pos] = 2*x1+10+0.1*x1**2;
    # 加噪声
    X[1:2,0:m_pos] += np.random.normal(loc=0,scale=5,size=(1,m_pos));
    Y[0,0:m_pos] = 1;

    x1 = np.random.normal(loc=1,scale=3,size=(1,m_neg))
    X[0:1,-m_neg:] = x1;
    X[1:2,-m_neg:] = 2*x1-5-0.1*x1**2
    X[1:2,-m_neg:] += np.random.normal(loc=0,scale=5,size=(1,m_neg))


    X = t.Tensor(X.T)
    Y = t.Tensor(Y.T)
    # X = t.Tensor(data_size, in_dim).uniform_(1, 10)
    # map_true = t.Tensor(in_dim, 1).uniform_(-5, 5)
    # #map_true = t.tensor([[1.5],[-5.],[3.]], dtype=t.float32)
    # print('w真值:{}'.format(map_true))

    # Y = X.mm(map_true) + 10. + t.FloatTensor(data_size,
    #                                              1).normal_(0, 10)  # t.randn(x.size())

    shuffled_index = np.random.permutation(data_size)
    shuffled_index = t.from_numpy(shuffled_index).long()
    X = X[shuffled_index]
    Y = Y[shuffled_index]
    split_index = int(data_size * 0.7)
    x_train = X[:split_index]
    y_train = Y[:split_index]
    x_test = X[split_index:]
    y_test = Y[split_index:]

    return x_train, y_train, x_test, y_test




# 生成数据
data_size = 200
in_dim = 3
x_train, y_train, x_test, y_test = create_linear_data(data_size, in_dim)

# 线性回归模型实例化
logistics = Logistics_Model(in_dim)
# 模型训练
losses = logistics.train(x_train, y_train)
plt.figure()
plt.scatter(np.arange(len(losses)), losses, marker='o', c='green')
plt.show()
# 模型测试
prediction, accuracy = logistics.test(x_test, y_test)
print('测试集上accuracy:{}'.format(accuracy))
# 打印参数
for name, parameter in logistics.model.named_parameters():
    print(name, parameter)


