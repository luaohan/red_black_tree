// red_black_tree.h (2014-09-07)
// WangPeng (1245268612@qq.com)

#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#define TRUE 0
#define ERROR -1
#define FALSE -1

#define RED 0
#define BLACK 1

typedef int ElemType;

typedef struct rb_tree_node
{
    ElemType data;
    short color;

    struct rb_tree_node *lchild, *rchild, *parent;

}rb_tree_node;

typedef struct rb_tree {
    rb_tree_node *root;
    rb_tree_node *nil;
} * rb_tree;

void rb_tree_init(rb_tree *tree, rb_tree_node *nil);
    
static rb_tree_node *tree_minimum(rb_tree_node *node, rb_tree_node *nil);

static void 
left_rotate(rb_tree *tree, rb_tree_node *node);

static void 
right_rotate(rb_tree *root, rb_tree_node *node);

static void rb_insert_fixup(rb_tree *tree, rb_tree_node *node); 

void rb_insert(rb_tree *tree, rb_tree_node *node); 

static void rb_transplant(rb_tree *tree, rb_tree_node *u, rb_tree_node *v); 
static void rb_delete_fixup(rb_tree *tree, rb_tree_node *node); 

void rb_delete(rb_tree *tree, rb_tree_node *node); 

void Visit(rb_tree_node *node, rb_tree_node *nil); 
void InVisitrb_tree(rb_tree_node *node, rb_tree_node *nil);   

//求二叉树第K层的节点个数                                                       
int GetNodeNumKthLevel(rb_tree_node *node, int k, rb_tree_node *nil);
//求二叉树中叶子节点的个数                                                      
int GetLeafNodeNum(rb_tree_node *node, rb_tree_node *nil);          
int GetNodeNum(rb_tree_node *node, rb_tree_node *nil);              
int Getrb_treeDepth(rb_tree_node *node, rb_tree_node *nil); 

rb_tree_node *SearchRB(rb_tree_node *node, ElemType e, rb_tree_node *nil);

#endif

