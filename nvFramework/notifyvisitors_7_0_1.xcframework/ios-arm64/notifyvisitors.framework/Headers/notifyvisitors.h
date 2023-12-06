//
//  notifyvisitors.h
//  notifyvisitors
//
//  Created by Notifyvisitors Macbook Air 4 on 25/10/23.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import <UIKit/UIKit.h>

//! Project version number for notifyvisitors.
FOUNDATION_EXPORT double notifyvisitorsVersionNumber;

//! Project version string for notifyvisitors.
FOUNDATION_EXPORT const unsigned char notifyvisitorsVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <notifyvisitors/PublicHeader.h>


typedef NS_ENUM(NSUInteger, nvPushBadgeCount){
    nvPushBadgeCountIncreaseByOne,
    nvPushBadgeCountDecreaseByOne,
    nvPushBadgeCountClearAll
};

typedef void(^NotificationListData)(NSMutableArray*);
typedef void(^nvGetCount)(NSInteger);
typedef void(^nvUnreadCenterCount)(NSDictionary*);

typedef void(^NotificationClickResponseData)(NSMutableDictionary*);
typedef void(^nv_UID)(NSString *);

@protocol notifyvisitorsDelegate <NSObject>

@optional
-(void)NotifyvisitorsGetEventResponseWithUserInfo:(NSDictionary*)userInfo;
-(void)notifyvisitorsEventsResponseCallback:(NSDictionary*)callback;
@end


@interface NVCenterStyleConfig : NSObject

@property (strong, nonatomic)UIColor *unselectedTabTextColor;

@property (strong, nonatomic)UIColor *selectedTabTextColor;

@property (strong, nonatomic)UIColor *selectedTabBgColor;
@property (strong, nonatomic)UIColor *unselectedTabBgColor;

@property (nonatomic)NSInteger selectedTabIndex;
@property (strong, nonatomic)UIFont *tabTextfont;
@property (strong, nonatomic)UIColor *tabBadgeCountBorderColor;
@property (strong, nonatomic)UIColor *tabBadgeCountFillColor;
@property (strong, nonatomic)UIColor *tabBadgeCountTextColor;
@property (nonatomic)BOOL shouldTabBadgeShine;

+(instancetype)sharedInstance;

-(void)setFirstTabWithTabLable:(NSString *)tabLabel TagDisplayName:(NSString *)tabDisplayName;

-(void)setSecondTabWithTabLable:(NSString *)tabLabel TagDisplayName:(NSString *)tabDisplayName;

-(void)setThirdTabWithTabLable:(NSString *)tabLabel TagDisplayName:(NSString *)tabDisplayName;

@end



@interface notifyvisitors : NSObject <UNUserNotificationCenterDelegate>

@property (nonatomic, weak)id <notifyvisitorsDelegate> delegate;

+(instancetype)sharedInstance;

#pragma mark - INITIAL INTEGRATION METHODS

+(void)Initialize:(NSString *)nvMode;

+(void)applicationDidEnterBackground:(UIApplication *)application;
+(void)sceneDidEnterBackground:(UIScene *)scene API_AVAILABLE(ios(13.0));

+(void)applicationWillEnterForeground:(UIApplication *)application;
+(void)sceneWillEnterForeground:(UIScene *)scene API_AVAILABLE(ios(13.0));

+(void)applicationDidBecomeActive:(UIApplication *)application;
+(void)sceneDidBecomeActive:(UIScene *)scene API_AVAILABLE(ios(13.0));

+(void)applicationWillTerminate;

+(void)OpenUrlWithApplication:(UIApplication *)application Url:(NSURL *)url;
+(NSMutableDictionary*)OpenUrlGetDataWithApplication: (UIApplication *)application Url:(NSURL *)url;

+(void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions API_AVAILABLE(ios(13.0));
+(void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts API_AVAILABLE(ios(13.0));

+(void)trackEvents:(NSString *)event_name Attributes:(NSMutableDictionary *)attributes lifetimeValue:(NSString *)ltv Scope:(int)scope;

+(void)UserIdentifier:(NSString *) userID UserParams:(NSMutableDictionary *) UserParams;
+(void)getNvUid:(nv_UID)nvUID;

+(void)Show:(NSMutableDictionary *)UserTokens CustomRule:(NSMutableDictionary *)customRule;
+(void)scrollViewDidScroll:(UIScrollView *) scrollView;
+(void)DismissAllNotifyvisitorsInAppNotifications;
+(void)StopInAppNotifications;
+(void)requestAppleAppStoreInAppReview;


//+(void)didReceiveRemoteNotificationWithUserInfofor_iOS7orBelow:(NSDictionary *)userInfo;

+(void)RegisterPushWithDelegate:(id)delegate App:(UIApplication *)application launchOptions:(NSDictionary *)launchOptions;
+(void)DidRegisteredNotification:(UIApplication *)application deviceToken:(NSData *)deviceToken;
+(NSString *)getPushRegistrationToken;

+(void)schedulePushNotificationwithNotificationID:(NSString *)NID Tag:(NSString *)tag TimeinSecond:(NSString *)time Title:(NSString *)title  Message:(NSString *)message URL:(NSString *)url  Icon:(NSString *)icon;

+(void)pushPreferences:(NSArray *)preferenceList isUnsubscribeFromAll:(BOOL)shouldUnsubscribe;

+(void)updatePushBadgeNumberWithValue:(nvPushBadgeCount)nvPushBadgeNumber;

+(void)didReceiveRemoteNotificationWithUserInfo:(NSDictionary *)userInfo;
+(NSMutableDictionary *)PushNotificationActionDataFromUserInfo:(NSDictionary *)userinfo;
+(void)didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void(^)(UIBackgroundFetchResult))completionHandler;

+(void)willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler API_AVAILABLE(ios(10.0));

+(void)didReceiveNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10.0));
+(void)PushNotificationActionDataFromResponse:(UNNotificationResponse *)response AutoRedirectOtherApps:(BOOL)autoRedirect clickResponseData:(NotificationClickResponseData)pushClickResponse API_AVAILABLE(ios(10.0));


+(void)NotifyVisitorsNotificationCentre DEPRECATED_MSG_ATTRIBUTE("first deprecated in Notifyvisitors iOS SDK 6.4.3 Use [notifyvisitors notificationCenter:] (see notifyvisitors.h)");

+(void)notificationCenter;
+(void)notificationCenterWithConfiguration:(NVCenterStyleConfig *)configuration;
+(void)GetNotificationCentreData:(NotificationListData) notificationDataList;

+(void)GetUnreadPushNotification:(nvGetCount)nvUnreadCount;
+(void)getNotificationCenterCountWithConfiguration:(NVCenterStyleConfig *)configuration countResult:(nvUnreadCenterCount)unreadCenterCounts;

+(void)stopGeofencePushforDateTime:(NSString *)nvDateTime additionalHours: (NSInteger)nvtimeinHours;

//+(void)startChatBotWithScreenName:(NSString *)nvBotScreenName;

+(void)LoadAttachmentWithRequest:(UNNotificationRequest *)request bestAttemptContent:(UNMutableNotificationContent *)bestAttemptContent withContentHandler:(nullable void (^)(UNNotificationContent * _Nonnull))contentHandler API_AVAILABLE(ios(10.0));

@end
