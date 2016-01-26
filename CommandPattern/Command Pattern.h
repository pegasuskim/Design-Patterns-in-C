

/*
CommandPattern

����ڰ� ���� ����� ��üȭ �ϰ�, ���� �ٸ� ��ɵ� ���� ��üȭ �Ͽ��� ����ڿ��� �Ķ���ͷ� �Ѱ��� �� �ְ� �Ѵ�. 

����ҵ��� ����

 

- Command: ���۷��̼� ���࿡ �ʿ��� �������̽��� �����Ѵ�.
- ConcreteCommand: Command�� �������̽��� ������ �����Ѵ�, Receiver�� �׼ǻ����� ������ �����Ѵ�.
- Client: ConcreteCommand�� �����ϰ�, Receiver�� �Ҵ��ϴ� ������ �Ѵ�.
- Invoker: ����� ó�� �����ϴ� ���ҷ� Command���� ���ǵ� �������̽��� ȣ���Ѵ�.
- Receiver: ����� �޾Ƶ��̴� ����� �ȴ�.
*/


// Command Pattern
#include <iostream.h>
#include <vector>

namespace Command {

 // "Receiver"
 class Receiver {
  public:
   // Methods
   void Action(){
    cout << " - Called Receiver.Action() \n";
   }
 };

 // "Command"
 class Command {
  protected:
   // Fields
   Receiver* receiver;
  public:
   // Constructors
   Command(Receiver* receiver){
    this->receiver = receiver;
   }
   virtual void Execute() = 0;//{}
 };
 
 // "Concrete Command"
 class ConcreteCommand : public Command {
  private:
   // Fields
   int id;
  public:
   // Consturctions
   ConcreteCommand(Receiver* receiver,int id) : Command(receiver){
    this->id = id;
   }
   // Methods
   virtual void Execute() {
    cout << "ID: " << id;
    receiver->Action();
   }
 };
 
 // "Invoker"
 class Invoker {
  // Fields
  private:
   std::vector<Command*> commands;
   Receiver* receiver;
   int currentPos;
  
  public:
   // Constructor
   Invoker(Receiver* receiver){
    currentPos = 0;
   }
   // Destructor
   ~Invoker(){
    std::vector<Command*>::iterator li;
    for(li = commands.begin(); li != commands.end() ; li++)
    {
     if(*li)
      delete *li;
    }
    commands.clear();
   }
   // Methods
   void Append(Command* c){
    commands.push_back(c);
   }
  
   void ExecuteCommand(int n){
    Command* c = new ConcreteCommand(receiver, n);
    c->Execute();
    Append(c);
    currentPos++;
   }
   void Redo(int depth){
    if(depth > commands.size())
     return;
    for(int i=0; i<depth; i++){
     commands[i]->Execute();
    }
   }
   // Not Implemented
   void Undo(int depth){}
   // Not Use
   /*
   void SetCommand(Command* command){
    this->command = command;
   }*/
 };
};
