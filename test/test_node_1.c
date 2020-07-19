/*
 * File: test_node_1.c
 * Author: Andrew Werchan
 * Function: Test the nodeCost function
 */
#include<stdbool.h>
#include<stdio.h>

#include "../include/node.h"

#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif
#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

bool testCost() {
  Node *n_1 = NULL;
  int test_val;
  test_val = 0;

  test_val = nodeCost(NULL);
  if (test_val != 0) {
    return false;
  }

  n_1 = createNode(0, 0, NULL, NULL);

  if (test_val != 0) {
    return false;
  }

  return true;

}

int main(){
  if (testCost()) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
}
