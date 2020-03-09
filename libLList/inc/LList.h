#ifndef LLIST_H
#define LLIST_H

#include "LLconf.h"

typedef struct Node *NodePtr;

/**
 * @brief Delete a Node
 * @warning Cannot delete the root node. Use deleteLList
 * 
 * @param[in,out] node outputs as former note->next
 */
void deleteNode(NodePtr node);

/**
 * @brief Get the Data from Node object
 * 
 * @param[in] node 
 * @return Data 
 */
Data getNodeData(const NodePtr node);

/**
 * @brief Get the next Node object
 * 
 * @param[in] node 
 * @return NodePtr 
 */
NodePtr getNodeNext(const NodePtr node);

/**
 * @brief Push data to the head of a LList
 * 
 * @param[in] head of LList
 * @param[in] data
 * 
 * @return NodePtr to the new head
 */
void pushLList(NodePtr *head, const Data data);

/**
 * @brief Create a LList with data in the head
 * 
 * @param[in] data
 * @return NodePtr to head
 */
NodePtr createLList(const Data data);

/**
 * @brief Delete the entire LList from head
 * 
 * @param[in] head 
 */
void deleteLList(NodePtr head);

/**
 * @brief Print the LList starting from head
 * 
 * @param[in] head 
 */
void printLList(const NodePtr head);

#endif /* LLIST_H */