//
//  ISAdMobAdapter.h
//  ISAdMobAdapter
//
//  Copyright © 2022 ironSource Mobile Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"
 
static NSString * const AdMobAdapterVersion = @"4.3.38";
static NSString * GitHash = @"";

//System Frameworks For AdMob Adapter

@import AdSupport;
@import AudioToolbox;
@import AVFoundation;
@import CFNetwork;
@import CoreGraphics;
@import CoreMedia;
@import CoreTelephony;
@import CoreVideo;
@import JavaScriptCore;
@import MediaPlayer;
@import MessageUI;
@import MobileCoreServices;
@import QuartzCore;
@import SafariServices;
@import Security;
@import StoreKit;
@import SystemConfiguration;
@import WebKit;

@interface ISAdMobAdapter : ISBaseAdapter

@end
