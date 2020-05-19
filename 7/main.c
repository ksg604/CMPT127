#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  // test the create function
  list_t* list = list_create();
  list_t* temp = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL )
    {
      printf( "create: create failed to malloc\n" );
      return 1;
    }

  if( list->head != NULL )
    {
      printf( "create: head is not null!\n" );
      return 1;
    }

  if( list->tail != NULL )
    {
      printf( "create: tail is not null!\n" );
      return 1;
    }

  // now test all the other functions (except list_print) to see if
  // they do what they are supposed to

  // you code goes here
  if(temp == NULL)
  {
  	printf("problem");
  	return 1;
  }
  if(temp->head != NULL)
  { 
  	printf("problem");
  	return 1;
        
  } 
  if(temp->tail != NULL) 
  {
  	printf("problem");
	  return 1;
  }

  element_t * tempNode = list_index(temp,1);
  if(tempNode != NULL)
  {
  	return 1;
  }
   
  list_append(list,7);
  list_append(list,14);
  list_append(list,12);
  list_append(list,17);
  list_prepend(list,50);
  list_prepend(list,100); //List should look like 100->50->7->14->12->17
  list_prepend(temp,17);

  if(temp->tail->val != 17)
  {
  	return 1;
  }
  

  element_t * nodep1 = list_index(list,4); //val should be 12
  element_t * nodep2 = list_index(list,0); //val should be 100
  element_t * nodep3 = list_index(list,20); //node should be null

  if(nodep1 == NULL)
  {
  	return 1;
  }


  if(nodep2->val != 100)
  {
  	return 1;
  }
  if(nodep3 != NULL)
  {
  	return 1;
  }


  
  element_t * node = element_create(21);
  if(node == NULL)
  {
  	return 1;
  }
  element_t * node2 = element_create(22);

  if(node2 == NULL) 
  {
  	return 1;
  }
  if(node == node2)
  {
  	return 1;
  }

  node->next = node2;
  free(node);
  node = element_create(21);
  if(node == NULL)
  {
  	return 1;
  }
  if(node->next != NULL)
  {
  	return 1;
  }
      
  list_destroy(list);
    
  list_destroy(temp);


	printf("test passed");
  
  return 0; // tests pass
}
