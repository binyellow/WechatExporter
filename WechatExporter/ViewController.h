//
//  ViewController.h
//  WechatExporter
//
//  Created by Matthew on 2020/9/29.
//  Copyright © 2020 Matthew. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController <NSSearchFieldDelegate>

@property (weak) IBOutlet NSTextField *lblITunes;
@property (weak) IBOutlet NSButton *btnExport;
@property (weak) IBOutlet NSButton *btnCancel;
@property (weak) IBOutlet NSButton *btnQuit;

@property (weak) IBOutlet NSTextField *txtboxOutput;
@property (weak) IBOutlet NSPopUpButton *popupBackup;
@property (weak) IBOutlet NSPopUpButton *popupUsers;
@property (weak) IBOutlet NSButton *btnToggleAll;
@property (weak) IBOutlet NSScrollView *sclSessions;
@property (weak) IBOutlet NSTableView *tblSessions;
@property (weak) IBOutlet NSSearchField *searchField;
@property (strong) NSArray *originalDataSource;  // 存储原始数据
@property (strong) NSArray *filteredDataSource;  // 存储过滤后的数据

@property (weak) IBOutlet NSButton *btnBackup;
@property (weak) IBOutlet NSButton *btnOutput;
@property (weak) IBOutlet NSButton *btnShowLogs;
@property (weak) IBOutlet NSButton *btnBackupDevice;

@property (weak) IBOutlet NSProgressIndicator *progressBar;
@property (weak) IBOutlet NSScrollView *sclViewLogs;
@property (unsafe_unretained) IBOutlet NSTextView *txtViewLogs;

- (void)writeLog:(NSString *)log;
- (void)onStart;
- (void)onComplete:(BOOL)cancelled;

- (void)onSessionStart:(NSString *)usrName row:(NSInteger)row;
- (void)onSessionProgress:(NSString *)sessionUsrName row:(NSInteger)row numberOfMessages:(NSUInteger)numberOfMessages numberOfTotalMessages:(NSUInteger)numberOfTotalMessages;
- (void)onSessionComplete:(NSString *)usrName;

@end

