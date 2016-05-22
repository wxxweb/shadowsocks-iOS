//
//  NAInterface.h
//  NAChloride
//
//  Created by Gabriel on 6/25/14.
//  Copyright (c) 2014 Gabriel Handford. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const NSUInteger NASecretBoxKeySize;
extern const NSUInteger NASecretBoxNonceSize;

@protocol NACryptoBox
- (NSData *)encrypt:(NSData *)data key:(NSData *)key error:(NSError * __autoreleasing *)error;
- (NSData *)decrypt:(NSData *)data key:(NSData *)key error:(NSError * __autoreleasing *)error;
@end

@protocol NACryptoStream
- (NSData *)encrypt:(NSData *)data nonce:(NSData *)nonce key:(NSData *)key error:(NSError * __autoreleasing *)error;
- (NSData *)decrypt:(NSData *)data nonce:(NSData *)nonce key:(NSData *)key error:(NSError * __autoreleasing *)error;
@end

@protocol NAHMAC
- (NSData *)HMACForKey:(NSData *)key data:(NSData *)data;
@end


@protocol NADigest
- (NSData *)digestForData:(NSData *)data;
@end

void NAChlorideInit(void);

#define NAWeakObject(o) __typeof__(o) __weak
#define NAWeakSelf NAWeakObject(self)