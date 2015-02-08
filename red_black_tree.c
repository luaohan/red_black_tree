#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

void rb_tree_init(rb_tree *tree, rb_tree_node *nil)
{
    (*tree)->root = nil;
    (*tree)->nil = nil;
}

static rb_tree_node *tree_minimum(rb_tree_node *node, rb_tree_node *nil)
{
    while (node->lchild != nil){
        node = node->lchild;
    }

    return node;
}

static void left_rotate(rb_tree *tree, rb_tree_node *node)
{
    rb_tree_node *temp= node->rchild;
    node->rchild = temp->lchild;
    
    if (temp->lchild != (*tree)->nil){
        temp->lchild->parent = node;
    }
    
    temp->parent = node->parent;
    
    if (node->parent == (*tree)->nil){
        (*tree)->root = temp;
    } else if (node == node->parent->lchild){
        node->parent->lchild = temp;
    } else {
        node->parent->rchild = temp;
    }

    temp->lchild = node;
    node->parent = temp;
}

static void right_rotate(rb_tree *tree, rb_tree_node *node)
{
    rb_tree_node *temp= node->lchild;
    node->lchild = temp->rchild;
    
    if (temp->rchild != (*tree)->nil){
        temp->rchild->parent = node;
    }
    
    temp->parent = node->parent;
    
    if (node->parent == (*tree)->nil){
        (*tree)->root = temp;
    } else if (node == node->parent->rchild){
        node->parent->rchild = temp;
    } else {
        node->parent->lchild = temp;
    }

    temp->rchild = node;
    node->parent = temp;
}

void rb_insert(rb_tree *tree, rb_tree_node *node)
{
    rb_tree_node *y = (*tree)->nil;
    rb_tree_node *x= (*tree)->root;

    while (x!= (*tree)->nil){
        y = x;
        if (node->data < x->data){
            x = x->lchild;
        } else {
            x = x->rchild;
        }
    }

    node->parent = y;

    if (y == (*tree)->nil){
        (*tree)->root = node;
    } else if (node->data < y->data){
        y->lchild = node;
    } else {
        y->rchild = node;
    }

    node->lchild = (*tree)->nil;
    node->rchild = (*tree)->nil;
    node->color = RED;

    rb_insert_fixup(tree, node);
}

static void rb_insert_fixup(rb_tree *tree, rb_tree_node *node)
{
    while (node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->lchild)
        {
            rb_tree_node *y = node->parent->parent->rchild;

            if (y->color == RED)
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;

            } else {

                if (node == node->parent->rchild){
                    node = node->parent;
                    left_rotate(tree, node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;

                right_rotate(tree, node->parent->parent);
            }
        } 
        else 
        {
            rb_tree_node *y = node->parent->parent->lchild;

            if (y->color == RED)
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;

            } else {

                if (node == node->parent->lchild){
                    node = node->parent;
                    right_rotate(tree, node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(tree, node->parent->parent);
            }
        }
    }

    (*tree)->root->color = BLACK;
}

static void rb_transplant(rb_tree *tree, rb_tree_node *u, rb_tree_node *v)
{
    if (u->parent == (*tree)->nil){
        (*tree)->root = v;
    } else if (u == u->parent->lchild){
        u->parent->lchild = v;
    } else {
        u->parent->rchild = v;
    }

    v->parent = u->parent;
}

#if 0
void rb_delete(rb_tree *tree, rb_tree_node *node)
{

    rb_tree_node *y = node;
    short y_original_color = y->color;
    rb_tree_node *x;

    if (node->lchild == (*tree)->nil)
    {
        x = node->rchild;
        rb_transplant(tree, node, node->rchild);

    } 
    else if (node->rchild == (*tree)->nil)
    {
        x = node->lchild;
        rb_transplant(tree, node, node->lchild);
    } 
    else 
////////////////////////////////////////////////////////////////////////
#if 0 
    {
        y = tree_minimum(node->rchild, (*tree)->nil);
        y_original_color = y->color;
        
        if (y->lchild != (*tree)->nil){                 
            x = y->lchild;   
        } else {
            x = y->rchild;
        }
    }

    if (y == (*tree)->root) {
        (*tree)->root = x;
        x->color = BLACK;

        /* DEBUG stuff */   
        node->lchild = NULL;
        node->rchild = NULL;
        node->parent = NULL;

        return;
    }   

    y_original_color = y->color;

    if (y == y->parent->lchild) {           
        y->parent->lchild = x;
    } else {
        y->parent->rchild = x;
    }
                                                      // ngnix doing
    if (y == node) {
        x->parent = y->parent;
    } else {
        if (y->parent == node) {
            x->parent = y;
        } else {
            x->parent = y->parent;
        }
        
        y->lchild = node->lchild;
        y->rchild = node->rchild;
        y->parent = node->parent;
        y->color = node->color;

        if (node == (*tree)->root) {
            (*tree)->root= y;
        } else {
            if (node == node->parent->lchild) {
                node->parent->lchild = y;
            } else {
                node->parent->rchild = y;
            }
        }

        if (y->lchild != (*tree)->nil) {
            y->lchild->parent = y;
        }

        if (y->rchild != (*tree)->nil) {
            y->rchild->parent = y;
        }

        /* DEBUG stuff */
        node->lchild = NULL;
        node->rchild = NULL;
        node->parent = NULL;
    }          
#endif
    //////////////////////////////////////////////////////////////////////////
//#if 0
    {
        y = tree_minimum(node->rchild, (*tree)->nil);
        y_original_color = y->color;

        x = y->rchild;
                                                  // <<算法导论>> 的做法
        if (y->parent == node){
            x->parent = y;
        } else {
            rb_transplant(tree, y, y->rchild);
            y->rchild = node->rchild;
            y->rchild->parent = y;
        }

        rb_transplant(tree, node, y);
        y->lchild = node->lchild;
        y->lchild->parent = y;
        y->color = node->color;
    }
//#endif
    ///////////////////////////////////////////////////////////////////////////

    if (y_original_color == BLACK){
        rb_delete_fixup(tree, x);
    }
}

static void rb_delete_fixup(rb_tree *tree, rb_tree_node *node)
{
    while ( (node != (*tree)->nil) && (node->color == BLACK) )
    {
        if (node == node->parent->lchild)
        {
            rb_tree_node *w = node->parent->rchild;

            if (w->color == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                lchild_rotate(tree, node->parent);
                w = node->parent->rchild;
            }

            if ((w->lchild->color == BLACK) && (w->rchild->color == BLACK)){
                w->color = RED;
                node = node->parent;
            } else if (w->rchild->color == BLACK){
                w->lchild->color = BLACK;
                w->color = RED;
                rchild_rotate(tree, w);
                w = w->parent->rchild;
            }

            w->color = node->parent->color;
            node->parent->color = BLACK;
            w->rchild->color = BLACK;

            lchild_rotate(tree, node->parent);
            node = (*tree)->root;
        } 
        else 
        {
            rb_tree_node *w = node->parent->lchild;

            if (w->color == RED){
                w->color = BLACK;
                node->parent->color = RED;
                rchild_rotate(tree, node->parent);
                w = node->parent->rchild;
            }

            if ((w->rchild->color == BLACK) && (w->lchild->color == BLACK)){
                w->color = RED;
                node = node->parent;
            } else if (w->lchild->color == BLACK){
                w->rchild->color = BLACK;
                w->color = RED;
                lchild_rotate(tree, w);
                w = w->parent->lchild;
            }

            w->color = node->parent->color;
            node->parent->color = BLACK;
            w->rchild->color = BLACK;

            rchild_rotate(tree, node->parent);
            node = (*tree)->root;
        }
    }

    node->color = BLACK;
}
#endif

void rb_delete(rb_tree *tree, rb_tree_node *node)
{
    //ngx_uint_t           red;
    short color_temp;
    rb_tree_node  *root, *sentinel, *subst, *temp, *w;

    /* a binary tree delete */

    //root = (rb_tree_node **) &tree->root;
    root = (*tree)->root;
    sentinel = (*tree)->nil;

    if (node->lchild == sentinel) {
        temp = node->rchild;
        subst = node;

    } else if (node->rchild == sentinel) {
        temp = node->lchild;
        subst = node;

    } else {
        
        //subst = ngx_rbtree_min(node->rchild, sentinel);
        subst = tree_minimum(node->rchild, sentinel);

        if (subst->lchild != sentinel) {
            temp = subst->lchild;
        } else {  
            temp = subst->rchild;
        }
    }

    if (subst == root) {
        root = temp;
        //ngx_rbt_black(temp);
        temp->color = BLACK;

        /* DEBUG stuff */
        node->lchild = NULL;
        node->rchild = NULL;
        node->parent = NULL;
        //node->key = 0;

        return;
    }

    //red = ngx_rbt_is_red(subst);
    color_temp = subst->color;

    if (subst == subst->parent->lchild) {
        subst->parent->lchild = temp;

    } else {
        subst->parent->rchild = temp;
    }


    if (subst == node) {

        temp->parent = subst->parent;

    } else {

        if (subst->parent == node) {
            temp->parent = subst;

        } else {
            temp->parent = subst->parent;
        }

        // rb_tran
        subst->lchild = node->lchild;
        subst->rchild = node->rchild;
        subst->parent = node->parent;
        //ngx_rbt_copy_color(subst, node);
        subst->color = node->color;

        if (node == root) {
            root = subst;

        } else {
            if (node == node->parent->lchild) { 
                node->parent->lchild = subst;
            } else {
                node->parent->rchild = subst;
            }
        }

        if (subst->lchild != sentinel) {
            subst->lchild->parent = subst;
        }

        if (subst->rchild != sentinel) {
            subst->rchild->parent = subst;
        }
    }

    /* DEBUG stuff */
    node->lchild = NULL;
    node->rchild = NULL;
    node->parent = NULL;
    //node->key = 0;

    if (color_temp == RED) {
        return;
    }

    /* a delete fixup */

    while (temp != root && temp->color == BLACK /*ngx_rbt_is_black(temp)*/) {

        if (temp == temp->parent->lchild) {
            w = temp->parent->rchild;

            if ( w->color == RED /*ngx_rbt_is_red(w)*/) {
                /*ngx_rbt_black(w);
                ngx_rbt_red(temp->parent);
                ngx_rbtree_lchild_rotate(root, sentinel, temp->parent);
                */
                w->color = BLACK;
                temp->parent->color = RED;
                left_rotate(tree, temp->parent);
                w = temp->parent->rchild;
            }

            //if (ngx_rbt_is_black(w->lchild) && ngx_rbt_is_black(w->rchild)) {
            if (w->lchild->color == BLACK && w->rchild->color == BLACK) {
                //ngx_rbt_red(w);
                w->color = RED;
                temp = temp->parent;

            } else {
                if ( w->rchild->color == BLACK /*ngx_rbt_is_black(w->rchild)*/) {
                    /*ngx_rbt_black(w->lchild);
                    ngx_rbt_red(w);
                    ngx_rbtree_rchild_rotate(root, sentinel, w);
                    */
                    w->lchild->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = temp->parent->rchild;
                }

                /*ngx_rbt_copy_color(w, temp->parent); 
                ngx_rbt_black(temp->parent);
                ngx_rbt_black(w->rchild);
                ngx_rbtree_lchild_rotate(root, sentinel, temp->parent);
                */
                w->color = temp->parent->color;
                temp->parent->color = BLACK;
                w->rchild->color = BLACK;
                left_rotate(tree, temp->parent);
                temp = root;
            }

        } else {
            w = temp->parent->lchild;

            if (w->color == RED/*ngx_rbt_is_red(w)*/) {
                /*ngx_rbt_black(w);
                ngx_rbt_red(temp->parent);
                ngx_rbtree_rchild_rotate(root, sentinel, temp->parent);
                */
                w->color = BLACK;
                temp->parent->color = RED;
                right_rotate(tree, temp->parent);

                w = temp->parent->lchild;
            }

            /*if (ngx_rbt_is_black(w->lchild) && ngx_rbt_is_black(w->rchild)) {*/
              if (w->lchild->color == BLACK && w->rchild->color == BLACK) {
                //ngx_rbt_red(w);
                w->color = RED;
                temp = temp->parent;

            } else {
                if ( w->lchild->color == BLACK /*ngx_rbt_is_black(w->lchild)*/) {
                    /*ngx_rbt_black(w->rchild);
                    ngx_rbt_red(w);
                    ngx_rbtree_lchild_rotate(root, sentinel, w);
                    */
                    w->rchild->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = temp->parent->lchild;
                }

                /*ngx_rbt_copy_color(w, temp->parent);
                ngx_rbt_black(temp->parent);
                ngx_rbt_black(w->lchild);
                ngx_rbtree_rchild_rotate(root, sentinel, temp->parent);
                */
                w->color = temp->parent->color;
                temp->parent->color = BLACK;
                w->lchild->color = BLACK;
                right_rotate(tree, temp->parent);
                temp = root;                          
            }
        }
    }

    //ngx_rbt_black(temp);
    temp->color = BLACK;
}

int GetNodeNum(rb_tree_node *tree, rb_tree_node *nil)
{
    if (tree == nil){
        return 0;
    }

    return GetNodeNum(tree->lchild, nil) + GetNodeNum(tree->rchild, nil) + 1;
} 

int Getrb_treeDepth(rb_tree_node *tree, rb_tree_node *nil)
{
    if (tree == nil){
        return 0;
    }

    int num_lchild = Getrb_treeDepth(tree->lchild, nil);
    int num_rchild = Getrb_treeDepth(tree->rchild, nil);

    return num_lchild > num_rchild ? (num_lchild + 1) : (num_rchild + 1);

}

void Visit(rb_tree_node *tree, rb_tree_node *nil)
{
    printf("%-5d: ", tree->data);

    if (tree->color == 0){
        printf("red   ,");
    } else {
        printf("black ,");
    }

    if (tree->lchild != nil){
        printf("lchild : %-5d, ", tree->lchild->data);
    } else {
        printf("lchild : null , ");
    }

    if (tree->rchild != nil){
        printf("rchild : %-5d, ", tree->rchild->data);
    } else {
        printf("rchild : null , ");
    }

    if (tree->parent != nil){
        printf("parent : %-5d, ", tree->parent->data);
        if (tree->parent->color == 0){
            printf("red   \n");
        } else {
            printf("black \n");
        }

    } else {
        printf("  < is the root > \n");
    }
}

void InVisitrb_tree(rb_tree_node *tree, rb_tree_node *nil){
    if (tree == nil){
        return ;
    }

    InVisitrb_tree(tree->lchild, nil);
    Visit(tree, nil);
    InVisitrb_tree(tree->rchild, nil);
}

int GetNodeNumKthLevel(rb_tree_node *tree, int k, rb_tree_node *nil)
{
    if( tree == nil || k < 1 ){
        return 0;
    }

    if(k == 1){                                                                
        return 1;
    }

    int numlchild = GetNodeNumKthLevel(tree->lchild, k-1, nil); // 左子树中k-1层的节点个数  
    int numrchild = GetNodeNumKthLevel(tree->rchild, k-1, nil); // 右子树中k-1层的节点个数  

    return (numlchild + numrchild);  
}  

int GetLeafNodeNum(rb_tree_node *tree, rb_tree_node *nil)  
{  
    if(tree == nil) { 
        return 0;  
    }

    if(tree->lchild == nil && tree->rchild == nil) {
        return 1;
    }

    int numlchild = GetLeafNodeNum(tree->lchild, nil); // 左子树中叶节点的个数  
    int numrchild = GetLeafNodeNum(tree->rchild, nil); // 右子树中叶节点的个数 

    return (numlchild + numrchild);
}

rb_tree_node *SearchRB(rb_tree_node *tree, ElemType e, rb_tree_node *nil)
{                                                                               
    if (tree == nil || tree->data == e){       
        return tree;                           
    } else if (e < tree->data){                
        return SearchRB(tree->lchild, e, nil); 
    } else {
        return SearchRB(tree->rchild, e, nil); 
    }                                                                           
}  

