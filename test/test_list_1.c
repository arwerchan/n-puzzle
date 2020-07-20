/**
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * File:    test_list_1
 * Prologue:
 */
#include<stdbool.h>

#include "../include/list.h"

#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif

#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

bool testPop() {

  List *testList = NULL;
  Node *testNode_1 = NULL;
  Node *testNode_2 = NULL;

  testNode_1 = popNode(NULL);
  if (testNode_1 != NULL) {
    return false;
  }

  testList = (List*)malloc(sizeof(List));
  testList->tail = NULL;
  testNode_2 = popNode(&testList);
  if (testNode_2 != NULL) {
    free(testList);
    return false;
  }

  testNode_1 = (Node*)malloc(sizeof(Node));
  testList->tail = testNode_1;
  testNode_2 = NULL;
  testNode_2 = popNode(&testList);
  if (testNode_2 == NULL) {
    free(testList);
    free(testNode_1);
    return false;
  }

  free(testList);
  free(testNode_1);
  return true;
}


int main() {
  
  if (testPop() == false) {
    return TEST_FAILED;
  }

  return TEST_PASSED;
}
