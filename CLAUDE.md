# LevelPlay iOS Adapters

## Overview
Unity LevelPlay (ironSource) iOS mediation adapters. Contains 11 network adapters for serving ads through the ironSource mediation platform.

## Language
- **Objective-C** (100%)

## Build System
- **CocoaPods**: Per-adapter Podfile for dependency management
- **Xcode projects**: Per-adapter build targets
- **xcframework build scripts**: `build_XCFramework.sh` for multi-architecture framework builds

## Architecture
- Directory structure: `Adapters/{Network}/IS{Network}Adapter/`
- All adapters extend `ISBaseAdapter` base class
- Format-specific delegate classes per adapter
- Pattern: `IS{Network}Adapter.h/.m` + format delegates + constants file

## Ad Formats
- Banner (all adapters)
- Interstitial (all adapters)
- Rewarded Video (all adapters)
- Native Ads (Google adapter only)

## Vungle Adapter
- Adapter version: v4.3.36
- VungleAds SDK: 7.4.0

## Platform Requirements
- Min iOS: 12.0
- IronSource SDK: 8.2.0.0

## Key Conventions
- Adapter naming: `IS{Network}Adapter`
- ISBaseAdapter inheritance for shared lifecycle
- Delegate-per-format pattern (separate delegate class per ad format)
- Constants defined in dedicated header file
- xcframework built via shell scripts for simulator + device architectures
