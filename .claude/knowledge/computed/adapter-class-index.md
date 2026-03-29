# LevelPlay (ironSource) — Vungle iOS Adapter Class Index

## Adapter Entry Point

| Class | Superclass | File |
|-------|-----------|------|
| `ISVungleAdapter` | `ISBaseAdapter` | `ISVungleAdapter.m` |

**Initialization**: `initSDKWithAppKey:userId:` → calls `[VungleAds initWithAppId:]`
**Network Key**: `"Vungle"` (registered in ironSource mediation)

## Format Delegates

| Format | Delegate Class | Protocol |
|--------|---------------|----------|
| Interstitial | `ISVungleInterstitialDelegate` | `ISAdapterInterstitialDelegate` |
| Rewarded | `ISVungleRewardedVideoDelegate` | `ISAdapterRewardedVideoDelegate` |
| Banner | `ISVungleBannerDelegate` | `ISAdapterBannerDelegate` |

## Callback Mapping (Vungle → LevelPlay)

| Vungle Callback | LevelPlay Callback | Context |
|----------------|-------------------|---------|
| `interstitialAdDidLoad:` | `adDidLoad` | Interstitial loaded |
| `interstitialAdDidFailToLoad:withError:` | `adDidFailToLoadWithError:` | Load failure |
| `interstitialAdWillPresent:` | `adDidOpen` | Shown |
| `interstitialAdDidClick:` | `adDidClick` | Click |
| `interstitialAdDidClose:` | `adDidClose` | Dismissed |
| `rewardedAdDidLoad:` | `adDidLoad` | Rewarded loaded |
| `rewardedAdDidRewardUser:` | `adDidReceiveReward` | Reward granted |
| `rewardedAdDidClose:` | `adDidClose` | Dismissed |
| `bannerAdDidLoad:` | `adDidLoad` | Banner loaded |
| `bannerAdDidClick:` | `adDidClick` | Click |
| `bannerAdDidTrackImpression:` | `adDidShow` | Impression |

## Bidding Support

- Implements `ISBiddingDataDelegate` protocol
- `collectBiddingDataWithDelegate:` → calls `[VungleAds getBiddingToken]`
- Token returned via `successWithBiddingData:` delegate callback

## Key Patterns

1. **Delegate-per-format**: Each format has its own delegate class within the adapter
2. **Singleton initialization**: `VungleAds` initialized once, completion block notifies all pending loads
3. **Banner size mapping**: ironSource `ISBannerSize` → Vungle banner size (320×50, 728×90, 300×250)
4. **Waterfall + bidding**: Supports both traditional waterfall and in-app bidding modes
5. **Privacy**: GDPR consent via `[VunglePrivacySettings setGDPRStatus:]`, CCPA via `setCCPAStatus:`, COPPA via `setCOPPAStatus:`
