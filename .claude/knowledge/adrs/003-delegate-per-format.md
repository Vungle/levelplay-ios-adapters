# ADR-003: Format-Specific Delegate Classes

## Status
Accepted

## Context
Each ad format (Banner, Interstitial, Rewarded Video) has its own set of delegate callbacks from the network SDK. Implementing all delegates in the main adapter class would create large, complex files. Different formats have different lifecycle events (e.g., rewarded has reward callback, banner has resize).

## Decision
Each ad format has a dedicated delegate class:
- `IS{Network}BannerDelegate` — handles banner load, display, click, resize
- `IS{Network}InterstitialDelegate` — handles interstitial load, show, close, click
- `IS{Network}RewardedVideoDelegate` — handles rewarded load, show, close, click, reward

The main adapter class (`IS{Network}Adapter`) instantiates and coordinates delegates. A constants header (`IS{Network}Constants.h`) defines shared values.

## Consequences
- Each delegate class has focused, single-format responsibility
- Main adapter class stays manageable as an orchestrator
- Easier to add new format support by adding a new delegate class
- Constants shared across delegates are centralized
- More files per adapter (adapter + 3 delegates + constants = 5 files minimum)
- Delegates must communicate with the adapter for shared state (e.g., init status)
