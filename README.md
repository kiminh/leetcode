# leetcode
My leetcode solutions

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





