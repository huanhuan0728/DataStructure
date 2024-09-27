//
//  main.cpp
//  tree
//
//  Created by xuhuan lu on 2024/9/27.
//

#include <iostream>


typedef struct TreeNode{
    int data;   //  结构中的数据元素
    bool isEmpty;   //  结点是否为空
}TreeNode;

//  初始化顺序存储的二叉树，所有结点标记为空
void InitSqBiTree (TreeNode t[], int length)
{
    for (int i = 0; i < length; i++)
    {
        t[i].isEmpty = true;
    }
}

bool isEmpty(TreeNode t[], int length, int index)
{
    if (index >= length || index < 1)
        return  true;
    return t[index].isEmpty;
}

//  找到下标为index的节点的左孩子，并返回左孩子的下标，如果没有左孩子，则返回-1
int getLchild(TreeNode t[], int length, int index)
{
    int lChild = index * 2;
    if (isEmpty(t, length, lChild)) //  如果左孩子存在，左孩子的下标一定是index * 2
    {
        return -1;
    }
    
    return lChild;
}

//  找到下标为index的节点的右孩子，并返回右孩子的下标，如果没有右孩子，则返回-1
int getRchild(TreeNode t[], int length, int index)
{
    int rChild = index * 2 + 1; //如果右孩子存在，则右孩子的下标一定是index * 2 + 1
    if (isEmpty(t, length, rChild)) {
        return  -1;
    }
    return rChild;
}

//找到下标为index的节点的父节点，并返回父节点的下标，如果没有父节点，则返回-1
int getFather(TreeNode t[], int length, int index)
{
    if (index == 1)
        return  -1;
    int father = index / 2; //如果父节点存在，父节点的下标一定是index/2，除法会自动向下取整
    if (isEmpty(t, length, father)) {
        return  -1;
    }
    return father;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
