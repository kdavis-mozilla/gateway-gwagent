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
#import "AJGWCGatewayCtrlEnums.h"
#import "AJGWCGatewayCtrlAclRules.h"
#import "alljoyn/gateway/GatewayCtrlAclWriteResponse.h"

@interface AJGWCGatewayCtrlAclWriteResponse : NSObject

/**
 * Constructor
 * @param handle A handle to a cpp GatewayCtrlAclWriteResponse object
 */
- (id)initWithHandle:(ajn::gwcontroller::GatewayCtrlAclWriteResponse*) handle;

/**
 * Constructor
 * @param aclId The ACL id
 * @param code {@link AJGWCAclResponseCode}
 * @param invalidRules {@link AJGWCGatewayCtrlAclRules}
 * @param objPath Object path
 */
- (id)initWithAclId:(NSString*) aclId code:(AJGWCAclResponseCode) code invalidRules:(AJGWCGatewayCtrlAclRules *) invalidRules objPath:(NSString*) objPath;

/**
 * @return The id of the ACL that the write operation was referred to
 */
- (NSString*)aclId;

/**
 * @return {@link AJGWCAclResponseCode} of the ACL write action
 */
- (AJGWCAclResponseCode)responseCode;

/**
 * @return {@link AJGWCGatewayCtrlAclRules} with the rules that don't comply with the {@link AJGWCGatewayCtrlConnectorCapabilities}
 */
- (AJGWCGatewayCtrlAclRules*)invalidRules;

/**
 * @return object path
 */
- (NSString*)objectPath;

- (ajn::gwcontroller::GatewayCtrlAclWriteResponse*)handle;
@end
