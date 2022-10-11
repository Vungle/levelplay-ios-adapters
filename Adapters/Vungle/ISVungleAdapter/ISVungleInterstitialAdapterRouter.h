//
//  ISVungleInterstitialAdapterRouter.h
//  ISVungleAdapter
//
//  Copyright © 2020 ironSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VungleAdsSDK/VungleAdsSDK.h>
#import "IronSource/ISBaseAdapter+Internal.h"

NS_ASSUME_NONNULL_BEGIN

@class ISVungleAdapter;
@interface ISVungleInterstitialAdapterRouter : NSObject<VungleInterstitialDelegate>

@property (nonatomic, strong) NSString* placementID;
@property (nonatomic, weak) id<ISInterstitialAdapterDelegate> delegate;
@property (nonatomic, strong) VungleInterstitial *interstitialAd;

- (instancetype)initWithPlacementID:(NSString *)placementID
                           delegate:(id<ISInterstitialAdapterDelegate>)delegate;

- (void)loadInterstitial;
- (void)playInterstitialAdWithViewController:(UIViewController *)viewController;
- (void)setBidPayload:(NSString * _Nullable)bidPayload;

- (void)interstitialInitSuccess;
- (void)interstitialInitFailed:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
