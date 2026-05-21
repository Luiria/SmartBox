#ifndef MAILBOX_MESSAGES_H
#define MAILBOX_MESSAGES_H

#include "MailBoxState.h"

class MailBoxMessages
{

public:
    static const char *getMessage(MailBoxState state)
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
};

#endif