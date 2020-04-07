# leetcode
My leetcode solutions

# 经验教训

* 一定要吧功能尽量细化为函数，这样一者做题思路比较清晰，二者可以在某些情况下直接return值。




# 搜索

很多题目其实都是一个“搜索+剪枝”的过程，其实搜索是一个非常通用的方法。任何一个最优化类型的题目，其实都可以通过搜索来解决。只是对于简单的暴力搜索来说，搜索空间是非常巨大的甚至是一个无限的空间，所谓的“优化”其实就是对搜索空间进行归纳总结，想想从哪里开始搜，搜索方向是什么，哪些子空间是可以排除在外不需要搜索的。

其中识别不需要搜索的子空间的技术，叫做剪枝。通过跳过这些子空间，来实现提升效率的目的。其实在很多问题中，问题的解空间虽然大，但是由于各种约束，真正需要搜索的可能只是其中很小一部分。

面对这种搜索问题，我们可以首先观察系统中的变量有几个，如果是2个的话，就是在一个二维平面的矩形中进行搜索，如果是三个的话，就是在一个三维空间的长方体中进行搜索。

搜索的起点呢，很多情况都是矩形的顶点或者立方体的顶点。

例如11题，寻求最大装水量，问题的目标是寻找2个杆子，使得装水量最大。这样系统中的变量就有2个，每个变量的取值范围是n，也就是解空间是一个n*n的二维空间。我们需要在这个二维空间上面进行搜索。经过仔细观察，我们可以发现把l和r对调后其实是一个重复的问题，这样解空间就缩小为原来的一半，再经过观察，就可以找到搜索的路径可剪枝的方案。


# permutation技术

排列组合生成技术。


# 图的遍历

130. Surrounded Regions


# 字典树 Trie

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








