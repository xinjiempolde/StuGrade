#include "bin_sorted_tree.h"
#include <QMessageBox>
#include <QDebug>
BST::BST()
{
    ClearBST();
}

void BST::InitBST(int iData, const QString &name)
{
    BSTNode node;
    node.name = name;
    node.grade = iData;
    node.leftIndex = -1;
    node.rightIndex = -1;
    v.push_back(node);
}

void BST::SetLeftChild(int currIndex, int iData, const QString &name)
{
    v[currIndex].leftIndex = v.size();  // 它的左孩子指向最后一个元素
    BSTNode* node = new BSTNode;
    node->leftIndex = -1;   // 一定得记得初始化，要不然死循环给你看！
    node->rightIndex = -1;
    node->name = name;
    node->grade = iData;
    v.push_back(*node);
}

void BST::SetRightChild(int currIndex, int iData, const QString &name)
{
    v[currIndex].rightIndex = v.size(); // 它的右孩子指向最后一个元素
    BSTNode* node = new BSTNode;
    node->leftIndex = -1;
    node->rightIndex = -1;
    node->name = name;
    node->grade = iData;
    v.push_back(*node);
}

void BST::InsertBST(int iData, const QString &name)
{
    if (v.size() == 0)
    {
        InitBST(iData, name);
        return;
    }
    int currIndex = 0;  // 遍历vector
    while (currIndex < v.size())
    {
        if (iData <= v[currIndex].grade)
        {
            if (v[currIndex].leftIndex == -1)
            {
                SetLeftChild(currIndex, iData, name);
                break;
            }
            currIndex = v[currIndex].leftIndex;
        }
        else
        {
            if (v[currIndex].rightIndex == -1)
            {
                SetRightChild(currIndex, iData, name);
                break;
            }
            currIndex = v[currIndex].rightIndex;
        }
    }
}

void BST::PreOrderTraverse(int currIndex)
{
    int flag = static_cast<int>((v[currIndex].grade / 10));
    switch (flag) {
    case 10:
    case 9:
        record.span_bigger_90++;
        break;
    case 8:
        record.span_80_to_90++;
        break;
    case 7:
        record.span_70_to_80++;
        break;
    case 6:
        record.span_60_to_70++;
        break;
    default:
        record.span_lower_60++;
        break;
    }
    // 左子树不为空，递归遍历左子树
    if (v[currIndex].leftIndex != -1)
    {
        PreOrderTraverse(v[currIndex].leftIndex);
    }
    // 右子树不为空，递归遍历右子树
    if (v[currIndex].rightIndex != -1)
    {
        PreOrderTraverse(v[currIndex].rightIndex);
    }
}

void BST::InorderTraverse(int currIndex, QString &name, bool &flag)
{
    if (v[currIndex].leftIndex != -1)
    {
        InorderTraverse(v[currIndex].leftIndex, name, flag);
    }
    if (v[currIndex].name == name)
    {
        flag = true;
        return;
    }
    if (v[currIndex].rightIndex != -1)
    {
        InorderTraverse(currIndex, name, flag);
    }
}

void BST::ClearBST()
{
    // 清空记录结构体
    ClearRecord();

    // 清空向量v
    v.clear();
}

void BST::ClearRecord()
{
    // 初始化成绩记录结构体
    record.span_lower_60 = 0;
    record.span_60_to_70 = 0;
    record.span_70_to_80 = 0;
    record.span_80_to_90 = 0;
    record.span_bigger_90 = 0;
}

GradeRecord BST::GetRecord()
{
    return record;
}
