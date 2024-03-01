// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

void insertNode_R(TreeNodePtr * t,int value){
  if((*t)==NULL){
   (*t)=(TreeNodePtr) malloc(sizeof(struct TreeNode));
	 if(*t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
		(*t)->data=value;
   }
  }
  else{
      if((*t)->data>=value) 
         insertNode_R(&(*t)->leftPtr,value);//left   
     else 
         insertNode_R(&(*t)->rightPtr,value);//right
      
   }
}

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)
         b->root=new_node;
		else 
      {
         while(!inserted)
         {
            if(t->data >=value)
            {
               if(!t->leftPtr)/* move/insert to the left*/
               {
                  t->leftPtr=new_node;
                  inserted++;
               }
               else
               {
                  t=t->leftPtr;
               }
            }
  	         else
            {
	            if(!t->rightPtr)/* move/ insert to the right*/
               {
                  t->rightPtr=new_node;
                  inserted++;
               }
               else
               {
                  t=t->rightPtr;
               }
            }    
	      }//end while		
      }//end else;
  b->size++;
  }
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) 
   {        
      inOrder( treePtr->leftPtr ); //Recursion to the left
      printf("%3d",treePtr->data) ;  //print the value 
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) 
    {        
      printf("%3d",treePtr->data) ;//print mid
      preOrder( treePtr->leftPtr ); //Recursion to the left
      preOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if     
                       
} // end 

void postOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) 
   {        
      
      postOrder( treePtr->leftPtr ); //Recursion to the left
      postOrder( treePtr->rightPtr ); //Recursion to the right
      printf("%3d",treePtr->data) ;//print mid
   } // end if                           
} // end 
void ExtraOrder( TreeNodePtr treePtr,int l)
{ 
   int i;
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) 
   {  
      ExtraOrder(treePtr->rightPtr,l+1);
      //Recursion to the left
      for(i=0;i<l*5;i++)
      printf("   ");
      printf("%3d\n",treePtr->data);
       //print the value 
      ExtraOrder(treePtr->leftPtr,l+1);
       //Recursion to the right
   } // end if                          
} // end 

