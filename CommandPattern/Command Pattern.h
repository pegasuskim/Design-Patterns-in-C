

/*
CommandPattern

사용자가 내린 명령을 객체화 하고, 서로 다른 명령들 역시 객체화 하여서 사용자에게 파라미터로 넘겨줄 수 있게 한다. 

각요소들의 역할

 

- Command: 오퍼레이션 수행에 필요한 인터페이스를 정의한다.
- ConcreteCommand: Command의 인터페이스를 실제로 구현한다, Receiver와 액션사이의 연결을 정의한다.
- Client: ConcreteCommand를 생성하고, Receiver을 할당하는 역할을 한다.
- Invoker: 명령을 처음 실행하는 역할로 Command에서 정의된 인터페이스를 호출한다.
- Receiver: 명령을 받아들이는 대상이 된다.
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
