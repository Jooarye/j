#pragma once

#include "location.hpp"
#include <string>
#include <vector>

enum class MessageKind { ERROR, NOTE };

class Message {
public:
  Message(MessageKind k, std::string message, yy::location loc);

  static void error(std::string, yy::location);
  static void note(std::string, yy::location);

  static void error(std::string);
  static void note(std::string);

  MessageKind kind;
  std::string message;
  yy::location loc;
};

extern std::vector<Message> messages;

std::ostream &operator<<(std::ostream &, Message &);