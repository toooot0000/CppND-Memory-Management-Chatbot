#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.emplace_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.emplace_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &chatbot)
{
    _chatBot = ChatBot(std::move(chatbot));
    _chatBot.SetCurrentNode(this);
    // Isn't making chatbot a unique_ptr passed through every node a better implementation?
    // Since no ChatBot is constructed or moved, which would reduce the time and space cost. 
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}