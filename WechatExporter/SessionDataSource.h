//
//  SessionDataSource.h
//  WechatExporter
//
//  Created by Matthew on 2021/2/1.
//  Copyright © 2021 Matthew. All rights reserved.
//

#ifndef SessionDataSource_h
#define SessionDataSource_h

#import <Cocoa/Cocoa.h>
#include <vector>
#include <set>
#include <utility>

#import "WechatObjects.h"

@interface SessionItem : NSObject

@property (assign) NSInteger orgIndex;
@property (assign) NSInteger userIndex;
@property (assign) BOOL checked;
@property (strong) NSString *sessionUsrName;
@property (strong) NSString *displayName;
@property (assign) NSInteger recordCount;
@property (strong) NSString *userDisplayName;
@property (strong) NSString *usrName;
@property (strong) NSString *lastMessage;
#ifndef NDEBUG
@property (assign) NSUInteger lastMessageTime;
#endif
// @property (assign) NSInteger userPointer;
// @property (assign) NSInteger sessionPointer;

// - (NSComparisonResult)orgIndexCompare:(SessionItem *)sessionItem:(BOOL)ascending;
- (NSComparisonResult)displayNameCompare:(SessionItem *)sessionItem ascending:(BOOL)ascending;
- (NSComparisonResult)recordCountCompare:(SessionItem *)sessionItem ascending:(BOOL)ascending;
- (NSComparisonResult)userIndexCompare:(SessionItem *)sessionItem ascending:(BOOL)ascending;


@end

@interface SessionDataSource : NSObject<NSTableViewDataSource>

@property (nonatomic, assign) NSInteger rowInProgress;
@property (nonatomic, assign) NSUInteger numberOfMsgExported;
@property (nonatomic, strong) NSArray *originalItems;
@property (nonatomic, strong) NSArray *filteredItems;
@property (nonatomic, copy) NSString *searchText;

- (void)loadData:(const std::vector<std::pair<Friend, std::vector<Session>>> *)usersAndSessions withAllUsers:(BOOL)allUsers indexOfSelectedUser:(NSInteger)indexOfSelectedUser includesSubscription:(BOOL)includesSubscriptions;
- (void)filterContentForSearchText:(NSString *)searchText;
- (void)getSelectedUserAndSessions:(std::map<std::string, std::map<std::string, void *>>&)usersAndSessions;

- (void)bindCellView:(NSTableCellView *)cellView atRow:(NSInteger)row andColumnId:(NSString *)identifier;
- (NSControlStateValue)updateCheckStateAtRow:(NSInteger)row;
- (void)checkAllSessions:(BOOL)checked;

@end

#endif /* SessionDataSource_h */
