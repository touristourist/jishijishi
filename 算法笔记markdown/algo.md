排序（找出第k大的数    ：使用类似快排的思想，由于只用找一边，复杂度O（n）



找规律(对于极大的数据，找周期)：[1021 (Fibonacci Again)](https://blog.csdn.net/bcj296050240/article/details/45746467) 



**求最大公因数**：欧几里得算法（[辗转相除法](https://baike.baidu.com/item/辗转相除法/4625352)）

**求最小公倍数**：两数的乘积/最大公因数（因为两数除最大公因数外的部分互质

- [**快速幂取模**](https://blog.csdn.net/dbc_121/article/details/77646508)（积的模等于模的积（或者模的积再取模-------可使用二分加速
- 再fibonacci



桶排序：HDOJ_1425  sort 







# hdoj 1021 Fibonacci Again 

注意数据极大（达到1e6）若递归计算会造成栈溢出，所以就只能找规律，发现f（n）模3的余数每8次一循环，所以

```c++
 int main() 
 {     
     long n;    
  	 while(scanf("%ld",&n) != EOF){   
      if (n%8==2 || n%8==6) 
          printf("yes\n");   
  	  else    
     	  printf("no\n");
      }
  return 0; }
```





1h nlp

文本的情感分析，快速了解情感偏向，了解作者的主观情绪

语料库。

正面评价，负面评价。

找一种模型或者算法，分析出一条语句是正面还是负面。



特征值：抽象出一个值代表原来的物

规范化：提取出特征值，如何用同一种标准衡量

词与词之间有联系

不带情感色彩的词也会加深情感打分

不同语境会表达不同的含义

不同语意差别巨大





情感词典模型

高维向量模型模型：解决多维语义问题，上下文语义之间的关联



分词：

- 文本清洗完成后的第一步处理
- 将语句分割成合理的词语
- jieba中文分词
- ![1551057256767](C:\Users\Tourist\AppData\Roaming\Typora\typora-user-images\1551057256767.png)



Word2Vec：将分词的结果输入，输出向量空间。



情感分析模型：

输出词向量后就能进行相关模型的情感分析

![1551057637919](C:\Users\Tourist\AppData\Roaming\Typora\typora-user-images\1551057637919.png)