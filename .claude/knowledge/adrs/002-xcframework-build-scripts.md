# ADR-002: Automated XCFramework Build Scripts

## Status
Accepted

## Context
iOS adapters must support multiple architectures: arm64 for physical devices, x86_64 and arm64 for simulators (Intel and Apple Silicon Macs). Apple's xcframework format is required to bundle multiple architecture slices without conflicts.

## Decision
Each adapter includes or shares a `build_XCFramework.sh` script that:
1. Cleans previous build artifacts
2. Archives for iOS device (arm64) using `xcodebuild archive`
3. Archives for iOS simulator (x86_64, arm64) using `xcodebuild archive`
4. Combines archives using `xcodebuild -create-xcframework`
5. Outputs the final `.xcframework` bundle

Scripts are designed to be run from the adapter directory or project root.

## Consequences
- Reproducible xcframework builds via a single script invocation
- Supports both Intel and Apple Silicon Mac simulators
- Scripts must be updated when Xcode build settings change
- xcframework is the standard Apple multi-architecture distribution format
- Enables binary distribution alongside CocoaPods source distribution
- Build scripts serve as documentation of the build process
