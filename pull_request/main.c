#include <stdio.h>
#include <stdlib.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
}TreeNode;


TreeNode *treeInsert(TreeNode *t, int data){

TreeNode *newNode = malloc(sizeof(TreeNode));

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

TreeNode *current = t;
TreeNode *parent = t;

    if(t == NULL){
        t = newNode;
    }else{
        while (current->key != data)
        {
            parent = current;

            if(current->key > data){
                current = current->left;

                if(current == NULL){
                    parent->left = newNode;

                    return t;
                }
            }else{
                current = current->right;

                if(current == NULL){
                    parent->right = newNode;

                    return t;
                }
            }
        }
        
    }
    return t;
}



boolean isBalanced(TreeNode *root){
	
	TreeNode *lTree = root->left;
	TreeNode *rTree = root->right;
	TreeNode *lNode = root;
	TreeNode *rNode = root;

	int lcount = 0, rcount = 0; 
	
	if(root){//посещаем корень

	while(lTree != NULL){
		
		lNode = lTree;
		
		if(lNode->left != NULL){
			
			lcount++;
		}
		else if(lNode->right != NULL){
			
			lcount++;
		}
		
	lTree = lTree->left;
	}
	
	
	while(rTree != NULL){
		
		rNode = rTree;
		
		if(rNode->right != NULL){
			
			rcount++;
		}
		else if(rNode->left != NULL){
			
			rcount++;
		}
		
	rTree = rTree->right;
	}

	if((lcount - rcount) > 1 || (lcount - rcount) < -1) return false;
	else return true;

	}else{
		
		return false;
	}
	
}

void printTree(TreeNode *root){
    if(root){
        printf("%d", root->key);
    if(root->left || root->right){
        printf("(");
        if(root->left){
            printTree(root->left);
        }else{ 
            printf("NULL");
         }
        printf(",");
        if(root->right){
            printTree(root->right);
        }else{
            printf("NULL");
        }
        printf(")");
    }

    }
}

TreeNode *searchNode(TreeNode *root, int data){
	
	if(root){

		if(root->key != data){
			
			if(root->key > data){
				searchNode(root->left, data);
			}else{
				searchNode(root->right, data);
			}
		}else{
			
			return root;
		}
		
	}else{
		
	return NULL;
	}
	
}

void freeMemory(TreeNode *root){
	
	if(root){
		
		if(root->left)
			freeMemory(root->left);
		if(root->right)
			freeMemory(root->right);	
						
	free(root);
	}

}

int main(const int argc, const char **argv){

//---------------------------- Task 1 ----------------------------	
TreeNode *tree = NULL;

tree = treeInsert(tree, 10);

treeInsert(tree, 8);
treeInsert(tree, 19);
treeInsert(tree, 5);
treeInsert(tree, 9);
treeInsert(tree, 20);
treeInsert(tree, 14);

printTree(tree);
printf("\n");

printf("Tree is %s Balanced!", isBalanced(tree) ? "" : "not");
//----------------------------------------------------------------
printf("\n");
//----------------------------------------------------------------
//---------------------------- Task 2 ----------------------------

int const amountTree = 50;
int const amountNode = 10000;
TreeNode *forest[amountTree];
int truthCounter = 0;

	for(int i = 0; i < amountTree; i++){
		forest[i] = NULL;
		for(int j = 0; j < amountNode; j++){

			forest[i] = treeInsert(forest[i], rand()%amountNode);
		}

	}
	
	for(int i = 0; i < amountTree; i++){
		
			isBalanced(forest[i]) ? truthCounter++ : truthCounter + 0;
	}

	printf("\n");
	printf("%f percent Balanced trees!", ((float)amountTree * (float)truthCounter) / 100);

	for(int i = 0; i < amountTree; i++){
		freeMemory(forest[i]);
		forest[i] = NULL;
	}

//----------------------------------------------------------------
printf("\n");
//----------------------------------------------------------------
//---------------------------- Task 3 ----------------------------

TreeNode *treeNode = searchNode(tree, 5);

	if(treeNode != NULL)
		printf("Desired value %d;", treeNode->key);
	else
		printf("Value not found!");

freeMemory(tree);
treeNode = NULL;
tree = NULL;

    return 0;
}
