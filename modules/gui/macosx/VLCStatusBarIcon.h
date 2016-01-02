/*****************************************************************************
 * VLCStatusBarIcon.h: Mac OS X module for vlc
 *****************************************************************************
 * Copyright (C) 2001-2016 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Goran Dokic <vlc at 8hz dot com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <cocoa/cocoa.h>


@interface VLCStatusBarIcon : NSObject <NSMenuDelegate>
{
    NSMenuItem *_vlcStatusBarMenuItem;

    NSString *_nameToDisplay;
    NSString *_timeToDisplay;
    NSString *_durationToDisplay;
    NSString *_urlToDisplay;
    NSImage *_menuImagePlay;
    NSImage *_menuImagePause;
    NSImage *_menuImageStop;
}

@property NSStatusItem *statusItem;
@property NSTimer *dataRefreshUpdateTimer;
@property (readwrite, strong) IBOutlet NSMenu *vlcStatusBarIconMenu;

// get data from VLC and update the little status menu
- (void) updateMenuItemRandom;
- (void) updateMenuItemPlayPause;
- (void) setDataUpdateTimer:(float) interval;

- (IBAction) updateMenuItemContent:(id)sender;
- (IBAction) restoreMainWindow:(id)sender;
- (IBAction) statusBarIconTogglePlayPause:(id)sender;
- (IBAction) statusBarIconStop:(id)sender;
- (IBAction) statusBarIconNext:(id)sender;
- (IBAction) statusBarIconPrevious:(id)sender;
- (IBAction) statusBarIconToggleRandom:(id)sender;

@end
