//
//  ISFacebookConstants.h
//  ISFacebookAdapter
//
//  Copyright © 2024 ironSource. All rights reserved.
//

// Mediation keys
static NSString * const kMediationName              = @"IronSource";

// Network keys
static NSString * const kAdapterName                = @"Facebook";
static NSString * const kPlacementId                = @"placementId";
static NSString * const kAllPlacementIds            = @"placementIds";

// Meta data keys
static NSString * const kMetaDataMixAudienceKey     = @"meta_mixed_audience";

// Meta error codes
static NSInteger kMetaNoFillErrorCode               = 1001;

// init state possible values
typedef NS_ENUM(NSInteger, InitState) {
    INIT_STATE_NONE,
    INIT_STATE_IN_PROGRESS,
    INIT_STATE_SUCCESS,
    INIT_STATE_FAILED
};

