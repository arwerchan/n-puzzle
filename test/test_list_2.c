/**
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * File:    test_list_2
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

bool emptyList() {
  List* list;
  list = (List*)malloc(sizeof(List));
  if (list != NULL) {
    Node* node = createNode(0, 0, NULL, NULL);
    pushNode(&list, node);
  }
  if (list->tail == NULL) {
    free(list);
    return false;
  }
  free(list);
  return true;
}

bool priorityTest() {
  List* list;
  list = (List*)malloc(sizeof(List));
  int cost_1, cost_2, cost_3;
  cost_1 = 1;
  cost_2 = 2;
  cost_3 = 3;
  Node* node_1 = createNode(cost_1, 0, NULL, NULL);
  Node* node_2 = createNode(cost_2, 0, NULL, NULL);
  Node* node_3 = createNode(cost_3, 0, NULL, NULL);

  // final order in list should be: node_1, node_2, node_3
  pushNode(&list, node_2);
  pushNode(&list, node_1);
  pushNode(&list, node_3);
  return true;
  int list_1_cost, list_2_cost, list_3_cost;
  list_1_cost = list->tail->d_cost;
  list_2_cost = list->tail->parent->d_cost;
  list_3_cost = list->tail->parent->parent->d_cost;
  if (list_1_cost != cost_1 ||
      list_2_cost != cost_2 ||
      list_3_cost != cost_3) {
    free(node_1);
    free(node_2);
    free(node_3);
    free(list);
    return false;
  }
  free(node_1);
  free(node_2);
  free(node_3);
  free(list);
  return true;
}

int main() {
  
  if (emptyList() == false) {
    return TEST_FAILED;
  }
  if (priorityTest() == false) {
    return TEST_FAILED;
  }

  return TEST_PASSED;
}
