#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"

int main()
{
    
    rb_tree tree = (rb_tree)malloc(sizeof(struct rb_tree));

    rb_tree_node nil;
    nil.color = BLACK;

    rb_tree_init(&tree, &nil);
    printf("rb_tree_init success \n");

    rb_tree_node a43, a2, a65, a24, a56, a23, a7, a60, a9;

    printf("insert : 43, 2, 65, 24, 56, 23, 7, 60, 9 \n");

    a43.data = 43;
    a2.data = 2;
    a65.data = 65;
    a24.data = 24;
    a56.data = 56;
    a23.data = 23;
    a7.data = 7;
    a60.data = 60;
    a9.data = 9;

    rb_insert(&tree, &a43);
    rb_insert(&tree, &a2);
    rb_insert(&tree, &a65);
    rb_insert(&tree, &a24);
    rb_insert(&tree, &a56);
    rb_insert(&tree, &a23);
    rb_insert(&tree, &a7);
    rb_insert(&tree, &a60);
    rb_insert(&tree, &a9);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));

    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);

    printf ("---------------delete 23 : \n");
    rb_delete(&tree, &a23);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));

    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);

#if 0 
    printf ("---------------delete 43 : \n");
    rb_delete(&tree, &a43);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));

    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);

    printf ("--------------------delete 7 : \n");
    rb_delete(&tree, &a7);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));

    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);
#endif

#if 0
    rb_tree_node a15, a1, a9, a2, a0, a12, a16, a7, a11, a13, a17, a14;

    printf("insert : 15, 1, 9, 2, 0, 12, 16, 7, 11, 13, 17, 14 \n");

    a15.data = 15;
    a1.data = 1;
    a9.data = 9;
    a2.data = 2;
    a0.data = 0;
    a12.data = 12;
    a16.data = 16;
    a7.data = 7;
    a11.data = 11;
    a13.data = 13;
    a17.data = 17;
    a14.data = 14;

    rb_insert(&tree, &a15);
    rb_insert(&tree, &a1);
    rb_insert(&tree, &a9);
    rb_insert(&tree, &a2);
    rb_insert(&tree, &a0);
    rb_insert(&tree, &a12);
    rb_insert(&tree, &a16);
    rb_insert(&tree, &a7);
    rb_insert(&tree, &a11);
    rb_insert(&tree, &a13);
    rb_insert(&tree, &a17);
    rb_insert(&tree, &a14);

    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));

    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);

    printf("------------------ delete 7 : \n");
    rb_delete(&tree, &a7);

    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));
    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);

    printf("------------------ delete 12 : \n");
    rb_delete(&tree, &a12);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));
    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);
    
    printf("------------------ delete 15 : \n");
    rb_delete(&tree, &a15);
    printf("GetNodeNumKthLevel 1 : %d \n", GetNodeNumKthLevel(tree->root, 1, tree->nil));
    printf("GetNodeNumKthLevel 2 : %d \n", GetNodeNumKthLevel(tree->root, 2, tree->nil));
    printf("GetNodeNumKthLevel 3 : %d \n", GetNodeNumKthLevel(tree->root, 3, tree->nil));
    printf("GetNodeNumKthLevel 4 : %d \n", GetNodeNumKthLevel(tree->root, 4, tree->nil));
    printf("GetNodeNumKthLevel 5 : %d \n", GetNodeNumKthLevel(tree->root, 5, tree->nil));

    printf("GetLeafNodeNum : %d \n", GetLeafNodeNum(tree->root, tree->nil));
    printf("GetNodeNum : %d \n", GetNodeNum(tree->root, tree->nil));
    printf("GetBSTreeDepth : %d \n", Getrb_treeDepth(tree->root, tree->nil));
    printf("InVisitrb_tree : \n");
    InVisitrb_tree(tree->root, tree->nil);
#endif
    
    free(tree);
    printf("destroy rb_tree success \n");

    return 0;
}
