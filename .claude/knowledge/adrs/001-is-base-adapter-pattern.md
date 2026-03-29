# ADR-001: ISBaseAdapter Inheritance Pattern

## Status
Accepted

## Context
Unity LevelPlay (ironSource) mediates ads from 11 network SDKs on iOS. Each adapter must handle SDK initialization, ad format support declaration, and lifecycle management. A consistent base provides shared functionality.

## Decision
All network adapters extend `ISBaseAdapter` provided by the ironSource SDK:
- `ISBaseAdapter` provides shared initialization, configuration, and format registration
- Each adapter class (`IS{Network}Adapter`) overrides methods for supported ad formats
- Adapter declares supported formats (Banner, Interstitial, Rewarded Video) via base class methods
- Format-specific behavior is delegated to dedicated delegate classes

## Consequences
- Consistent adapter structure across all 11 networks
- ISBaseAdapter handles common mediation plumbing
- Adapters focus on network-specific SDK integration
- Base class updates from ironSource SDK affect all adapters
- Adapter must conform to base class lifecycle contract
- Adding native ads requires base class support (currently Google-only)
