/*
   Copyright (C) 2018 Alexander Akulich <akulichalexander@gmail.com>

   This file is a part of TelegramQt library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

 */

#ifndef TELEGRAM_CLIENT_RPC_HELP_LAYER_HPP
#define TELEGRAM_CLIENT_RPC_HELP_LAYER_HPP

#include "ClientRpcLayerExtension.hpp"
#include "TLTypes.hpp"

namespace Telegram {

class PendingRpcOperation;

namespace Client {

class HelpRpcLayer : public BaseRpcLayerExtension
{
    Q_OBJECT
public:
    explicit HelpRpcLayer(QObject *parent = nullptr);

    // Generated Telegram API declarations
    PendingRpcOperation *getAppChangelog(const QString &deviceModel, const QString &systemVersion, const QString &appVersion, const QString &langCode);
    PendingRpcOperation *getAppUpdate(const QString &deviceModel, const QString &systemVersion, const QString &appVersion, const QString &langCode);
    PendingRpcOperation *getConfig();
    PendingRpcOperation *getInviteText(const QString &langCode);
    PendingRpcOperation *getNearestDc();
    PendingRpcOperation *getSupport();
    PendingRpcOperation *getTermsOfService(const QString &langCode);
    PendingRpcOperation *saveAppLog(const TLVector<TLInputAppEvent> &events);
    // End of generated Telegram API declarations
};

} // Client namespace

} // Telegram namespace

#endif // TELEGRAM_CLIENT_RPC_HELP_LAYER_HPP