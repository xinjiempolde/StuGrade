/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 周新纪（插入数据，设置左孩子和右孩子） & 刘亚炯（先序遍历和中序遍历） & 王崧霖（相关结构的定义）

Date: 2019-12-20

Description: 二叉排序树定义及其操作

**************************************************************************/
#ifndef BST_H
#define BST_H
#include <QString>
#include <QVector>
/* 二叉排序树节点 */
typedef struct {
    float grade;
    QString name;
    int leftIndex;
    int rightIndex;
}BSTNode;

/* 成绩记录结构体 */
typedef struct {
    int span_lower_60;  // 不及格
    int span_60_to_70;  // 及格
    int span_70_to_80;  // 中
    int span_80_to_90;  // 良
    int span_bigger_90; // 优
}GradeRecord;

class BST
{
public:
    BST();

    /*
     * 函数名:InitBST
     * 功  能:初始化二叉排序树
     * 输  入:学生成绩idata， 学生名字name
     * 输  出:无
     * 返回值:无
     */
    void InitBST(int iData, const QString& name);

    /*
     * 函数名:SetLeftChild
     * 功  能:构造当前节点的左孩子
     * 输  入:当前节点currIndex, 学生成绩idata， 学生名字name
     * 输  出:无
     * 返回值:无
     */
    void SetLeftChild(int currIndex, int iData, const QString &name);

    /*
     * 函数名:SetRightChild
     * 功  能:构造当前节点的右孩子
     * 输  入当前节点currIndex, 学生成绩idata， 学生名字name
     * 输  出:无
     * 返回值:无
     */
    void SetRightChild(int currIndex, int iData, const QString &name);

    /*
     * 函数名:InsertBST
     * 功  能:向二叉排序树中插入节点
     * 输  入:学生成绩idata， 学生名字name
     * 输  出:无
     * 返回值:无
     */
    void InsertBST(int iData, const QString &name);

    /*
     * 函数名:PreOrderTraverse
     * 功  能:先序遍历二叉排序树，并统计成绩分布
     * 输  入:当前节点
     * 输  出:无
     * 返回值:无
     */
    void PreOrderTraverse(int currIndex);

    /*
     * 函数名:InorderTraverse
     * 功  能:先序遍历二叉排序树，查找是否重名
     * 输  入:当前节点
     * 输  出:无
     * 返回值:无
     */
    void InorderTraverse(int currIndex, QString& name, bool &flag);

    /*
     * 函数名:ClearBST
     * 功  能:重置二叉排序树
     * 输  入:无
     * 输  出:无
     * 返回值:无
     */
    void ClearBST();

    /*
     * 函数名:ClearRecord
     * 功  能:清空二叉排序树的记录
     * 输  入:无
     * 输  出:无
     * 返回值:无
     */
    void ClearRecord();

    /*
     * 函数名:GetRecord
     * 功  能:获得二叉排序树的记录结构体
     * 输  入:无
     * 输  出:无
     * 返回值:记录结构体
     */
    GradeRecord GetRecord();
private:
    QVector<BSTNode> v;    // 用vector来表示二叉排序树
    GradeRecord record;
};

#endif // BST_H
