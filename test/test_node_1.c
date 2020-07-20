/*
 * File:    test_node_1.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
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
  int test_val;
  test_val = 0;

  test_val = nodeCost(NULL);
  if (test_val != 0) {
    return false;
  }

  Node *n_1 = NULL;
  n_1 = createNode(0, 0, NULL, NULL);
  test_val = nodeCost(n_1);
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
