/******************************************************************************
 * Copyright (c) 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#import "AJGWCConnectorAppStatusSignalHandlerAdapter.h"
#import "AJGWCConnectorAppStatus.h"
#import "alljoyn/about/AJNConvertUtil.h"

AJGWCConnectorAppStatusSignalHandlerAdapter::AJGWCConnectorAppStatusSignalHandlerAdapter(id <AJGWCConnectorAppStatusSignalHandler> handle)
{
    connectorAppStatusSignalHandler = handle;
}

AJGWCConnectorAppStatusSignalHandlerAdapter::~AJGWCConnectorAppStatusSignalHandlerAdapter()
{
}


void AJGWCConnectorAppStatusSignalHandlerAdapter::onStatusSignal(const qcc::String &appId, const ajn::gwc::ConnectorAppStatus *ConnectorAppStatus)
{
    AJGWCConnectorAppStatus* gwConnectorAppStatus = [[AJGWCConnectorAppStatus alloc] initWithHandle:const_cast<ajn::gwc::ConnectorAppStatus*>(ConnectorAppStatus)];
    [connectorAppStatusSignalHandler onStatusSignal:[AJNConvertUtil convertQCCStringtoNSString:appId] status:gwConnectorAppStatus];
}

void AJGWCConnectorAppStatusSignalHandlerAdapter::onError(const qcc::String& appId, const QStatus &status)
{
    [connectorAppStatusSignalHandler onError:[AJNConvertUtil convertQCCStringtoNSString:appId] errorCode:status];
}

