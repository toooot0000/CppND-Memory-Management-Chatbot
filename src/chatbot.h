#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

/**
 * * The Rule of Three:
 * If a class requires any method listed below, then actually the left methods should 
 * also be implemented. 
 * * 1. destructor;
 * * 2. copy contructor;
 * * 3. copy assignment operator;
 * 
 * * The Rule of Five:
 * For a class that needs to use move sementics, you need to implement 2 more methods 
 * besides the 3 ones mentioned above
 * * 1. move constructor;
 * * 2. move assignment operator;
 */

/**
 * ? Shouldn't ChatBot be a singleton? Since logically there would be only one ChatBot 
 * ? availiable in the whole life time of the program?
 */

class ChatBot
{
private:
    // data handles (owned)
    std::string _imageFilename;
    wxBitmap *_image{nullptr}; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode{nullptr};
    GraphNode *_rootNode{nullptr};
    ChatLogic *_chatLogic{nullptr};

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();                    // destructor that takes care of all pointers.

    //// STUDENT CODE
    ////
    // copy constructor
    ChatBot(const ChatBot &other);

    // copy assignment operator
    ChatBot &operator=(const ChatBot &other);

    // move constructor
    ChatBot(ChatBot &&other) noexcept;

    // move assignment operator
    ChatBot &operator=(ChatBot &&other) noexcept;

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic *GetChatLogicHandle() const { return _chatLogic; }
    wxBitmap *GetImageHandle() const { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
