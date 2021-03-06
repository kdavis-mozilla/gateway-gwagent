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

#ifndef RemotedApp_H
#define RemotedApp_H

#include <vector>
#include <alljoyn/gateway/AnnouncedApp.h>
#include <alljoyn/gateway/RuleObjectDescription.h>

namespace ajn {
namespace gwc {
class RemotedApp : public AnnouncedApp {
  public:

    /**
     * Constructor - must call appropriate init
     */
    RemotedApp() { }

    /**
     * init
     * @param busUniqueName The name of the {@link BusAttachment} of the remoted application
     * @param appName The name of the application
     * @param appId The application id
     * @param deviceName The name of the device
     * @param deviceId The device id
     * @param ruleObjDescriptions Configuration of the object paths and interfaces that are
     * used by the Connector App to reach this remoted application
     * @return {@link QStatus}
     */
    QStatus init(const qcc::String& busUniqueName, const qcc::String& appName, uint8_t*appId, const qcc::String& deviceName, const qcc::String& deviceId, const std::vector<RuleObjectDescription*>& ruleObjDescriptions);

    /**
     * init
     * @param remotedAppInfo MsgArg with the information for this remoted app
     * @param ruleObjDescriptions vector with object description rules for the remoted app
     * @param internalMetadata map of the internal metadata
     * @return {@link QStatus}
     */
    QStatus init(const ajn::MsgArg*remotedAppInfo, const std::vector<RuleObjectDescription*>& ruleObjDescriptions, const std::map<qcc::String, qcc::String>& internalMetadata);

    /**
     * init
     * @param aboutData Announcement's about data object
     * @param ruleObjDescriptions vector with object description rules for the remoted app
     * @return {@link QStatus}
     */
    QStatus init(ajn::services::AboutClient::AboutData const& aboutData, const std::vector<RuleObjectDescription*>& ruleObjDescriptions);


    /**
     * init
     * @param announcedApp The {@link AnnouncedApp} to be used to build this {@link RemotedApp}
     * @param ruleObjDescriptions Configuration of the object paths and interfaces that are
     * used by the Connector App to reach this remoted application
     * @return {@link QStatus}
     */
    QStatus init(AnnouncedApp* announcedApp, const std::vector<RuleObjectDescription*>& ruleObjDescriptions);

    /**
     * Destructor
     */
    virtual ~RemotedApp();

    /**
     * Configuration of the object paths and interfaces that are
     * used by the Connector App to reach this remoted application
     * @return List of {@link RuleObjectDescription} objects
     */
    const std::vector<RuleObjectDescription*>& getRuleObjDesciptions();

    /**
     * release allocations and empty object. must be called before deletion of object.
     * @return {@link QStatus}
     */
    QStatus release();

  private:
    /**
     * Configuration of the object paths and interfaces that are
     * used by the Connector App to reach this remoted application
     */
    std::vector<RuleObjectDescription*> m_RuleObjDescriptions;

    void emptyVector();
};
}
}

#endif /* defined(RemotedApp_H) */
