/*
 * client.cc
 *
 *  Created on: Mar 5, 2022
 *      Author: Abdul Ahad
 */



#include <omnetpp.h>
using namespace omnetpp;

class client: public cSimpleModule{
    cMessage *msg;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};
Define_Module(Client::Server);


void client::initialize(){
    EV <<"client initialize"<<"\n";
    msg=new cMessage("RTS");
    scheduleAt(simTime()+dblrand(),msg->dup());
    EV<<"Client initialize complete"<<"\n";
}
void client::handleMessage(cMessage *msg){
    EV <<"client handle message initialize"<<"\n";
    cModule *target;
    msg=new cMessage("RTS");
    target = getParentModule()->getSubmodule("Server");
    sendDirect(msg, target,"radioIn");
    scheduleAt(simTime()+dblrand(),msg->dup());
}


