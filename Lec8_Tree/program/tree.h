        

/* START: fig4_16.txt */
        #ifndef _Tree_H
        #define _Tree_H

        struct TreeNode;
        typedef int ElementType;
        typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;
        
        struct TreeNode
        {
            ElementType Element;
            SearchTree  Left;
            SearchTree  Right;
        };
        
        void  Preorder(SearchTree node);
        void  Inorder(SearchTree node);
        int leaf ( SearchTree *t);
        SearchTree MakeEmpty( SearchTree T );
        Position Find( ElementType X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( ElementType X, SearchTree T );
        SearchTree Delete( ElementType X, SearchTree T );
        ElementType Retrieve( Position P );

        #endif  /* _Tree_H */

/* END */
