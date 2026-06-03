#include "domain/MailBoxMessage.h"

const char *MailBoxMessages::getMessage(MailBoxState state)
{
    switch (state)
    {
    case MailBoxState::OPEN:
        return "The mailbox door was opened. "
               "Please check whether you have received any mail.";

    case MailBoxState::MAIL_INSERTED:
        return "New mail has been detected in the mailbox.";

    default:
        return nullptr;
    }
}

String MailBoxMessages::buildEvent(
    const char *email,
    const char *subject,
    const char *message)
{
    return String("{") +
           "\"email\":\"" + email + "\"," +
           "\"subject\":\"" + subject + "\"," +
           "\"message\":\"" + message + "\"" +
           "}";
}