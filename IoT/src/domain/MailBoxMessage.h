#ifndef MAILBOX_MESSAGES_H
#define MAILBOX_MESSAGES_H

#include <Arduino.h>
#include "MailBoxState.h"

class MailBoxMessages
{

public:
    static const char *getMessage(MailBoxState state);
    static String buildEvent(const char *email, const char *subject, const char *message);
};

#endif