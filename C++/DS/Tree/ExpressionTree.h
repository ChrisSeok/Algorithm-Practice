#ifndef __EXPRESSIONTREE_H_
#define __EXPRESSIONTREE_H_
#include "BinaryTree.h"

Node *MakeExpTree(char expr[]);//루트노드 반환하겠군!//postfix 형식으로 변환도.
int Evalexptree(Node *n);

void ShowPrefix(Node *n);
void ShowInfix(Node *n);
void ShowPostfix(Node *n);

#endif