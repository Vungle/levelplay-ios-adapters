//
//  ISAdMobInterstitialDelegate.m
//  ISAdMobAdapter
//
//  Created by maoz.elbaz on 24/02/2021.
//  Copyright © 2021 ironSource. All rights reserved.
//

#include "ISAdMobInterstitialDelegate.h"

@implementation ISAdMobInterstitialDelegate

- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                     andDelegate:(id<ISAdMobInterstitialDelegateWrapper>)delegate {
    self = [super init];
    if (self) {
        _adUnitId = adUnitId;
        _delegate = delegate;
    }
    return self;
}

/// Tells the delegate that the ad presented full screen content.
- (void)adWillPresentFullScreenContent:(id<GADFullScreenPresentingAd>)ad {
    [_delegate onInterstitialDidOpen:_adUnitId];
}

/// Tells the delegate that the ad failed to present full screen content.
- (void)ad:(id<GADFullScreenPresentingAd>)ad didFailToPresentFullScreenContentWithError:(NSError *)error {
    [_delegate onInterstitialShowFail:_adUnitId withError:error];
}

/// Tells the delegate that an impression has been recorded for the ad.
- (void)adDidRecordImpression:(id<GADFullScreenPresentingAd>)ad {
}

/// Tells the delegate that a click has been recorded for the ad.
- (void)adDidRecordClick:(id<GADFullScreenPresentingAd>)ad {
    [_delegate onInterstitialDidClick:_adUnitId];
}

/// Tells the delegate that the ad will dismiss full screen content.
- (void)adWillDismissFullScreenContent:(id<GADFullScreenPresentingAd>)ad {
}

/// Tells the delegate that the ad dismissed full screen content.
- (void)adDidDismissFullScreenContent:(id<GADFullScreenPresentingAd>)ad {
     [_delegate onInterstitialDidClose:_adUnitId];

}




@end
