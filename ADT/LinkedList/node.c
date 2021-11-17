/* File: node.c */
/* Implementasi Node */

#include "node.h"

Address newNode(ElTypeNode val) {
  Address p = (Address)malloc(sizeof(Node));
  if (p != NULL) {
    INFO_NODE(p) = val;
    NEXT_NODE(p) = NULL;
  }
  return p;
}