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

#import <Foundation/Foundation.h>
#import "alljoyn/gateway/AnnouncedApp.h"

@interface AJGWCAnnouncedApp : NSObject
/**
 * Constructor
 * @param busName The name of the {@link AJNBusAttachment} of the device that sent the Announcement
 * @param appName The name of the application
 * @param appId The application id
 * @param appIdLength The application id length
 * @param deviceName The name of the device
 * @param deviceId The device id
 */
- (id)initWithBusName:(NSString*) busName appName:(NSString*) appName appId:(uint8_t*) appId appIdLength:(uint32_t)appIdLength deviceName:(NSString*) deviceName deviceId:(NSString*)deviceId;

/**
 * Constructor
 * @param busName The name of the {@link AJNBusAttachment} of the device that sent the Announcement
 * @param aboutData The data sent with the Announcement
 */
- (id)initWithBusName:(NSString*) busName aboutData:(NSDictionary *) aboutData;

/**
 * @return The bus name
 */
- (NSString*)busName;

/**
 * @return The name of the application that sent the announcement
 */
- (NSString*)appName;

/**
 * @return Id of the application that sent the announcement
 */
- (uint8_t*)appId;

/**
 * @return The name of the device that the application belongs to
 */
- (NSString*)deviceName;

/**
 * @return The id of the device that the application belongs to
 */
- (NSString*)deviceId;

/**
 * Returns the cpp handle of this class
 * @return AnnouncedApp
 */
- (ajn::gwc::AnnouncedApp*)handle;

@end
