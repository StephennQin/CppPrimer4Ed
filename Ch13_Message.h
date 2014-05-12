// C++ Primer 4th Edition Chapter 13 Exercise Section 13.4 Exercise 13.16-19
/*
// Usage:
#include "Ch13_Message.h"

int main()
{
    Message  msg1("new message !");
    Folder fldr1;
	msg1.save(fldr1) ;

	return 0;
}
*/
#include <iostream>
#include <string>
#include <set>

#ifndef MESSAGE_H
#define MESSAGE_H

class Message;
class Folder
{
    public:
        Folder() {};
        ~Folder();
        Folder(const Folder& other);
        Folder& operator=(const Folder& other);

        //  add/remove specified Message from this Folder
        void save(Message&);
        void remove(Message&);
        // add/remove this Folder from specified Message
        void addMsg(Message*);
        void remMsg(Message*);
    protected:
    private:
        // Data:
        std::set<Message*> message;
        // Utility Functions:
        void put_Fldr_in_Messages(const std::set<Message*>& rhs);
        void remove_Fldr_from_Messages();
};

class Message
{
    public:
        // folders is initialized to the empty set automatically
        Message(const std::string &str = ""):
            contents(str) { }
        // copy control: we must manage pointers to this Message
        // from the Folders pointed to by folders
        ~Message();// virtual ~Message();
        Message(const Message& other);
        Message& operator=(const Message& other);

        // add/remove this Message from specified Folder's set of messages
        void save(Folder&);
        void remove(Folder&);
        // add/remove specified Folder from this Message
        void addFldr(Folder*);
        void remFldr(Folder*);
    protected:

    private:
        // Data:
        std::string contents;
        std::set<Folder*> folders;
        // Utility Functions:
        void put_Msg_in_Folders(const std::set<Folder*>& rhs);
        void remove_Msg_from_Folders();
};

Folder::~Folder()
{
    //dtor
    remove_Fldr_from_Messages();
}

Folder::Folder(const Folder& other):
    message(other.message)
{
    //copy ctor
    put_Fldr_in_Messages(other.message);
}

Folder& Folder::operator=(const Folder &rhs)
{
    if (this == &rhs) return *this;
    remove_Fldr_from_Messages();
    message = rhs.message;
    put_Fldr_in_Messages(rhs.message);
    return *this;
}

void Folder::put_Fldr_in_Messages(const std::set<Message*> &rhs)
{
	for( std::set<Message*>::const_iterator beg = rhs.begin();
                                            beg != rhs.end(); ++beg )
        (*beg)->addFldr(this);
}

void Folder::remove_Fldr_from_Messages()
{
	for( std::set<Message*>::const_iterator beg = message.begin();
                                            beg != message.end();++beg )
        (*beg)->remFldr(this);
}

void Folder::save(Message& msg)
{
    addMsg(&msg);
    msg.addFldr(this);
}

void Folder::remove(Message& msg)
{
    remMsg(&msg);
    msg.remFldr(this);
}

void Folder::addMsg(Message* msg)
{
    message.insert(msg);
}

void Folder::remMsg(Message* msg)
{
    message.erase(msg);
}

Message::~Message()
{
    //dtor
    remove_Msg_from_Folders();
}

Message::Message(const Message& other):
    contents(other.contents), folders(other.folders)
{
    //copy ctor
    // add this Message to each Folder that points to other
    put_Msg_in_Folders(folders);
}

Message& Message::operator=(const Message& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    remove_Msg_from_Folders();  // update existing Folders
    contents = rhs.contents;    // copy contents from rhs
    folders = rhs.folders;      // copy Folder pointers from rhs
    // add this Message to each Folder in rhs
    put_Msg_in_Folders( rhs.folders );
    return *this;
}

// add this Message to Folders that point to rhs
void Message::put_Msg_in_Folders(const std::set<Folder*>& rhs)
{
	for( std::set<Folder *>::const_iterator beg = rhs.begin();
                                        beg != rhs.end(); ++beg )
        (*beg)->addMsg(this);
}

// remove this Message from corresponding Folders
void Message::remove_Msg_from_Folders()
{
    // remove this message from corresponding folders
    for( std::set<Folder*>::const_iterator beg = folders.begin ();
            beg != folders.end (); ++beg )
        (*beg)->remMsg(this); // *beg points to a Folder
}

void Message::save(Folder& fldr)
{
    addFldr( &fldr );
    fldr.addMsg( this );
}

void Message::remove(Folder& fldr)
{
    remFldr( &fldr );
    fldr.remMsg( this );
}

void Message::addFldr(Folder* fldr)
{
    folders.insert( fldr );
}

void Message::remFldr(Folder* fldr)
{
    folders.erase( fldr );
}

#endif // MESSAGE_H
