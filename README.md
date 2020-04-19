# leetcode
My leetcode solutions

# 经验教训

* 一定要吧功能尽量细化为函数，这样一者做题思路比较清晰，二者可以在某些情况下直接return值。
* 如果输入的形式是一个序列，则可以想想：分治、动规、贪婪，一般不建议搜索，因为很费时间，栈还有可能溢出。


# 搜索

很多题目其实都是一个“搜索+剪枝”的过程，其实搜索是一个非常通用的方法。任何一个最优化类型的题目，其实都可以通过搜索来解决。只是对于简单的暴力搜索来说，搜索空间是非常巨大的甚至是一个无限的空间，所谓的“优化”其实就是对搜索空间进行归纳总结，想想从哪里开始搜，搜索方向是什么，哪些子空间是可以排除在外不需要搜索的。

其中识别不需要搜索的子空间的技术，叫做剪枝。通过跳过这些子空间，来实现提升效率的目的。其实在很多问题中，问题的解空间虽然大，但是由于各种约束，真正需要搜索的可能只是其中很小一部分。

面对这种搜索问题，我们可以首先观察系统中的变量有几个，如果是2个的话，就是在一个二维平面的矩形中进行搜索，如果是三个的话，就是在一个三维空间的长方体中进行搜索。

搜索的起点呢，很多情况都是矩形的顶点或者立方体的顶点。

例如11题，寻求最大装水量，问题的目标是寻找2个杆子，使得装水量最大。这样系统中的变量就有2个，每个变量的取值范围是n，也就是解空间是一个n*n的二维空间。我们需要在这个二维空间上面进行搜索。经过仔细观察，我们可以发现把l和r对调后其实是一个重复的问题，这样解空间就缩小为原来的一半，再经过观察，就可以找到搜索的路径可剪枝的方案。


# 动态规划

动态规划一般是一维动规划，和二维动规划。

## 一维动规
其中一维动规主要特点是在一个数组上进行迭代，第i个item的状态，于前1个或者前n个元素的状态相关，通过取min、max或者bool来得出。

两大思路：
* 背包思路-后缀遍历大法
* 我结尾思路-以我结尾或者另起炉灶，最后求最优

### 记忆化搜索，缓存

* [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
频繁获取区间和，不如存一个累加和序列，到时候减法一下就可以了。

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

bit计算，如果当前是奇数，那一定是把前一个数字的最后一个bit换成了1，所以就是res[i-1]+1
如果当前是偶数，那自己的bit1的个数，肯定和自己右移一位形成的数字的bit1数是一样的。

### [357. Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)
对于n来说，10^n最多有n位，其中n-1位的情况已经算出来了，那就只剩下计算n位的情况了
也就是9 * 9 * 8 * 7....这么多情况

### 子序列最值( 我结尾，延续？或者另起炉灶)
给定一个序列，求这个序列里面的一个子序列，使得这个子序列在给定条件上是最优的

 * [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
 * [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) 注意负负得正，所以需要一个min_res和一个max_res，最终的结果，可能是下面情况中的一种。
    - nums[ k ]，重新开始另起炉灶
    - nums[ k ] * max_res[ k - 1 ]
    - nums[ k ] * min_res[ k - 1 ]

* [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
依然是如果以i结尾的话，需要遍历之前所有比i小的（可以构成递增序列），看看他们最长能构成多长的序列n，加上第i个，就是n+1，选出一个最大的，就是res[i]的结果。

* [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
先排序，然后对于每个i，编译[ i-1, 0 ]的所有元素，如果能整除，那就计算如果纳入这个集合，会获取多大的收益，最后res[i]的值是收益最大的那个。

这类型问题需要通过2步来求解:

* 第一步：序列中以s[ k ]结尾的子序列的最优解，注意：意思是这个子序列的最后一个元素一定要是s[ k ]
* 第二部：在所有以0、1、2、3、...n结尾的解中，求max或者min，从而得到原始问题的最终解。

### [55. Jump Game](https://leetcode.com/problems/jump-game/)

### [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
121.首先对数组进行差分，本质上是求差分数组sum最大的子串。经典动态规划，思想是先求出以每一个元素为结尾的串能做到的最大sum(一定要包含这个元素)。最后计算一下整体最大的元素。

### [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
简单题目

### [91. Decode Ways](https://leetcode.com/problems/decode-ways/)
这个题目比比较有意思，但是需要注意100、0这些情况

### [343. Integer Break](https://leetcode.com/problems/integer-break/)
数字拆分，使得乘积最大。解法是：每个数字都能拆分为(1,n-1)(2,n-2)(3,n-3)...(L,R)
其中最大值可能是四种情况中的一种： 
- L * R    
- L拆 * R
- L * R拆
- L拆 * R拆 

### [198. House Robber](https://leetcode.com/problems/house-robber/)
考虑当前这家，max(抢，不抢)

### [337. House Robber III](https://leetcode.com/problems/house-robber-iii/)
原理差不多，只不过第i层要访问到i+1层和i+2层的信息，所以每次递归返回时也同时携带自己下一层的信息。

### [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
这个题的划分比较复杂。考虑到计算{1 ~ n}构成的BST的个数，对于动态规划的，我们必须通过{1 ~ n-1}、{1 ~ n-2}、{1 ~ n-3}来表达{1 ~ n}？

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

就拿n=3来说，可以用仔细看可以发现从1-3，每一个节点都可以作为root节点。
当确定root节点以后，左边有L个节点，右边有R个节点，其中L和R的关系是`L + R = n-1`。
其中左边的所有节点是连续的，所以有res[ L ]种情况，同理右边也是连续的R个数，所以有res[ R ]种情况。
那么以这个数字为root时候，就有res[ L ] * res[ R ]种情况。

* 当root = 1时，左边有root - 1 = 0个节点，右边有n - root = 2个节点，所以有res[ 0 ] * res[ 2 ] = 2种情况。
* 当root = 2时，左边有root - 1 = 1个节点，右边有n - root = 1个节点，所以有res[ 1 ] * res[ 1 ] = 1种情况。
* 当root = 3时，左边有root - 1 = 2个节点，右边有n - root = 0个节点，所以有res[ 2 ] * res[ 0 ] = 2种情况。

所以一共有 2 + 1 + 2 = 5种情况。

### 背包思路（后缀遍历大法）

* [139. Word Break](https://leetcode.com/problems/word-break/)
依然是使用n-1、n-2、n-3、n-4...等来表示n。
res[ n ]表示目标字符串s[ 0 : n ]是不是yes。举个例子，如果我们知道s[ 0 : n-k]是yes的，恰好s[n-k+1 : n]刚好是字典里面一个单词，那么s[ 0 : n ]就是yes的。所以我们在求res[ n ]的时候，遍历字典里面所有的word，如果s[ 0 : n]刚好以word为后缀，且恰好再往前的s[0 : n - len(word) - 1]是yes的，那么res[ n ]就是yes的，否则默认是no。

* [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)
 依然使用“后缀遍历法”，通过遍历1、4、9、16等平方数字，算法至少需要几个。

* [322. Coin Change](https://leetcode.com/problems/coin-change/)
主要考虑一下amount里面最后要放硬币i的的i种情况，因为最后一定更要放，所以不考虑不放的情况。
amount就是背包的容量。


## 二维动规


# permutation技术

排列组合生成技术。


# 图的遍历

130. Surrounded Regions


# 字典树 Trie

字典树最大的优势是可以快速的插入和查找字符串，而且可以按照字典顺序输出字符串，缺点是占用的空间比较大。

211是一个字典树搜索的变形，即支持模糊搜索，实现方法是把所有的可能都搜索一下。

* [211.Add and Search Word - Data structure design](https://leetcode.com/problems/add-and-search-word-data-structure-design/)

# 优势

insert and find strings in O(L) 要明显优于BST和Hash
可以直接以字典顺来输出所有词
可以很快的做前缀搜索：输入法自动完成功能

# 劣势

比较费内存，因为每个node都有一个长度为26的数组。

# 二叉树

二叉树的考点比较固定，主要有下面一些：
* 创建树
* 深度优先遍历
* 广度优先遍历 && 按层遍历
* 双树同时处理
* 二叉搜索树BST

在解决问题时，尽量寻找一下问题的答案是否有递归的性质，例如[101.Symmetric Tree](https://leetcode.com/problems/symmetric-tree)

## 深度优先遍历

这个经常用到，其中包括preorder、inorder和postorder三种遍历方法，每种遍历方法又分为递归遍历、循环遍历、和迭代器模式的遍历。
最典型的有下面这些题目，都是直接考察这方面内容。

* [94.Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal)
* [144.Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal)
* [145.Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal)
* [173.Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator)

## 广度优先遍历

广度优先遍历也叫按层遍历,[102.Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal)这个题目是直接对按层遍历的考察。
按层遍历，的很多题目，一般需要能够识别到每一层的第一个节点和最后一个节点，需要在这些时候做一些特别的记录或者操作才能解决问题。
典型的问题有：

[222.Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes)
[116.Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node)
[117.Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii)
[199.Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
其中222比较直接一些，二另外三道题则比较间接，但是依然是用了层序遍历的思想。

## 双树同时处理



# 哈希

哈希思想也是算法中的一个重要思想。哈希的主要应用有2方面：提高性能和归类。

通过构造特殊的哈希，可以快速收集相同类型的数据。典型的题目例如：

* [49.Group Anagrams](https://leetcode.com/problems/group-anagrams/)


# 列表

# 队列

# 栈

经典题目：可以求最小值的栈的实现[155.Min Stack](https://leetcode.com/problems/min-stack/)

两个栈实现一个队列[232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)，需要用到两个栈，一个负责push，另外一个负责pop。执行push操作的时候，首先检测目前是否出于push状态，如果不是的话，就调整为push状态，然后在push。在pop的时候也是同理。

两个队列实现一个栈[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)，需要用到两个队列，者两个队列无轮流做主队列，切换队列时候，需要current = (current + 1) % 2



# 位图

如果数据的范围是有限的，则可以使用位图。

* [187.Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences)
* [78. Subsets](https://leetcode.com/problems/subsets/)
使用位图来表示子集是一个极好的方法，连去重功能都有了。

# 生成排列、组合

这个比较麻烦

* [46.Permutations](https://leetcode.com/problems/permutations/)
* [78.Subsets](https://leetcode.com/problems/subsets/)


# 排序

很多最优化问题，其实只要把目标集合进行排序，就会有迹可循。

一种特殊的字符串排序方法模式 [179. Largest Number](https://leetcode.com/problems/largest-number/)

[524. Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

# 贪心

贪心算法的常用工具是优先队列priority_queue：因为时刻都要取当前的最优解

unsolved[1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

经典的开会问题








