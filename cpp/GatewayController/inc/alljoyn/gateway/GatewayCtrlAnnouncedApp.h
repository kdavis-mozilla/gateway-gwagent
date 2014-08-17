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

#ifndef GatewayCtrlAnnouncedApp_H
#define GatewayCtrlAnnouncedApp_H

#include <map>
#include <qcc/String.h>
#include <alljoyn/about/AboutClient.h>

#define UUID_LENGTH  16

namespace ajn {
namespace gwcontroller {

class GatewayCtrlAnnouncedApp {
  public:

    GatewayCtrlAnnouncedApp() { }

    /**
     * init
     * @param busName The name of the {@link BusAttachment} of the device that sent the Announcement
     * @param appName The name of the application
     * @param appId The application id
     * @param deviceName The name of the device
     * @param deviceId The device id
     */
    void init(const qcc::String& busName, const qcc::String& appName, uint8_t*appId, const qcc::String& deviceName, const qcc::String& deviceId);

    /**
     * init
     * @param busName The name of the {@link BusAttachment} of the device that sent the Announcement
     * @param aboutData The data sent with the Announcement
     * @return {@link QStatus}
     */
    QStatus init(const qcc::String& busName, ajn::services::AboutClient::AboutData const& aboutData);

    /**
     * Destructor
     */
    virtual ~GatewayCtrlAnnouncedApp();

    /**
     * @return The bus name
     */
    const qcc::String& getBusName();

    /**
     * @return The name of the application that sent the announcement
     */
    const qcc::String& getAppName() const;

    /**
     * @return Id of the application that sent the announcement
     */
    uint8_t*getAppId();

    /**
     * @return The name of the device that the application belongs to
     */
    const qcc::String& getDeviceName() const;

    /**
     * @return The id of the device that the application belongs to
     */
    const qcc::String& getDeviceId();

    /**
     * set bus name
     */

    void setBusName(const qcc::String& busName);

    /**
     * set bus name
     */
    void setAppName(const qcc::String& appName);

    /**
     * set app Id
     */
    void setAppId(uint8_t*appId, size_t len);

    /**
     * set device name
     */
    void setDeviceName(const qcc::String& deviceName);

    /**
     * set device Id
     */
    void setDeviceId(const qcc::String& deviceId);


  private:
    /**
     * Create an entry. If information is missing from the aboutData map an empty string is entered instead
     */
    qcc::String getAboutDataEntry(ajn::services::AboutClient::AboutData const& aboutData, const qcc::String& key);

    /**
     * The unique name of the {@link BusAttachment} that sent the Announcement signal
     */
    qcc::String m_BusName;

    /**
     * The name of the application that sent the announcement
     */

    qcc::String m_AppName;

    /**
     * The Id of the application that sent the announcement
     */
    uint8_t m_AppId[UUID_LENGTH];

    /**
     * The name of the device that the application belongs to
     */
    qcc::String m_DeviceName;

    /**
     * The id of the device that the application belongs to
     */
    qcc::String m_DeviceId;
};
}
}
#endif /* defined(GatewayCtrlAnnouncedApp_H) */