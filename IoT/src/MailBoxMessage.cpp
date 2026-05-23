#include "MailBoxMessage.h"

const char *MailBoxMessages::getMessage(MailBoxState state)
{
    switch (state)
    {
    case MailBoxState::OPEN:
        return "La porte de la boîte aux lettres a été ouverte."
               "Veuillez vérifier si vous avez reçu du courrier.";

    case MailBoxState::MAIL_INSERTED:
        return "Du courier a été détectée dans la boîte aux lettres.";

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
           "\"email\":\"" + email +
           "\"," + "\"subject\":\"" + subject + "," +
           "\"message\":\"" + message + "\"" +
           "}";
}