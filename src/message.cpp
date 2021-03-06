#include "message.hpp"
#include "location.hpp"
#include <filesystem>

std::vector<Message> messages;

Message::Message(MessageKind kind, std::string message, yy::location loc) {
  this->kind = kind;
  this->message = message;
  this->loc = loc;
}

void Message::error(std::string msg, yy::location loc) {
  messages.push_back(Message(MessageKind::ERROR, msg, loc));
}

void Message::note(std::string msg, yy::location loc) {
  messages.push_back(Message(MessageKind::NOTE, msg, loc));
}

void Message::error(std::string msg) {
  messages.push_back(Message(MessageKind::ERROR, msg, yy::location()));
}

void Message::note(std::string msg) {
  messages.push_back(Message(MessageKind::NOTE, msg, yy::location()));
}

std::ostream &operator<<(std::ostream &os, Message &e) {
  yy::position begin = e.loc.begin;

  if (!e.loc.begin.filename) {
    os << "jc: " << (e.kind == MessageKind::ERROR ? "error" : "note") << ": "
       << e.message << std::endl;
  } else {
    std::string fn = std::filesystem::relative(*begin.filename,
                                               std::filesystem::current_path());

    os << fn << ":" << begin.line << ":" << begin.column << ": "
       << (e.kind == MessageKind::ERROR ? "error" : "note") << ": " << e.message
       << std::endl;
  }

  return os;
}