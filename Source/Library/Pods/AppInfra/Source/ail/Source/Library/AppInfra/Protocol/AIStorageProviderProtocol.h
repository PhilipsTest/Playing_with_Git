//
//  AIStorageProviderProtocol.h
//  AppInfra
//
//  Created by Senthil on 22/06/16.
/*  Copyright ©  Koninklijke Philips N.V.,  All rights are reserved.
 *Reproduction or dissemination in whole or in part is prohibited 
 *without the prior written consent of the copyright holder.*/
//

#import <Foundation/Foundation.h>

/**
 protocol for defining secure storage methods
 */
@protocol AIStorageProviderProtocol <NSObject>

typedef NS_ENUM(NSUInteger,AISSError)
{
    AISSErrorCodeAccessKeyFailure  = 1,
    AISSErrorCodeUnknownKey        = 2,
    AISSErrorCodeDecryptionError   = 3,
    AISSErrorCodeEncryptionError   = 4,
    AISSErrorCodeUnarchiveFailure  = 5,
    AISSErrorCodeNoDataFoundForKey = 6,
    AISSErrorCodearchiveFailure    = 7,
    AISSErrorCodeInvalidInput      = 8,
    AISSErrorCodeInvalidDataType   = 9,
};

/**
 Method to store any object securely into user defaults
 @param object any object to be securely stored
 @param key a string to identify the data on user defaults
 @param error error object
 @since 1.0.0
 */
- (BOOL)storeValueForKey:(nonnull NSString*)key
                   value:(nonnull id<NSCoding>)object
                   error:(NSError *_Nullable*_Nullable)error;

/**
 Method to fetch the object stored against the key provided
 @param key a string to identify the data on user defaults
 @param error error object
 @returns the object stored against the key provided
 @since 1.0.0
 */

-(nullable id)fetchValueForKey:(nonnull NSString*)key
                         error:( NSError *_Nullable*_Nullable)error;

/**
 Method to delete the object stored against the key provided
 @param key a string to identify the data on user defaults
 @since 1.0.0
 */
- (void)removeValueForKey:(nonnull NSString*)key;


/**
 Method to loadData
 @param data data to be loaded It can be any customObject which confirms to NSCoding protocol
 @param error error object
 @returns encrypted data
 @since 1.0.0
 */
-(nullable NSData*)loadData:(nonnull id <NSCoding>)data
                         error:(NSError *_Nullable*_Nullable)error;

/**
 Method to parseData Data
 @param data data to be parsed
 @param error error object
 @returns decrypted data
 @since 1.0.0
 */
-(nullable id)parseData:(nonnull NSData*)data
                              error:(NSError *_Nullable*_Nullable)error;

/**
 Method to check whether passcode lock is enabled in devie
 
 @returns Bool value indicating whether passcode is enabled or not
 @since 2.1.0
 */
-(BOOL) deviceHasPasscode;

/**
 Method to check whether devices is rooted or not
 
 @returns "true" if device is jailbroken else returns "false"
 @since 2.2.0
 */
-(nonnull NSString *)getDeviceCapability;

@end
