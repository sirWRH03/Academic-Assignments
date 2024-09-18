#include <iostream>
#include <new>
#include "bstree.h"

using namespace std;

template <typename ItemType>
void BSTree<ItemType>::Delete(BSTreeNode<ItemType>*& treePtr, ItemType& item)
{
    if (item < treePtr->data)
    {
        BSTree<ItemType>::DeleteNode(treePtr->leftPtr);
    }
    else if (item > treePtr->data)
    {
        BSTree<ItemType>::DeleteNode(treePtr->rightPtr);
    }
    else
    {
        BSTree<ItemType>::DeleteNode(treePtr);
    }
}

template <typename ItemType>
void BSTree<ItemType>::DeleteNode(BSTreeNode<ItemType>*& treePtr)
{
    BSTreeNode<ItemType>* tempPtr;
    tempPtr = treePtr;
    
    if (treePtr->leftPtr == NULL)
    {
        treePtr = treePtr->rightPtr;
        delete tempPtr;
    }
    else if (treePtr->rightPtr == NULL)
    {
        treePtr = treePtr->leftPtr;
        delete tempPtr;
    }
    else
    {
        ItemType info = GetPredecessor(treePtr->leftPtr);
        treePtr->data = info;
        Delete(treePtr->leftPtr, info);
    }
}

template <typename ItemType>
void BSTree<ItemType>::Insert(BSTreeNode<ItemType>*& ptr, ItemType item)
{
    if (ptr == NULL)
    {
        ptr = new BSTreeNode<ItemType>;
        ptr->rightPtr = NULL;
        ptr->leftPtr = NULL;
        ptr->data = item;
    }
    else if (item < ptr->data)
    {
        BSTree<ItemType>::Insert(ptr->leftPtr, item);
    }
    else
    {
        BSTree<ItemType>::Insert(ptr->rightPtr, item);
    }
}

template <typename ItemType>
void BSTree<ItemType>::Destroy(BSTreeNode<ItemType>*& ptr)
{
    if (ptr != NULL)
    {
        BSTree<ItemType>::Destroy(ptr->leftPtr);
        BSTree<ItemType>::Destroy(ptr->rightPtr);
        delete ptr;
    }
}

template <typename ItemType>
void BSTree<ItemType>::CopyTree(BSTreeNode<ItemType>*& copy, const BSTreeNode<ItemType>* originalTree)
{
    if (originalTree == NULL)
    {
        copy = NULL;
    }
    else
    {
        copy = new BSTreeNode<ItemType>;
        copy->data = originalTree->data;

        BSTree<ItemType>::CopyTree(copy->leftPtr, originalTree->leftPtr);
        BSTree<ItemType>::CopyTree(copy->rightPtr, originalTree->rightPtr);
    }
}

template <typename ItemType>
ItemType BSTree<ItemType>::GetPredecessor(BSTreeNode<ItemType>* treePtr) const
{
    BSTreeNode<ItemType>* rPtr = treePtr->rightPtr;
    
    if (rPtr == NULL)
    {
        return treePtr->data;
    }
    else if (rPtr->data > treePtr->data)
    {
        BSTree<ItemType>::GetPredecessor(rPtr);
    }
}

template <typename ItemType>
int BSTree<ItemType>::CountNodes(BSTreeNode<ItemType>* treePtr) const
{
    if (treePtr == NULL)
    {
        return 0;
    }
    else
    {
        return (BSTree<ItemType>::CountNodes(treePtr->leftPtr) +
    
        BSTree<ItemType>::CountNodes(treePtr->rightPtr) + 1);
    }
}

template <typename ItemType>
int BSTree<ItemType>::LevelCount(BSTreeNode<ItemType>* treePtr) const
{
int level = 0;
if (treePtr == NULL)
{
return -1;
}
else if (rootPtr->leftPtr==NULL && rootPtr->rightPtr==NULL)
{
return -1;
}
else if (treePtr == rootPtr)
{
return level;
}
int LevelLeft, LevelRight;
LevelLeft += BSTree<ItemType>::LevelCount(treePtr->leftPtr);
LevelRight += BSTree<ItemType>::LevelCount(treePtr->rightPtr);
if(LevelLeft == -1)
{
return LevelRight;
}
else
{
return LevelLeft;
}
}

template <typename ItemType>
int BSTree<ItemType>::FindLevel(BSTreeNode<ItemType>* treePtr, ItemType item) const
{
    int level = 0;
    
    if (treePtr == NULL)
    {
        return -1;
    }

    if (item < treePtr->data)
    {
        level += FindLevel(treePtr->leftPtr, item);
    }
    else if (item > treePtr->data)
    {
        level += FindLevel(treePtr->rightPtr, item);
    }
    
    return level;
}

template <typename ItemType>
BSTree<ItemType>::BSTree()
{
    rootPtr = NULL;
}

template <typename ItemType>
BSTree<ItemType>::BSTree(const BSTree<ItemType>& someTree)
{
    BSTree<ItemType>::CopyTree(rootPtr, someTree.rootPtr);
}

template <typename ItemType>
void BSTree<ItemType>::operator=(const BSTree<ItemType>& originalTree)
{
    if (&originalTree == this)
    {
        return;
    }

    BSTree<ItemType>::CopyTree(rootPtr, originalTree.rootPtr);
}

template <typename ItemType>
BSTree<ItemType>::~BSTree()
{
    Destroy(rootPtr);
}

template <typename ItemType>
void BSTree<ItemType>::InsertItem(ItemType item)
{
    if (BSTree<ItemType>::IsFull())
    {
        throw FullBSTree();
    }
    else if (FindLevel(rootPtr, item) >= 0)
    {
        throw FoundInBSTree();
    }
    else
    {
        BSTree<ItemType>::Insert(rootPtr, item);
    }
}

template <typename ItemType>
ItemType BSTree<ItemType>::DeleteItem(ItemType item)
{
    BSTree<ItemType>::Delete(rootPtr, item);
}

template <typename ItemType>
void BSTree<ItemType>::MakeEmpty()
{
    BSTree<ItemType>::Destroy(rootPtr);
}

template <typename ItemType>
int BSTree<ItemType>::Size() const
{
    return BSTree<ItemType>::CountNodes(rootPtr);
}

template <typename ItemType>
bool BSTree<ItemType>::IsFull() const
{
    BSTreeNode<ItemType>* location;
    
    try
    {
        location = new BSTreeNode<ItemType>;
        delete location;
        return false;
    }
    catch ( std::bad_alloc )
    {
        return true;
    }
}

template <typename ItemType>
bool BSTree<ItemType>::IsEmpty() const
{
    return (rootPtr == NULL);
}

template <typename ItemType>
ItemType BSTree<ItemType>::Min() const
{
    if (BSTree<ItemType>::IsEmpty())
    {
        throw EmptyBSTree();
    }
    else
    {
        BSTreeNode<ItemType>* tempPtr;
        BSTreeNode<ItemType>* tempPtr2;

        tempPtr = rootPtr;
        tempPtr2 = rootPtr->leftPtr;

        if (tempPtr2 == NULL)
        {
            return tempPtr->data;
        }

        while (tempPtr2->data < tempPtr->data)
        {
            tempPtr = tempPtr2;
            tempPtr2 = tempPtr2->leftPtr;
            
            if (tempPtr2 == NULL)
            {
                return tempPtr->data;
            }
        }
    }
}

template <typename ItemType>
ItemType BSTree<ItemType>::Max() const
{
    if (BSTree<ItemType>::IsEmpty())
    {
        throw EmptyBSTree();
    }
    else
    {
        BSTreeNode<ItemType>* tempPtr;
        BSTreeNode<ItemType>* tempPtr2;
        
        tempPtr = rootPtr;
        tempPtr2 = rootPtr->rightPtr;
        
        if (tempPtr2 == NULL)
        {
            return tempPtr->data;
        }
        
        while (tempPtr2->data > tempPtr->data)
        {
            tempPtr = tempPtr2;
            tempPtr2 = tempPtr2->rightPtr;
            
            if (tempPtr2 == NULL)
            {
                return tempPtr->data;
            }
        }
    }
}

template <typename ItemType>
int BSTree<ItemType>::TotalLevels() const
{
    if (rootPtr == NULL)
    {
        throw EmptyBSTree();
    }
    else
    {
        return BSTree<ItemType>::LevelCount(rootPtr);
    }
}

template <typename ItemType>
int BSTree<ItemType>::Level(ItemType item) const
{
    if (BSTree<ItemType>::IsEmpty())
    {
        throw EmptyBSTree();
    }
    else if (BSTree<ItemType>::FindLevel(rootPtr, item) == -1)
    {
        throw NotFoundBSTree();
    }
    else
    {
        return BSTree<ItemType>::FindLevel(rootPtr, item);
    }
}