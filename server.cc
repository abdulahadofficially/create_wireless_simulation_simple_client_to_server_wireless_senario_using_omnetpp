/*
 * server.cc
 *
 *  Created on: Mar 5, 2022
 *      Author: Abdul Ahad
 */




#include <omnetpp.h>
using namespace omnetpp;

class Server: public cSimpleModule{
    cMessage *msg;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};
Define_Module(Server);

void Server::initialize(){

}
void Server::handleMessage(cMessage *msg){
    msg = new cMessage("CTS");
    cModule *target=getParentModule()->getSubmodule("Client");
    sendDirect(msg,target,"radioIn");
}
