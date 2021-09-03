#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"
#include <memory>
#include "graphnode.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;

    // I don't think we need a vector of edges here.
    // Because the moment we create an edge object in LoadAnswerGraphFromFile(), 
    // we can transfer the ownership immediately to the node without putting 
    // it into a vector first; Even if in the future the "product manager" (if any)
    // wants the chatlogic to modify edges, still this logic should be based on 
    // nodes(for example, GraphNode.deleteEdge(GraphoNode _toNode), and ChatLogic call
    // this method on a specific node).  

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode{nullptr};
    ChatBot *_chatBot{nullptr};
    ChatBotPanelDialog *_panelDialog{nullptr};

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic(){};
    ~ChatLogic(){};

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */