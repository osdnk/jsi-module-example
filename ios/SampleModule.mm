//
//  SampleModule.m
//  newfeatures
//
//  Created by Michał Osadnik on 07/10/2021.
//


#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <ReactCommon/RCTTurboModuleManager.h>
#import <jsi/jsi.h>
#import <React/RCTView.h>
#import <memory>
#import <React/RCTBridgeModule.h>
#import "module.h"

@interface SampleModule : NSObject <RCTBridgeModule>

@end

using namespace facebook;

@implementation SampleModule
@synthesize bridge = _bridge;
RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

- (void)setBridge:(RCTBridge *)bridge
{
  _bridge = bridge;
  
  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
  if (!cxxBridge.runtime) {
    return;
  }
  
  auto callInvoker = bridge.jsCallInvoker;
  

  osdnk::samplemodule::installNative(*(jsi::Runtime *)cxxBridge.runtime);
}

@end

